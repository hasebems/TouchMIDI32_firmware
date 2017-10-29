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

extern void tm32_intrpt( void );
extern void tm32_init( void );
extern void tm32_loop( void );
extern void tm32_touchOn( int number );
extern void tm32_touchOff( int number );
extern void tm32_rcvUart( int count, uint8_t* buf );

//---------------
//	configration
//---------------
//	UART MIDI Rx
#define		UART_MIDI_RX_NO_USE			0	//	if you use UART Rx, should pull-up Rx.
#define		UART_MIDI_RX_TO_USBOUT		1
#define		UART_MIDI_RX_TO_MAIN_APP	2	//	inplement tm32_rcvUart()
#define		UART_MIDI_RX				UART_MIDI_RX_TO_MAIN_APP
//	UART MIDI Tx
#define		UART_MIDI_TX_NO_USE			0
#define		UART_MIDI_TX_SAME_AS_USBOUT	1
#define		UART_MIDI_TX_TO_MAIN_APP	2
#define		UART_MIDI_TX				UART_MIDI_TX_TO_MAIN_APP

//---------------------------------------------------------
//		I2C Device Configuration
//---------------------------------------------------------
#define		USE_ADA88
//#define		USE_LPS22HB
//#define		USE_LPS25H
//#define		USE_AQM1602XA
//#define		USE_ADXL345
#define		USE_PCA9685

#endif
/* [] END OF FILE */
