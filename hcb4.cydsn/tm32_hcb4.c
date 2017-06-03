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
#define		MAX_BEAT_LIGHTING_PERIOD	15
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
static uint8_t		hcbBlockConnectionPattern;
static uint8_t		hcbCrntBeat;
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

static uint8_t		touchCurrentStatus;
static int			debugCounter;

static DLE 			dle[DOREMI_MAX];

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
	debugCounter = 0;

	//	Mode Check
	tm32_p6_1_Lo();
	tm32_p6_2_Lo();
	tm32_p6_3_Lo();
	tm32_p6_4_Lo();

	hcbActive = false;
	hcbBlockID = 0;
	hcbBlockConnectionPattern = 0x10;
	hcbCrntBeat = 0;
	hcbCounterPerBeat = 0;
	
	hcbLightPatternRcvMode = false;
	hcbLightPatternRcvModeCounter = 0;
	hcbLightPatternRcvTime = 0;
	beatOn = false;

	hcbLightPattern[0] = 0b0000000000000111;
	hcbLightPattern[1] = 0b0000000000111000;
	hcbLightPattern[2] = 0b0000011100000000;
	hcbLightPattern[3] = 0b0011100000000000;
	hcbLightPattern[4] = 0b0000000000000111;
	hcbLightPattern[5] = 0b0000000000111000;
	hcbLightPattern[6] = 0b0000011100000000;
	hcbLightPattern[7] = 0b0011100000000000;
	
	for ( i=0; i<DOREMI_MAX; i++ ){
		DLE_init(&dle[i]);
	}
	
	event10msec = false;
	systemTimerStkFor10msec = tm32_systemTimer+40;
	systemTimerStkFor4msec = tm32_systemTimer+16;
	counter10msec = 0;

	touchCurrentStatus = 0;

    //  H/W init
	tm32_p6_1_Hi();
	tm32_p6_2_Hi();
}
//---------------------------------------------------------
//			Set MIDI Buffer
//---------------------------------------------------------
static void setMidiBuffer( uint8 statusByte, uint8 secondByte, uint8 thirdByte )
{
	uint8 midiMsg[3];
	midiMsg[0] = statusByte;
	midiMsg[1] = secondByte;
	midiMsg[2] = thirdByte;
	tm32_usbMidiOut( 3, midiMsg );
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
void lighteningLed( void )
{
	int		i;
	int 	seg;
	bool	beatOff = false;

	//	Periodic Job & Make Time Event
	if ( event10msec ){
		hcbCounterPerBeat++;
		if ( MAX_BEAT_LIGHTING_PERIOD == hcbCounterPerBeat ){
			beatOff = true;
		}
		for ( i=0; i<DOREMI_MAX; i++ ){
			if ( DLE_count(&dle[i]) == true ){
				colorArrayEvent[i] = true;
			}
		}
	}	
	
	//	Check DLE Segment & Make Beat Event
	seg = DLE_getSegment(&dle[hcbCrntBeat]);
	if ( seg == SEG_NOT_USE ){
		if ( beatOn == true ){
			//	Light Beat
			for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
				colorArray[hcbCrntBeat][i] = 2000 / (((hcbCrntBeat&0x01)*4)+1);
			}
			colorArrayEvent[hcbCrntBeat] = true;
		}
		if ( beatOff == true ){
			//	turn off
			for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
				colorArray[hcbCrntBeat][i] = 0;
			}
			colorArrayEvent[hcbCrntBeat] = true;
		}
	}

	//	Lightening Full Color LED
	for ( i=0; i<MAX_CELL; i++ ){
		if ( colorArrayEvent[i] == true ){
			tm32_i2cErrCode |= PCA9685_setFullColorLED( i%3, i/3, (unsigned short*)colorArray[i] );
			colorArrayEvent[i] = false;
		}
	}

	beatOn = false;
}
//---------------------------------------------------------
void tm32_loop( void )
{
	//	Generate Time Event
	generateTimeEvent();

	//	Counter Job
	if ( event10msec ){ hcbLightPatternRcvTime++;}

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
		if ( counter10msec & 0x80 ){ tm32_p6_4_Lo(); }
		else { tm32_p6_4_Hi(); }	
	}
}
//---------------------------------------------------------
//			Receive UART MIDI
//---------------------------------------------------------
void getBeat( uint8_t id, uint8_t beat )
{
	hcbBlockID = (id & 0x0f) + 1;
	hcbCrntBeat = beat;
	hcbCounterPerBeat = 0; // counter clear
	beatOn = true;
	
	uint8_t maxId = (hcbBlockConnectionPattern & 0xf0)>>4;
	if ( hcbBlockID > maxId ){
		hcbActive = false;
	}
	else {
		hcbActive = true;
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
		if ( hcbLightPatternRcvTime > 10 ){
			//	over time
			hcbLightPatternRcvMode = false;
		}
		else if ( MAX_BEAT <= hcbLightPatternRcvModeCounter ){
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
					hcbActive = false;
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
					getLightPattern( ((*(buf+1))<<8) | (*(buf+2)) );
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
void tm32_touchOn( int number )
{
	touchCurrentStatus |= (0x01<<number);
	DLE_on( &dle[number], &colorArray[number][0], number );
	colorArrayEvent[number] = true;
	setMidiBuffer( 0x90, 0x3c+number, 0x7f );
}
//---------------------------------------------------------
//			Touch Off
//---------------------------------------------------------
void tm32_touchOff( int number )
{
	touchCurrentStatus &= ~(0x01<<number);
	DLE_off( &dle[number] );
	setMidiBuffer( 0x90, 0x3c+number, 0x00 );
}
/* [] END OF FILE */
