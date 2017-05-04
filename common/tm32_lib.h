/* ========================================
 *
 *	tm32_lib.h
 *		description: TouchMidi32 Library Functions
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#ifndef TM32_LIB_H
#define	TM32_LIB_H

#include	"project.h"


//---------------------------------------------------------
//			TouchMIDI32 External Variables
//---------------------------------------------------------
extern uint32_t	tm32_systemTimer;	//	<When 1 means 250usec>
									//	4 means 1msec, 4000 means 1sec, 240,000 means 1min, 14,400,000 means 1hour
									//	345,600,000 means 1day, 32bit can measure about 4days.
									
									//	Disable <When 1 means 2msec>//	500 means 1sec, 30,000 means 1min, 1,800,000 means 1hour, 
									//	43,200,000 means 1day, 32bit can measure about 99days.


//---------------------------------------------------------
//			TouchMIDI32 Library Functions
//---------------------------------------------------------
extern void tm32_uartMidiOut( uint8 length, uint8* buf );
extern void tm32_usbMidiOut( uint8 length, uint8* buf );
extern void tm32_p6_1_Hi( void );
extern void tm32_p6_1_Lo( void );
extern void tm32_p6_2_Hi( void );
extern void tm32_p6_2_Lo( void );
extern void tm32_p6_3_Hi( void );
extern void tm32_p6_3_Lo( void );
extern void tm32_p6_4_Hi( void );
extern void tm32_p6_4_Lo( void );
uint8 tm32_p7_1( void );
uint8 tm32_p7_2( void );
uint8 tm32_p7_3( void );
uint8 tm32_p7_4( void );

//---------------------------------------------------------
//			TouchMIDI32 External Functions
//---------------------------------------------------------
extern void tm32_initLib( void );
extern void tm32_generateTouchSenseEvent( uint32 swState );
extern void tm32_rcvMidiOnUart( uint8_t dt );
extern void tm32_intrpt( void );

#endif
/* [] END OF FILE */
