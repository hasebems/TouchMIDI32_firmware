/* ========================================
 *
 *	tm32_app.h
 *		description: TouchMidi32 App Functions Definition
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt.
 *
 * ========================================
*/
#ifndef TM32_APP_H
#define TM32_APP_H
#include	"project.h"

extern void tm32_init( void );	
extern void tm32_loop( void );
extern void tm32_touchOn( int number );
extern void tm32_touchOff( int number );
extern void tm32_rcvUart( int count, uint8_t* buf );

//---------------
//	configration
//---------------
//	UART MIDI Rx
#define		UART_MIDI_RX_TO_USBOUT		1
#define		UART_MIDI_RX_TO_MAIN_APP	2	//	inplement tm32_rcvUart()
#define		UART_MIDI_RX				UART_MIDI_RX_TO_USBOUT



#endif
/* [] END OF FILE */
