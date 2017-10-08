/* ========================================
 *
 *	tm32_lib.c
 *		description: TouchMidi32 Library Functions
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include	"project.h"
#include	"tm32_lib.h"
#include	"tm32_app.h"

//---------------------------------------------------------
//			TouchMIDI32 Variables
//---------------------------------------------------------
uint32_t	tm32_systemTimer;	//	<When 1 means 250usec/ see System Timer Configure "period:8" >
								//	4 means 1msec, 4000 means 1sec, 240,000 means 1min, 14,400,000 means 1hour
								//	345,600,000 means 1day, 32bit can measure about 4days.
									
								//	Disable <When 1 means 2msec/ see System Timer Configure "period:64" >
								//	500 means 1sec, 30,000 means 1min, 1,800,000 means 1hour, 
								//	43,200,000 means 1day, 32bit(4,294,967,296) can measure about 99days.
								//	This value is incremented by interrupt, don't write.
uint8		systemErr;
								
//	Internal Variables
static uint32	oldSwState;
static uint8_t	midiStatusByte;
static uint8_t	midiDataByte1;
static uint8_t	uartMidiCount;

//---------------------------------------------------------
//			MIDI OUT ( Channel Message Only )
//---------------------------------------------------------
void tm32_uartMidiOut( uint8 length, uint8* buf )
{
#if ( UART_MIDI_TX != UART_MIDI_TX_NO_USE )
	int		i;
	for ( i=0; i<length; i++ ){
		MIDI_UART_PutChar( *(buf+i) );
	}	
#endif
}
//---------------------------------------------------------
void tm32_usbMidiOut( uint8 length, uint8* buf )
{
	if ( length >= 4 ){ return;}
	systemErr = USBMIDI_PutUsbMidiIn( length, (const uint8*)buf, 0);
#if ( UART_MIDI_TX == UART_MIDI_TX_SAME_AS_USBOUT )
	tm32_uartMidiOut( length, buf );
#endif
}

//---------------------------------------------------------
//			PORT
//---------------------------------------------------------
#ifndef P6_1_AS_PORT_INPUT
void tm32_p6_1_Hi( void ){	Pin_1_Write(1);}
void tm32_p6_1_Lo( void ){	Pin_1_Write(0);}
#else
uint8 tm32_p6_1( void ){ return Pin_5_Read();}
#endif
#ifndef P6_2_AS_PORT_INPUT
void tm32_p6_2_Hi( void ){	Pin_2_Write(1);}
void tm32_p6_2_Lo( void ){	Pin_2_Write(0);}
#else
uint8 tm32_p6_2( void ){ return Pin_6_Read();}
#endif
#ifndef P6_3_AS_PORT_INPUT
void tm32_p6_3_Hi( void ){	Pin_3_Write(1);}
void tm32_p6_3_Lo( void ){	Pin_3_Write(0);}
#else
uint8 tm32_p6_3( void ){ return Pin_7_Read();}
#endif
#ifndef P6_4_AS_PORT_INPUT
void tm32_p6_4_Hi( void ){	Pin_4_Write(1);}
void tm32_p6_4_Lo( void ){	Pin_4_Write(0);}
#else
uint8 tm32_p6_4( void ){ return Pin_8_Read();}
#endif

#ifndef NO_USE_P7
uint8 tm32_p7_1( void ){ return Pin_5_Read();}
uint8 tm32_p7_2( void ){ return Pin_6_Read();}
uint8 tm32_p7_3( void ){ return Pin_7_Read();}
uint8 tm32_p7_4( void ){ return Pin_8_Read();}
#endif

//---------------------------------------------------------
//			Initialize
//---------------------------------------------------------
void tm32_initLib( void )
{	
	tm32_systemTimer = 0;
	systemErr = 0;
	
	oldSwState = 0;
	midiStatusByte = 0;
	midiDataByte1 = 0;
	uartMidiCount = 0;

#ifndef P6_1_AS_PORT_INPUT
	tm32_p6_1_Lo();
#endif
#ifndef P6_2_AS_PORT_INPUT	
	tm32_p6_2_Lo();
#endif
#ifndef P6_3_AS_PORT_INPUT	
	tm32_p6_3_Lo();
#endif
#ifndef P6_4_AS_PORT_INPUT
	tm32_p6_4_Lo();
#endif
}						
//---------------------------------------------------------
//		Touch Sense Event
//---------------------------------------------------------
void tm32_generateTouchSenseEvent( uint32 swState )
{
	int		i;
	uint32	shiftBit = 0x0001;

	if ( swState == oldSwState ){ return; }

	for ( i=0; i<32; i++ ){
		if ( (swState^oldSwState) & shiftBit ){
			if ( swState & shiftBit ){ tm32_touchOn(i);}
			else { tm32_touchOff(i);}
		}
		shiftBit <<= 1;
	}
	oldSwState = swState;
}
//---------------------------------------------------------
//		UART MIDI Rx
//---------------------------------------------------------
void tm32_rcvMidiOnUart( uint8_t dt )
{
	if ( dt & 0x80 ){
		//	Status Byte	
		midiStatusByte = dt;
		uartMidiCount = 1;
	}
	else {
		//	Data Byte
		if ( uartMidiCount == 0 ){
			//	Runing Status
			uartMidiCount++;
		}
		if ( uartMidiCount == 1 ){
			switch ( midiStatusByte & 0xf0 ){
				case 0xc0:
				case 0xd0:{
					//	2byte code
 #if ( UART_MIDI_RX != UART_MIDI_RX_NOT_USE )
					uint8_t	mdt[2];
					mdt[0] = midiStatusByte;
					mdt[1] = dt;
 #if ( UART_MIDI_RX	== UART_MIDI_RX_TO_USBOUT )
					tm32_usbMidiOut( 2,mdt );
 #elif ( UART_MIDI_RX == UART_MIDI_RX_TO_MAIN_APP )
					tm32_rcvUart( 2,mdt );
 #endif
					uartMidiCount = 0;
 #endif
					break;
				}
				default:{
					midiDataByte1 = dt;
					uartMidiCount++;
					break;
				}
			}
		}
		else if ( uartMidiCount >= 2 ){
			switch ( midiStatusByte & 0xf0 ){
				case 0x80: case 0x90: case 0xa0: case 0xb0:
				case 0xe0:{
 #if ( UART_MIDI_RX != UART_MIDI_RX_NOT_USE )
					uint8_t mdt[3];
					mdt[0] = midiStatusByte;
					mdt[1] = midiDataByte1;
					mdt[2] = dt;
					//	3byte code
 #if ( UART_MIDI_RX	== UART_MIDI_RX_TO_USBOUT )
					tm32_usbMidiOut( 3,mdt );
 #elif ( UART_MIDI_RX == UART_MIDI_RX_TO_MAIN_APP )
					tm32_rcvUart( 3,mdt );
 #endif
					uartMidiCount = 0;
 #endif
					break;
				}
				default:{
					uartMidiCount++;
					break;
				}
			}
		}		
	}
}
/* [] END OF FILE */
