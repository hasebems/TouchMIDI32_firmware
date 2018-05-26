/* ========================================
 *
 *	tm32_basicapp.c
 *		description: TouchMidi32 Default application
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include "tm32_lib.h"
#include "tm32_i2cdev.h"
#include "tm32_analyse_pressure.h"
#include "tm32_analyse_touch.h"


//---------------------------------------------------------
//			Macros
//---------------------------------------------------------
#define		MAX_TOUCH_PADS		32
#define		MAX_KEYBOARD_PADS	25

//	for doremi
#define		NO_NOTE				12
#define		WARNING				(NO_NOTE+1)

//	for TOUCH_EVENT_TABLE
enum SW_TYPE {
	KBD_SW,
	PCN_SW,
	OCT_SW,
	VEL_SW,
	EFF_SW		//	3rd byte on:7f, off:00
};

/*----------------------------------------------------------------------------*/
//
//      Variables
//
/*----------------------------------------------------------------------------*/
static uint8_t		midiExp;
static uint8_t		doremi;
static uint8_t		crntNote;

static uint8_t		lastMod;
static uint8_t		lastPrt;

static bool         nowPlaying;
static bool			event10msec;
static bool			event4msec;

static uint8_t		ledPwmCounter;
static uint32_t		counter10msec;
static uint32_t		systemTimerStkFor10msec;
static uint32_t		systemTimerStkFor4msec;

static uint8_t		touchCurrentStatus;
static int			debugCounter;

static uint16		prsValue;
static uint16		tempPrsValue;

/*----------------------------------------------------------------------------*/
 //
 //      Full Color LED by Interrupt
 //
 /*----------------------------------------------------------------------------*/
//	PWM : Total 256count
//	this interrupt is 250usec periodic.
//	PWM interval : 16msec
#define		PWM_INCREMENT_VALUE_PER_ONE_INT		4	//(256/(16000/250))
const uint8_t tColorTable[13][3] = {

 	//	this Value(0x00-0x20) * midiExp(0-127) / 16 = 0x00-0xfe : PWM count value
 	// R	 G		B
 	{ 0x20,  0x00,  0x00  },   //  red		C
 	{ 0x1a,  0x06,  0x00  },   //  red		C#
 	{ 0x16,  0x0a,  0x00  },   //  orange	D
 	{ 0x14,  0x0c,  0x00  },   //  orange	D#
 	{ 0x0c,  0x14,  0x00  },   //  yellow	E
 	{ 0x00,  0x20,  0x00  },   //  green	F
 	{ 0x00,  0x10,  0x10  },   //  green	F#
 	{ 0x00,  0x00,  0x20  },   //  blue		G
 	{ 0x04,  0x00,  0x1c  },   //  blue		G#
 	{ 0x08,  0x00,  0x18  },   //  violet	A
 	{ 0x0c,  0x00,  0x14  },   //  violet	A#
 	{ 0x18,  0x00,  0x08  },   //  violet	B
 	{ 0x00,  0x00,  0x00  },   //  none
 };
 //-------------------------------------------------------------------------
