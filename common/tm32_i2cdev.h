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
//			TouchMIDI32 External Functions
//---------------------------------------------------------
extern int tm32_i2cErrCode;
	
extern void tm32_init_i2cDevice( void );

extern void ada88_init( void );
extern void ada88_write( int letter );
extern void ada88_writeNumber( int num );

extern void lps22hb_init( void );
extern uint16 lps22hb_getPressure( void );

extern void lps25h_init( void );
extern uint16 lps25h_getPressure( void );

extern void aqm1602xa_init( void );
extern void aqm1602xa_setStringUpper( int locate, char* str, int strNum );

extern void adxl345_init( unsigned char chipnum );
extern int adxl345_getAccel( unsigned char chipnum, signed short* value );

extern void PCA9685_init( int chipNumber );
extern int PCA9685_setFullColorLED( int chipNumber, int ledNum, unsigned short* color  );

#endif
/* [] END OF FILE */
