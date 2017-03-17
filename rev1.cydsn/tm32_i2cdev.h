/* ========================================
 *
 *	tm32_i2cdev.h
 *		description: TouchMidi32 I2C Device Driver
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#ifndef		TM32_I2CDEV_H
#define		TM32_I2CDEV_H
	
#include	"project.h"


//---------------------------------------------------------
//		I2C Device Configuration
//---------------------------------------------------------
#define		USE_ADA88
#define		USE_LPS22HB
//#define		USE_AQM1602XA

//---------------------------------------------------------
//			TouchMIDI32 External Functions
//---------------------------------------------------------
extern int tm32_i2cErrCode;
	
extern void tm32_init_i2cDevice( void );

extern void ada88_init( void );
extern void ada88_write( int letter );
extern void ada88_writeNumber( int num );

extern void lps22hb_init( void );
extern uint16 lps22hb_getPressure( void );

extern void aqm1602xa_init( void );
extern void aqm1602xa_setStringUpper( int locate, char* str, int strNum );

#endif
/* [] END OF FILE */
