/* ========================================
 *
 *	tm32_hcb4.c
 *		description: HCB4 ( HoneycombBell Version 4 )
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include <stdbool.h>
#include <stdint.h>

#include "tm32_lib.h"
#include "tm32_i2cdev.h"
#include "tm32_hcb4_dle.h"

//---------------------------------------------------------
//			Macros
//---------------------------------------------------------
#define		MAX_BEAT		8
#define		MAX_CELL		12
#define		MAX_BEAT_LIGHTING_PERIOD	20
#define		MAX_CONNECTION_PTN			15
#define		MAX_ID						6
//---------------------------------------------------------
//	for TOUCH_EVENT_TABLE
enum SW_TYPE {
	KBD_SW,
	PCN_SW,
	OCT_SW,
	VEL_SW,
	EFF_SW		//	3rd byte on:7f, off:00
};
//---------------------------------------------------------
//			Variables
//---------------------------------------------------------
//	HCB config & state
static bool			hcbActive;
static uint8_t		hcbBlockID;
static uint8_t		hcbBlockConnectionPattern;	//	0 - 14
static uint8_t		hcbCrntBeat;
static uint8_t		hcbNextBeat;
static uint8_t		hcbCounterPerBeat;

//	Light Pattern
static bool			hcbLightPatternRcvMode;
static uint8_t		hcbLightPatternRcvModeCounter;
static uint8_t		hcbLightPatternRcvTime;
static uint16_t		hcbLightPattern[MAX_BEAT];

//	managing LED
static uint16_t 	colorArray[MAX_CELL][VOLUME_ARRAY_MAX];
static bool			colorArrayEvent[MAX_CELL];
static bool			beatOn;

//	time event
static bool			event10msec;
static bool			event4msec;

//	counter
static uint32_t		counter10msec;
static uint32_t		systemTimerStkFor10msec;
static uint32_t		systemTimerStkFor4msec;

static uint32_t		touchCurrentStatus;
static uint8_t		keyOnCounter[MAX_CELL];	//	(0 - 3)  0-2:keyon counter, 3:keyon at the same time
static uint32_t		keyOnTimeStock[MAX_CELL];
static int			debugCounter;

static DLE 			dle[DOREMI_MAX];

//---------------------------------------------------------
//			Table
//---------------------------------------------------------

//---------------------------------------------------------
static const int8_t tOctave[MAX_CONNECTION_PTN][MAX_ID+1] = {
// ID   0	1   2   3   4   5   6
	{	0,	0,	0,	0,	0,	0,	0	},	//	not work
	{	0,	0,	0,	0,	0,	0,	0	},	//	1
	{	0,	12,	0,	0,	0,	0,	0	},	//	2 left-right
	{	0,	0,	0,	0,	0,	0,	0	},	//	2 upper-lower
	{	0,	12,	0,	-12,0,	0,	0	},	//	3 left-right
	{	0,	0,	0,	0,	0,	0,	0	},	//	3 upper-lower
	{	0,	24,	12,	0,	-12,0,	0	},	//	4 left-right
	{	0,	0,	0,	0,	0,	0,	0	},	//	4 upper-lower
	{	0,	12,	12,	0,	0,	0,	0	},	//	4 2*2
	{	0,	24,	12,	0,	-12,-24,0	},	//	5 left-right
	{	0,	0,	0,	0,	0,	0,	0	},	//	5 upper-lower
	{	0,	36,	24,	12,	0,	-12,-24	},	//	6 left-right
	{	0,	0,	0,	0,	0,	0,	0	},	//	6 upper-lower
	{	0,	12,	12,	0,	0,	-12,-12	},	//	6 2*3
	{	0,	12,	12,	12,	0,	0,	0	}	//	6 3*2
};
//---------------------------------------------------------
static const int8_t tMaxBlock[MAX_CONNECTION_PTN] = 
{
	0,	1,	2,	2,	3,	3,	4,	4,	4,	5,	5,	6,	6,	6,	6
};
//---------------------------------------------------------
//			Interrupt
//---------------------------------------------------------
void tm32_intrpt(void){}

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_init( void )
{
	int i;
	
	tm32_init_i2cDevice();
	PCA9685_init(0);
	PCA9685_init(1);
	PCA9685_init(2);

	debugCounter = 0;

	hcbActive = false;
	hcbBlockID = 0;
	hcbBlockConnectionPattern = 0x01;
	hcbCrntBeat = 0xff;
	hcbNextBeat = 0xff;
	hcbCounterPerBeat = 0;
	
	hcbLightPatternRcvMode = false;
	hcbLightPatternRcvModeCounter = 0;
	hcbLightPatternRcvTime = 0;
	beatOn = false;

	hcbLightPattern[0] = 0b0000000000000111;
	hcbLightPattern[1] = 0b0000000000111000;
	hcbLightPattern[2] = 0b0000000111000000;
	hcbLightPattern[3] = 0b0000111000000000;
	hcbLightPattern[4] = 0b0000000000000111;
	hcbLightPattern[5] = 0b0000000000111000;
	hcbLightPattern[6] = 0b0000000111000000;
	hcbLightPattern[7] = 0b0000111000000000;
	
	for ( i=0; i<DOREMI_MAX; i++ ){
		DLE_init(&dle[i]);
	}
	
	event10msec = false;
	systemTimerStkFor10msec = tm32_systemTimer+40;
	systemTimerStkFor4msec = tm32_systemTimer+16;
	counter10msec = 0;
	touchCurrentStatus = 0;
	
	for ( i=0; i<MAX_CELL; i++ ){
		keyOnCounter[i] = 0;
		keyOnTimeStock[i] = 0;
	}
	
    //  H/W init
	tm32_p6_1_Hi();	//	
	tm32_p6_2_Lo();	//	OE enable

	tm32_p6_3_Lo();
	tm32_p6_4_Lo();
}
//---------------------------------------------------------
//			Set MIDI Buffer
//---------------------------------------------------------
static void setMidiBuffer( uint8 statusByte, uint8 secondByte, uint8 thirdByte )
{
	uint8	midiMsg[3];
	uint8	midiStatus = statusByte & 0xf0;
	midiMsg[0] = statusByte;
	midiMsg[1] = secondByte;
	midiMsg[2] = thirdByte;
	
	if (( 0x90 == midiStatus ) || ( 0xa0 == midiStatus )){
		tm32_usbMidiOut( 3, midiMsg );
	}
	tm32_uartMidiOut( 3, midiMsg );
}
//---------------------------------------------------------
//			Loop
//---------------------------------------------------------
void generateTimeEvent( void )
{
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
}
//---------------------------------------------------------
void makeLedDisplayBeats( uint8_t cell, uint16_t brightness ) 
{
	int j;
	for ( j=0; j<VOLUME_ARRAY_MAX; j++ ){
		colorArray[cell][j] = brightness;// / (((hcbCrntBeat&0x01)*4)+1);
	}
	colorArrayEvent[cell] = true;
}
//---------------------------------------------------------
void lighteningLed( void )
{
	int		i;
	bool	beatOff = false;

	//	Periodic Job & Make Time Event
	if ( event10msec ){
		hcbCounterPerBeat++;
		if ( MAX_BEAT_LIGHTING_PERIOD == hcbCounterPerBeat ){
			//	beat light off event
			beatOff = true;
		}
		for ( i=0; i<DOREMI_MAX; i++ ){
			if ( DLE_count(&dle[i]) == true ){
				colorArrayEvent[i] = true;
			}
		}
	}	
	
	//	Check DLE Segment & Make Beat Event
	uint16_t lightPtn = 0;
	uint16_t unlightPtn = 0;
	if ( true == beatOn ){
		lightPtn = hcbLightPattern[hcbNextBeat];
	}
	if (( true == beatOn ) || ( true == beatOff )){
		if ( 0xff != hcbCrntBeat ){
			unlightPtn = hcbLightPattern[hcbCrntBeat];
		}
	}
	if ( lightPtn | unlightPtn ){
		uint16_t bitPtn = 0x0001;
		for ( i=0; i<MAX_CELL; i++ ){
			if ( SEG_NOT_USE == DLE_getSegment(&dle[i]) ){
				if ( unlightPtn & bitPtn ){
					//	turn off
					makeLedDisplayBeats(i,0);
				}
				if ( lightPtn & bitPtn ){
					if ( true == hcbActive ){
						//	Light Beat
						makeLedDisplayBeats(i,2000);
					}
				}
			}
			bitPtn <<= 1;
		}
	}

	//	Lightening Full Color LED
	for ( i=0; i<MAX_CELL; i++ ){
		if ( colorArrayEvent[i] == true ){
			tm32_i2cErrCode |= PCA9685_setFullColorLED( 2-i%3, i/3, (unsigned short*)colorArray[i] );
			colorArrayEvent[i] = false;
		}
	}

	beatOn = false;
	hcbCrntBeat = hcbNextBeat;
}
//---------------------------------------------------------
void tm32_loop( void )
{
	//	Generate Time Event
	generateTimeEvent();

	//	Counter Job
	if ( event10msec ){
		hcbLightPatternRcvTime++;
		if ( hcbLightPatternRcvTime > 10 ){
			hcbLightPatternRcvMode = false;
		}
	}

	// Full Color LED lighting
	lighteningLed();
	
	//	display warning
	if ( tm32_i2cErrCode != 0 ){
		//	Warning
		if ( counter10msec & 0x20 ){ tm32_p6_4_Lo(); }
		else { tm32_p6_4_Hi(); }
	}
	else {
		//	Normal
		//tm32_p6_4_Hi();
	}
}
//---------------------------------------------------------
//			HCB No Active
//---------------------------------------------------------
void setHcbNoActive( void )
{
	int i;
	uint16_t bitPtn = 0x0001;
	hcbActive = false;
	for ( i=0; i<MAX_CELL; i++ ){
		if ( touchCurrentStatus & bitPtn ){
			//	All Key Off
			setMidiBuffer( 0x90, 0x3c+i+tOctave[hcbBlockConnectionPattern][hcbBlockID], 0x00 );
		}
		bitPtn <<= 1;
	}
}
//---------------------------------------------------------
//			Receive UART MIDI
//---------------------------------------------------------
void getBeat( uint8_t id, uint8_t beat )
{
	uint8_t	myId = (id & 0x0f) + 1;
	hcbNextBeat = beat;
	hcbCounterPerBeat = 0; // counter clear
	beatOn = true;
	
	uint8_t maxId = tMaxBlock[hcbBlockConnectionPattern];
	if ( myId > maxId ){
		setHcbNoActive();
	}
	else {
		hcbActive = true;
		hcbBlockID = myId;
	}
	
	//	Send Beat
	setMidiBuffer( 0xb0 | hcbBlockID, 0x53, beat );

	//	Check Beat (debug)
	if ( beat & 0x01 ){ tm32_p6_3_Hi();}
	else { tm32_p6_3_Lo(); }
}
//---------------------------------------------------------
void getLightPattern( uint16_t ptn )
{
	if ( hcbLightPatternRcvMode == true ){
		hcbLightPatternRcvModeCounter++;
		if ( MAX_BEAT <= hcbLightPatternRcvModeCounter ){
			//	over beat
			hcbLightPatternRcvMode = false;
		}
		else {
			//	set Light Pattern
			hcbLightPattern[hcbLightPatternRcvModeCounter] = ptn;
			hcbLightPatternRcvTime = 0;
		}
	}
	else {
		//	set Light Pattern ( beat == 0 )
		hcbLightPatternRcvMode = true;
		hcbLightPatternRcvModeCounter = 0;
		hcbLightPatternRcvTime = 0;
		hcbLightPattern[0] = ptn;
	}
}
//---------------------------------------------------------
void tm32_rcvUart( int count, uint8_t* buf )
{
	if ( 3 == count ){
		switch ( *buf & 0xf0 ){
			case 0x90:	//	fall through
			case 0xa0:{
				setMidiBuffer( *buf, *(buf+1), *(buf+2) );
				break;	
			}
			case 0xb0:{
				if ( 0x52 == *(buf+1) ){
					//	block connection pattern
					setHcbNoActive();
					setMidiBuffer( 0xb0, 0x52, *(buf+2) );
					hcbBlockConnectionPattern = *(buf+2);
				}
				else if ( 0x53 == *(buf+1) ){
					//	beat signal
					getBeat( *buf, *(buf+2));
				}
				break;
			}
			case 0xe0:{
				if ( (*buf & 0x0f) == hcbBlockID ){
					uint16 ptn = ((uint16)*(buf+2))<<6;
					ptn |= (uint16)*(buf+1);
					getLightPattern( ptn );
				}
				else {
					setMidiBuffer( *buf, *(buf+1), *(buf+2) );
				}
				break;
			}
			default: break;
		}
	}
}
//---------------------------------------------------------
//			Touch On
//---------------------------------------------------------
static const int tNode2Note[32] =
{	2,2,5,5,8,8,11,11,1,1,4,4,7,7,10,10,-1,-1,-1,-1,-1,-1,-1,-1,9,9,6,6,3,3,0,0	};
//---------------------------------------------------------
void setKeyOn( uint8_t note )
{
	DLE_on( &dle[note], &colorArray[note][0], note );
	colorArrayEvent[note] = true;
	setMidiBuffer( 0x90, 0x3c+note+tOctave[hcbBlockConnectionPattern][hcbBlockID], 0x7f );

	keyOnTimeStock[note] = counter10msec;
	if ( keyOnCounter[note] < 2 ){ keyOnCounter[note]++;}
}
//---------------------------------------------------------
void tm32_touchOn( int number )
{
	int	note;
	uint32_t	swEvent = 0x0001<<number;	
	if (!( touchCurrentStatus & swEvent )){
		if ( hcbActive == true ){
			note = tNode2Note[number];
			if (( note >= 12 ) || ( note < 0 )){ return; }
			
			if ( keyOnCounter[note] == 0 ){ setKeyOn(note);}
			else if ( keyOnCounter[note] == 1 ){
				if ( keyOnTimeStock[note]+5 < counter10msec ){ setKeyOn(note);}
				else { keyOnCounter[note] = 3; }
			}
		}
	}
	touchCurrentStatus |= (0x01<<number);
}
//---------------------------------------------------------
//			Touch Off
//---------------------------------------------------------
void tm32_touchOff( int number )
{
	uint32_t	swEvent = 0x0001<<number;
	if ( touchCurrentStatus & swEvent ){
		int note = tNode2Note[number];
		if (( note >= 12 ) || ( note < 0 )){ return; }
		
		if ( keyOnCounter[note] == 3 ){
			keyOnCounter[note] = 1;
		}
		else if ( keyOnCounter[note] != 0 ){
			DLE_off( &dle[note] );
			setMidiBuffer( 0x90, 0x3c+note+tOctave[hcbBlockConnectionPattern][hcbBlockID], 0x00 );
			keyOnCounter[note]--;
		}
	}
	touchCurrentStatus &= ~(0x01<<number);
}
/* [] END OF FILE */
