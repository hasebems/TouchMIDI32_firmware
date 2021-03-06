/* ========================================
 *
 *	tm32_fab13app.c
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

//---------------------------------------------------------
//			Macros
//---------------------------------------------------------
#define		MAX_TOUCH_PADS		32
#define		MAX_KEYBOARD_PADS	25

//	for TOUCH_EVENT_TABLE
enum SW_TYPE {
	KBD_SW,
	PCN_SW,
	OCT_SW,
	VEL_SW,
	EFF_SW		//	3rd byte on:7f, off:00
};

//---------------------------------------------------------
static void MIDIOutIndicator( void );


//---------------------------------------------------------
//			Variables
//---------------------------------------------------------
static uint8	heartbeat;
static uint32_t	sentSignalTime;

static uint8	mode;
static uint8	noteNumberStock[MAX_TOUCH_PADS];
static uint8	offsetVelocity;
static int8		offsetOctave;
static uint8	pcNumber;

static int		debugCounter;

static bool			event4msec;
static uint32_t		systemTimerStkFor4msec;

static uint8_t		midiExp;
static uint16		prsValue;
static uint16		tempPrsValue;

//static const uint8 TOUCH_EVENT_TABLE[2][MAX_TOUCH_PADS][2];
//static const uint8 VELCITY_TABLE[5];
//---------------------------------------------------------
//			Tables
//---------------------------------------------------------
static const uint8 TOUCH_EVENT_TABLE[2][MAX_TOUCH_PADS][2] = {
{	//	naked Mode
	{ KBD_SW, 0x3c }, { KBD_SW, 0x3d }, { KBD_SW, 0x3e }, { KBD_SW, 0x3f },
	{ KBD_SW, 0x40 }, { KBD_SW, 0x41 }, { KBD_SW, 0x42 }, { KBD_SW, 0x43 },
	
	{ KBD_SW, 0x44 }, { KBD_SW, 0x45 }, { KBD_SW, 0x46 }, { KBD_SW, 0x47 },
	{ KBD_SW, 0x48 }, { KBD_SW, 0x49 }, { KBD_SW, 0x4a }, { KBD_SW, 0x4b },
	
	{ KBD_SW, 0x4c }, { KBD_SW, 0x4d }, { KBD_SW, 0x4e }, { KBD_SW, 0x4f },
	{ KBD_SW, 0x50 }, { KBD_SW, 0x51 }, { KBD_SW, 0x52 }, { KBD_SW, 0x53 },
	
	{ KBD_SW, 0x54 }, { KBD_SW, 0x55 }, { KBD_SW, 0x56 }, { KBD_SW, 0x57 },
	{ KBD_SW, 0x58 }, { KBD_SW, 0x59 }, { KBD_SW, 0x5a }, { KBD_SW, 0x5b }
},	
{	//	coMIDI Mode
	{ KBD_SW, 0x30 }, { KBD_SW, 0x31 }, { KBD_SW, 0x32 }, { KBD_SW, 0x33 },
	{ KBD_SW, 0x34 }, { KBD_SW, 0x35 }, { KBD_SW, 0x36 }, { KBD_SW, 0x37 },
	
	{ KBD_SW, 0x38 }, { KBD_SW, 0x39 }, { KBD_SW, 0x3a }, { KBD_SW, 0x3b },
	{ KBD_SW, 0x3c }, { KBD_SW, 0x3d }, { KBD_SW, 0x3e }, { KBD_SW, 0x3f },
	
	{ KBD_SW, 0x47 }, { KBD_SW, 0x46 }, { KBD_SW, 0x45 }, { KBD_SW, 0x44 },
	{ KBD_SW, 0x43 }, { KBD_SW, 0x42 }, { KBD_SW, 0x41 }, { KBD_SW, 0x40 },
	
	{ OCT_SW, 0x01 }, { VEL_SW, 0x01 }, { VEL_SW, 0xff }, { PCN_SW, 0x01 },
	{ PCN_SW, 0xff }, { EFF_SW, 0x01 }, { OCT_SW, 0xff }, { KBD_SW, 0x48 }
}
};
static const uint8 VELCITY_TABLE[5] = { 60, 80, 100, 114, 127 };

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_init( void )
{
	int i;
	
	tm32_init_i2cDevice();

	heartbeat = 0; 
	sentSignalTime = 0;

	debugCounter = 0;

	mode = 0;
	for ( i=0; i<MAX_TOUCH_PADS; i++ ){ noteNumberStock[i] = 0;}
	offsetVelocity = 4;
	offsetOctave = 0;
	pcNumber = 0;

	systemTimerStkFor4msec = tm32_systemTimer+2;
	event4msec = false;
	midiExp = 0;
	tempPrsValue = 0;
	prsValue = -1000;	//	different number from tempPrsValue

	AnalysePressure_Init();
	
	//	Mode Check
	mode = 0;
	tm32_p6_1_Lo();
	tm32_p6_2_Lo();
	tm32_p6_3_Lo();
	tm32_p6_4_Lo();
	if (( tm32_p7_1() == 0 ) && ( tm32_p7_2() == 0 )){
		mode = 1;		//	coMIDI Mode
		tm32_p6_2_Hi();	//	Power Indicator
		offsetVelocity = 2;
	}

}
/*----------------------------------------------------------------------------*/
//
//      Pressure Sensor
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
static void pressureSensor( void )
{
	uint16 prs = lps25h_getPressure();

	tempPrsValue = prs;		
 	if ( tempPrsValue != prsValue ){
		int dispValue = tempPrsValue - 10000;
		ada88_writeNumber(dispValue);
		prsValue = tempPrsValue;
	}
	
	AnalysePressure_setNewRawPressure(prs);
	if ( event4msec == true ){
		if ( AnalysePressure_catchEventOfPeriodic(&midiExp) == true ){
			setMidiBuffer(0xb0,0x0b,midiExp);
		}
    }

//	ada88_writeNumber(midiExp);
}
//---------------------------------------------------------
//			Loop
//---------------------------------------------------------
void tm32_loop( void )
{
	if ( systemTimerStkFor4msec < tm32_systemTimer ){
		event4msec = true;
		systemTimerStkFor4msec += 2;
	}
	else {
		event4msec = false;
	}

	
	if ( mode == 0 ){
		//	heart beat
		if ((( tm32_systemTimer & 0x00000100 ) == 0x00000100 ) && ( heartbeat == 0 )){
			tm32_p6_1_Lo(); tm32_p6_2_Hi(); tm32_p6_3_Lo(); tm32_p6_4_Hi();
			heartbeat = 1;
		}
		if ((( tm32_systemTimer & 0x00000100 ) == 0x00000000 ) && ( heartbeat == 1 )){
			tm32_p6_1_Hi(); tm32_p6_2_Lo(); tm32_p6_3_Hi(); tm32_p6_4_Lo();
			heartbeat = 0;
		}
	}
	else if ( mode == 1 ){
		//	Octave LED
		switch( offsetOctave ){
			case -1: tm32_p6_1_Hi(); tm32_p6_4_Lo(); break;
			case  0: tm32_p6_1_Lo(); tm32_p6_4_Lo(); break;
			case  1: tm32_p6_1_Lo(); tm32_p6_4_Hi(); break;
			default: break;
		}
		if ( sentSignalTime+20 <= tm32_systemTimer ){
			//	MIDI out Indicator
			tm32_p6_3_Lo();
		}
	}

    //	Air Pressure Sensor
    pressureSensor();

}
//---------------------------------------------------------
//			Touch On
//---------------------------------------------------------
void IncDebCnt( void )
{
	debugCounter += 10;
	if ( debugCounter > 2000 ){ debugCounter = 0;}
}
//---------------------------------------------------------
void MIDIOutIndicator( void )
{
	sentSignalTime = tm32_systemTimer;
	tm32_p6_3_Hi();
}
//---------------------------------------------------------
void tm32_touchOn( int number )
{
	uint8	midiMsg[3];
	const uint8* tblPtr = &TOUCH_EVENT_TABLE[mode][number][0];

	switch(*tblPtr){
		case KBD_SW:{
			midiMsg[0] = 0x90;
			midiMsg[1] = *(tblPtr+1) + offsetOctave*12;
			midiMsg[2] = VELCITY_TABLE[offsetVelocity];
			noteNumberStock[number] = midiMsg[1];
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			break;
		}
		case PCN_SW:{
			int8 incdec = (int8)(*(tblPtr+1));
			if (( incdec > 0 ) && ( pcNumber < 127 )){ pcNumber++; }
			else if (( incdec < 0 ) && ( pcNumber > 0 )){ pcNumber--;}
			midiMsg[0] = 0xc0;
			midiMsg[1] = pcNumber;
			tm32_usbMidiOut( 2, midiMsg );
			MIDIOutIndicator();
			break;
		}
		case OCT_SW:{
			int8 incdec = (int8)(*(tblPtr+1));
			if ( offsetOctave == 0 ){
				if ( incdec > 0 ){ offsetOctave = 1;}
				else if ( incdec < 0 ){ offsetOctave = -1; }
			}
			else {
				offsetOctave = 0;
			}
			break;
		}
		case VEL_SW:{
			int8 incdec = (int8)(*(tblPtr+1));
			if (( incdec > 0 ) && ( offsetVelocity < 4 )){
				offsetVelocity++;
				MIDIOutIndicator();
			}
			else if (( incdec < 0 ) && ( offsetVelocity > 0 )){
				offsetVelocity--;
				MIDIOutIndicator();
			}
			break;
		}
		case EFF_SW:{
			midiMsg[0] = 0xb0;
			midiMsg[1] = *(tblPtr+1);
			midiMsg[2] = 0x7f;
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			break;			
		}
		default: break;
	}

	IncDebCnt();
}
//---------------------------------------------------------
//			Touch Off
//---------------------------------------------------------
void tm32_touchOff( int number )
{
	uint8	midiMsg[3];
	const uint8* tblPtr = &TOUCH_EVENT_TABLE[mode][number][0];
	
	switch(*tblPtr){
		case KBD_SW:{
			midiMsg[0] = 0x90;
			midiMsg[1] = noteNumberStock[number];
			midiMsg[2] = 0;
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			break;
		}
		case EFF_SW:{
			midiMsg[0] = 0xb0;
			midiMsg[1] = *(tblPtr+1);
			midiMsg[2] = 0;
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			break;			
		}
		default: break;
	}
	
	IncDebCnt();
}
/* [] END OF FILE */