void tm32_intrpt(void)
{
	//	display warning
	if ( doremi == WARNING ){
		tm32_p6_1_Lo();
		if ( tm32_systemTimer & 0x0200 ){	//	500msec
			return;
		}
	}

	ledPwmCounter+=PWM_INCREMENT_VALUE_PER_ONE_INT;	
	
    //	PWM Full Color LED
    uint8_t ledCnt;
	//Red
    ledCnt = (tColorTable[doremi][0]*midiExp)>>4;
    if (ledPwmCounter >= ledCnt){tm32_p6_1_Hi();}
	else						{tm32_p6_1_Lo();}
	//Green
    ledCnt = (tColorTable[doremi][1]*midiExp)>>4;
    if (ledPwmCounter >= ledCnt){tm32_p6_2_Hi();}
	else						{tm32_p6_2_Lo();}
	//Blue
    ledCnt = (tColorTable[doremi][2]*midiExp)>>4;
    if (ledPwmCounter >= ledCnt){tm32_p6_3_Hi();}
	else						{tm32_p6_3_Lo();}
}

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_init( void )
{
	tm32_init_i2cDevice();
	debugCounter = 0;

	//	Mode Check
	tm32_p6_1_Lo();
	tm32_p6_2_Lo();
	tm32_p6_3_Lo();
	tm32_p6_4_Lo();

	
	midiExp = 0;
    doremi = NO_NOTE;
	crntNote = 96;
	lastMod = 0;
	lastPrt = 0;
	nowPlaying = false;
	event10msec = false;
	systemTimerStkFor10msec = tm32_systemTimer+40;
	systemTimerStkFor4msec = tm32_systemTimer+16;
	counter10msec = 0;
	ledPwmCounter = 0;

	touchCurrentStatus = 0;
	tempPrsValue = 0;
	prsValue = -1000;	//	different number from tempPrsValue
	
    //  H/W init
    tm32_p6_1_Lo();	//R
	tm32_p6_2_Lo();	//G
	tm32_p6_3_Lo();	//B

    AnalysePressure_Init();
    AnalyseTouch_init();
}
/*----------------------------------------------------------------------------*/
//
//      Touch Sensor
//
/*----------------------------------------------------------------------------*/
static void setMidiBuffer( uint8 statusByte, uint8 secondByte, uint8 thirdByte )
{
	uint8 midiMsg[3];
	midiMsg[0] = statusByte;
	midiMsg[1] = secondByte;
	midiMsg[2] = thirdByte;
	tm32_usbMidiOut( 3, midiMsg );
}
/*----------------------------------------------------------------------------*/
static void touchSensor( void )
{
	AnalyseTouch_setNewTouch(touchCurrentStatus);
	if ( event10msec ){
		uint8_t mdNote;
		if ( AnalyseTouch_catchEventOfPeriodic(&mdNote, counter10msec) == true ){
			if ( nowPlaying == true ){
				setMidiBuffer(0x90,mdNote,0x7f);
				setMidiBuffer(0x90,crntNote,0x00);
				if ( doremi < WARNING ){
					doremi = mdNote%12;
				}
			}
			else {
				setMidiBuffer(0xa0,mdNote,0x01);
				setMidiBuffer(0xa0,crntNote,0x00);
			}
	        crntNote = mdNote;
		}
	}
}
/*----------------------------------------------------------------------------*/
//
//      Pressure Sensor
//
/*----------------------------------------------------------------------------*/
static void pressureSensor( void )
{
	uint16 prs = lps25h_getPressure();

	tempPrsValue = prs;		
 	if ( tempPrsValue != prsValue ){
//		int dispValue = tempPrsValue - 10000;
//		ada88_writeNumber(dispValue);
		prsValue = tempPrsValue;
	}	
	
	
	AnalysePressure_setNewRawPressure(prs);
	if ( event4msec == true ){
		if ( AnalysePressure_catchEventOfPeriodic(&midiExp) == true ){
			setMidiBuffer(0xb0,0x0b,midiExp);
			if (( midiExp > 0 ) && ( nowPlaying == false )){
	            setMidiBuffer(0x90,crntNote,0x7f);
		        nowPlaying = true;
				if ( doremi < WARNING ){
					doremi = crntNote%12;
				}
			}
		    if (( midiExp == 0 ) && ( nowPlaying == true )){
			    setMidiBuffer(0x90,crntNote,0);
				nowPlaying = false;
				if ( doremi < WARNING ){
					doremi = NO_NOTE;
				}
			}
		}
    }

//	if ( doremi != NO_NOTE ){
//		int letter = doremi+3;
//		if (letter > 7){ letter-=7;}
//		ada88_write(letter);
//	}
//	else {
//		ada88_write(19);
//	}
	ada88_writeNumber(midiExp);
}
/*----------------------------------------------------------------------------*/
//
//      Accelerator Sensor
//
/*----------------------------------------------------------------------------*/
//-------------------------------------------------------------------------
#define		MAX_ANGLE		32
const uint8_t tCnvModDpt[MAX_ANGLE] = {
	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	1,	1,	2,	2,
	3,	4,	5,	6,	7,	8,	9,	10,
	12,	14,	16,	19,	22,	25,	28,	31,
};
//-------------------------------------------------------------------------
const uint8_t tCnvPrtDpt[MAX_ANGLE] = {
	0,	0,	0,	0,	0,	0,	0,	0,
	10,	20,	30,	40,	50,	60,	70,	70,
	80,	80,	80,	80,	90,	90,	90,	90,
	100,100,100,100,110,110,110,110,
};
//-------------------------------------------------------------------------
static void acceleratorSensor( void )
{
	signed short acl[3] = { 0,0,0 };
	int incli;

	adxl345_getAccel(0,acl);
	if ( acl[0] < 0 ){ acl[0] = acl[0] * (-1);}
	incli = (MAX_ANGLE-1) - acl[0]/512;	// 0-31

	uint8_t modVal, prtVal;
	if ( acl[2] < 0 ){	// Upward
		modVal = 0;
		prtVal = incli;
		if ( prtVal >= MAX_ANGLE ){
	        prtVal = MAX_ANGLE-1;
		}
	}
	else {	// Downward
		prtVal = 0;
		modVal = incli;
		if ( modVal >= MAX_ANGLE ){
	        modVal = MAX_ANGLE-1;
	    }
	}

	//	lessen variation of modulation
	modVal = tCnvModDpt[modVal];
	if ( modVal > lastMod ){
		lastMod++;
		setMidiBuffer(0xb0,0x01,lastMod);
	}
	else if ( modVal < lastMod ){
		lastMod--;
		setMidiBuffer(0xb0,0x01,lastMod);
	}

	prtVal = tCnvPrtDpt[prtVal];
	if ( prtVal != lastPrt ){
		lastPrt = prtVal;
		setMidiBuffer(0xb0,0x05,lastPrt);
	}
}
//---------------------------------------------------------
//			Loop
//---------------------------------------------------------
void tm32_loop( void )
{
	//	Generate Time Event
	if ( systemTimerStkFor10msec < tm32_systemTimer ){
		event10msec = true;
		systemTimerStkFor10msec += 40;
		counter10msec++;
	}
	else {
		event10msec = false;
	}
	if ( systemTimerStkFor4msec < tm32_systemTimer ){
		event4msec = true;
		systemTimerStkFor4msec += 16;
	}
	else {
		event4msec = false;
	}

	//  Touch Sensor
    touchSensor();

    //	Air Pressure Sensor
    pressureSensor();

    //  accelerator sensor
	acceleratorSensor();

	//	display warning
	if ( tm32_i2cErrCode != 0 ){
		doremi = WARNING;
	}
}
//---------------------------------------------------------
//			Touch On
//---------------------------------------------------------
void tm32_touchOn( int number )
{
	touchCurrentStatus |= (0x01<<number);

}
//---------------------------------------------------------
//			Touch Off
//---------------------------------------------------------
void tm32_touchOff( int number )
{
	touchCurrentStatus &= ~(0x01<<number);

}
/* [] END OF FILE */
