/* ========================================
 *
 *	tm32_basicapp.c
 *		description: TouchMidi32 Default application
 *
 *	Copyright(c)2018 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include "tm32_lib.h"
#include "tm32_i2cdev.h"
#include "tm32_app.h"

#include	"fmsd1.h"
#include	"fmif.h"

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
//static uint16	prsValue;
//static uint16	tempPrsValue;
static uint8	heartbeat;
static uint32_t	sentSignalTime;

static uint8	noteNumberStock[MAX_TOUCH_PADS];
static uint8	offsetVelocity;
static int8		offsetOctave;
static uint8	pcNumber;

static int		debugCounter;

//static const uint8 VELCITY_TABLE[5];
//---------------------------------------------------------
//			Tables
//---------------------------------------------------------
static const uint8 TOUCH_EVENT_TABLE[MAX_TOUCH_PADS][2] =
{
	{ KBD_SW, 0x54 }, { OCT_SW, 0xff }, { EFF_SW, 0x01 }, { PCN_SW, 0xff },
	{ PCN_SW, 0x01 }, { VEL_SW, 0xff }, { VEL_SW, 0x01 }, { OCT_SW, 0x01 },

	{ KBD_SW, 0x3c }, { KBD_SW, 0x3d }, { KBD_SW, 0x3e }, { KBD_SW, 0x3f },
	{ KBD_SW, 0x40 }, { KBD_SW, 0x41 }, { KBD_SW, 0x42 }, { KBD_SW, 0x43 },
	
	{ KBD_SW, 0x44 }, { KBD_SW, 0x45 }, { KBD_SW, 0x46 }, { KBD_SW, 0x47 },
	{ KBD_SW, 0x48 }, { KBD_SW, 0x49 }, { KBD_SW, 0x4a }, { KBD_SW, 0x4b },
	
	{ KBD_SW, 0x4c }, { KBD_SW, 0x4d }, { KBD_SW, 0x4e }, { KBD_SW, 0x4f },
	{ KBD_SW, 0x50 }, { KBD_SW, 0x51 }, { KBD_SW, 0x52 }, { KBD_SW, 0x53 }
};
static const uint8 VELCITY_TABLE[5] = { 60, 80, 100, 114, 127 };

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_init( void )
{
	int i;
	
	tm32_init_i2cDevice();

	//	SPI/SD1 Initialize
	initSPI();
	initSD1();
	Fmdriver_init();
	
	//prsValue = 0;
	//tempPrsValue = 0;
	heartbeat = 0; 
	sentSignalTime = 0;

	debugCounter = 0;

	for ( i=0; i<MAX_TOUCH_PADS; i++ ){ noteNumberStock[i] = 0;}
	offsetVelocity = 2;
	offsetOctave = 0;
	pcNumber = 0;

	//	Power On
	tm32_p6_4_Hi();
}
//---------------------------------------------------------
//			Loop
//---------------------------------------------------------
void tm32_loop( void )
{
	//	Octave LED
	switch( offsetOctave ){
		case -1: tm32_p6_1_Hi(); tm32_p6_2_Lo(); break;
		case  0: tm32_p6_1_Lo(); tm32_p6_2_Lo(); break;
		case  1: tm32_p6_1_Lo(); tm32_p6_2_Hi(); break;
		default: break;
	}
	if ( sentSignalTime+20 <= tm32_systemTimer ){
		//	MIDI out Indicator
		tm32_p6_3_Lo();
	}
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
	const uint8* tblPtr = &TOUCH_EVENT_TABLE[number][0];

	switch(*tblPtr){
		case KBD_SW:{
			midiMsg[0] = 0x90;
			midiMsg[1] = *(tblPtr+1) + offsetOctave*12;
			midiMsg[2] = VELCITY_TABLE[offsetVelocity];
			noteNumberStock[number] = midiMsg[1];
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			Fmdriver_sendMidi(midiMsg[0]);
			Fmdriver_sendMidi(midiMsg[1]);
			Fmdriver_sendMidi(midiMsg[2]);
			break;
		}
		case PCN_SW:{
			int8 incdec = (int8)(*(tblPtr+1));
			if (( incdec > 0 ) && ( pcNumber < 127 )){ pcNumber++; }
			else if (( incdec < 0 ) && ( pcNumber > 0 )){ pcNumber--;}
			midiMsg[0] = 0xc0;
			midiMsg[1] = pcNumber;
			tm32_usbMidiOut( 2, midiMsg );
			Fmdriver_sendMidi(midiMsg[0]);
			Fmdriver_sendMidi(midiMsg[1]);
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
	const uint8* tblPtr = &TOUCH_EVENT_TABLE[number][0];
	
	switch(*tblPtr){
		case KBD_SW:{
			midiMsg[0] = 0x90;
			midiMsg[1] = noteNumberStock[number];
			midiMsg[2] = 0;
			tm32_usbMidiOut( 3, midiMsg );
			MIDIOutIndicator();
			Fmdriver_sendMidi(midiMsg[0]);
			Fmdriver_sendMidi(midiMsg[1]);
			Fmdriver_sendMidi(midiMsg[2]);

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
