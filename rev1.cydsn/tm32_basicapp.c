/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "tm32_lib.h"
#include "tm32_i2cdev.h"

//---------------------------------------------------------
//			Variables
//---------------------------------------------------------
static uint16	prsValue;
static uint16	tempPrsValue;
static uint8	onoff;

static int		debugCounter;

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_init( void )
{
	tm32_init_i2cDevice();

	prsValue = 0;
	tempPrsValue = 0;
	onoff = 0;

	debugCounter = 0;
}
//---------------------------------------------------------
//			Loop
//---------------------------------------------------------
void tm32_loop( void )
{
	tempPrsValue = lps22hb_getPressure();		
	if ( tempPrsValue != prsValue ){
		int dispValue = tempPrsValue - 10000;
		ada88_writeNumber(dispValue);
		prsValue = tempPrsValue;
	}	
//	ada88_writeNumber(debugCounter);
	
	if ((( tm32_systemTimer & 0x00000100 ) == 0x00000100 ) && ( onoff == 0 )){
		tm32_p6_1_Lo();
		onoff = 1;
	}
	if ((( tm32_systemTimer & 0x00000100 ) == 0x00000000 ) && ( onoff == 1 )){
		tm32_p6_1_Hi();
		onoff = 0;
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
void tm32_touchOn( int number )
{
	uint8	midiMsg[3];
	midiMsg[0] = 0x90; midiMsg[1] = 0x3c + number; midiMsg[2] = 0x7f;
	tm32_usbMidiOut( 3, midiMsg );
	IncDebCnt();
}
//---------------------------------------------------------
//			Touch Off
//---------------------------------------------------------
void tm32_touchOff( int number )
{
	uint8	midiMsg[3];
	midiMsg[0] = 0x90; midiMsg[1] = 0x3c + number; midiMsg[2] = 0;
	tm32_usbMidiOut( 3, midiMsg );
	IncDebCnt();
}
/* [] END OF FILE */
