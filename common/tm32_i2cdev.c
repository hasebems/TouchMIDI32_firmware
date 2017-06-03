/* ========================================
 *
 *	tm32_i2cdev.c
 *		description: TouchMidi32 I2C Device Driver
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include	"project.h"
#include	"tm32_app.h"
#include	"tm32_i2cdev.h"

//---------------------------------------------------------
//		Variables
//---------------------------------------------------------
int		tm32_i2cErrCode;


//---------------------------------------------------------
//		Initialize I2C Device
//---------------------------------------------------------
void tm32_init_i2cDevice( void )
{
	tm32_i2cErrCode = 0;
	
	ada88_init();
	lps22hb_init();
	lps25h_init();	
	aqm1602xa_init();
	adxl345_init(0);
	PCA9685_init(0);
}
//---------------------------------------------------------
//		Write I2C Device
//---------------------------------------------------------
int write_i2cDevice( uint16 adrs, uint8* buf, uint32 count )
{
	int 	i=0;
	uint8	err;
	I2C_I2CMasterClearStatus();
	I2C_I2CMasterWriteBuf( adrs, buf, count, I2C_I2C_MODE_COMPLETE_XFER );
	do {
		err = I2C_I2CMasterStatus();
		if ( ++i > 1000 ){
			tm32_i2cErrCode = err;
			return err;
		}
	} while (( err &  I2C_I2C_MSTAT_WR_CMPLT ) == 0 );
	return 0;
}
//---------------------------------------------------------
//		Read 1byte I2C Device
//---------------------------------------------------------
int read1byte_i2cDevice( uint16 adrs, uint8* wrBuf, uint8* rdData, uint32 wrCount )
{
	int 	i=0;	
	uint8	err;
	I2C_I2CMasterClearStatus();
	I2C_I2CMasterWriteBuf( adrs, wrBuf, wrCount, I2C_I2C_MODE_NO_STOP );
	do {
		err = I2C_I2CMasterStatus();
		if ( ++i > 1000 ){
			tm32_i2cErrCode = err;
			return err;
		}
	} while (( err &  I2C_I2C_MSTAT_WR_CMPLT ) == 0 );

	I2C_I2CMasterClearStatus();
	I2C_I2CMasterReadBuf( adrs, rdData, 1, I2C_I2C_MODE_REPEAT_START );
	do {
		err = I2C_I2CMasterStatus();
		if ( ++i > 1000 ){
			tm32_i2cErrCode = err;
			return err;
		}
	} while (( err &  I2C_I2C_MSTAT_RD_CMPLT ) == 0 );

	return 0;
}
//---------------------------------------------------------
//		Read N byte I2C Device
//---------------------------------------------------------
int read_nbyte_i2cDevice( uint16 adrs, uint8* wrBuf, uint8* rdData, uint32 wrCount, uint32 rdCount )
{
	int 	i=0;	
	uint8	err;
	I2C_I2CMasterClearStatus();
	I2C_I2CMasterWriteBuf( adrs, wrBuf, wrCount, I2C_I2C_MODE_NO_STOP );
	do {
		err = I2C_I2CMasterStatus();
		if ( ++i > 1000 ){
			tm32_i2cErrCode = err;
			return err;
		}
	} while (( err &  I2C_I2C_MSTAT_WR_CMPLT ) == 0 );

	I2C_I2CMasterClearStatus();
	I2C_I2CMasterReadBuf( adrs, rdData, rdCount, I2C_I2C_MODE_REPEAT_START );
	do {
		err = I2C_I2CMasterStatus();
		if ( ++i > 1000 ){
			tm32_i2cErrCode = err;
			return err;
		}
	} while (( err &  I2C_I2C_MSTAT_RD_CMPLT ) == 0 );

	return 0;
}

#ifdef USE_ADA88
//---------------------------------------------------------
//		<< ADA88 >>
//---------------------------------------------------------
#define		ADA88_I2C_ADRS		0x0070
//---------------------------------------------------------
//		Initialize ADA88 LED Matrix
//---------------------------------------------------------
void ada88_init( void )
{
	uint8 i2cBuf[2] = {0};
	i2cBuf[0] = 0x21;
	write_i2cDevice( ADA88_I2C_ADRS, i2cBuf, 2 );

	i2cBuf[0] = 0x81;
	write_i2cDevice( ADA88_I2C_ADRS, i2cBuf, 2 );

	i2cBuf[0] = 0xef;
	write_i2cDevice( ADA88_I2C_ADRS, i2cBuf, 2 );

	ada88_write(0);
}
//---------------------------------------------------------
//	write Character to Ada LED-matrix
//---------------------------------------------------------
void ada88_write( int letter )
{
	int	i;
	uint8 i2cBufx[17];
	const uint8 letters[21][8] = {
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	//	0:nothing
		{0x02,0x05,0x88,0x88,0x8f,0x88,0x88,0x88},	//	1:A
		{0x87,0x88,0x88,0x87,0x88,0x88,0x88,0x87},	//	2:B
		{0x07,0x88,0x88,0x80,0x80,0x88,0x88,0x07},	//	3:C
		{0x87,0x88,0x88,0x88,0x88,0x88,0x88,0x87},	//	4:D
		{0x87,0x80,0x80,0x87,0x80,0x80,0x80,0x8f},	//	5:E
		{0x87,0x80,0x80,0x87,0x80,0x80,0x80,0x80},	//	6:F
		{0x07,0x88,0x80,0x80,0x8e,0x88,0x88,0x07},	//	7:G
		{0x88,0x88,0x88,0x8f,0x88,0x88,0x88,0x88},	//	8:H

		{0x02,0x05,0x88,0xe8,0xaf,0xe8,0xa8,0xa8},	//	9:AF
		{0x87,0x88,0x88,0xe7,0xa8,0xe8,0xa8,0xa7},	//	10:BF
		{0x07,0x88,0x88,0xe0,0xa0,0xe8,0xa8,0x27},	//	11:CF
		{0x87,0x88,0x88,0xe8,0xa8,0xe8,0xa8,0xa7},	//	12:DF
		{0x87,0x80,0x80,0xe7,0xa0,0xe0,0xa0,0xaf},	//	13:EF
		{0x87,0x80,0x80,0xe7,0xa0,0xe0,0xa0,0xa0},	//	14:FF
		{0x07,0x88,0x80,0xe0,0xae,0xe8,0xa8,0x27},	//	15:GF

		{0x97,0x90,0x90,0x97,0x90,0x90,0x90,0xd0},	//	16:Fl.
		{0x13,0x94,0x94,0xf4,0xd4,0xd4,0xb4,0x53},	//	17:Ob.

		{0x04,0x1f,0x04,0x1f,0x04,0x0f,0x15,0x22},	//	18:MA
		{0x04,0x0f,0x04,0x1e,0x08,0x12,0x01,0x0e},	//	19:KI
		{0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa}	//	20:
	};

	i2cBufx[0] = 0;
	for ( i=0; i<8; i++ ){
		i2cBufx[i*2+1] = letters[letter][i];
		i2cBufx[i*2+2] = 0;
	}
	write_i2cDevice( ADA88_I2C_ADRS, i2cBufx, 17 );
}
//---------------------------------------------------------
void ada88_writeNumber( int num )	//	num 1999 .. -1999
{
	int i;
	uint8 i2cBufx[17];
	uint8 ledPtn[8] = {0};
	const uint8 numletter[10][5] = {
		{ 0x07, 0x05, 0x05, 0x05, 0x07 },
		{ 0x04, 0x04, 0x04, 0x04, 0x04 },
		{ 0x07, 0x04, 0x07, 0x01, 0x07 },
		{ 0x07, 0x04, 0x07, 0x04, 0x07 },
		{ 0x05, 0x05, 0x07, 0x04, 0x04 },
		{ 0x07, 0x01, 0x07, 0x04, 0x07 },
		{ 0x07, 0x01, 0x07, 0x05, 0x07 },
		{ 0x07, 0x04, 0x04, 0x04, 0x04 },
		{ 0x07, 0x05, 0x07, 0x05, 0x07 },
		{ 0x07, 0x05, 0x07, 0x04, 0x07 }
	};
	const uint8 graph[10][2] = {
		{ 0x00, 0x00 },
		{ 0x00, 0x40 },
		{ 0x40, 0x60 },
		{ 0x60, 0x70 },
		{ 0x70, 0x78 },
		{ 0x78, 0x7c },
		{ 0x7c, 0x7e },
		{ 0x7e, 0x7f },
		{ 0x7f, 0xff },
		{ 0xff, 0xff }
	};	

	if ( num > 1999 ){ num = 1999; }
	else if ( num < -1999 ){ num = -1999;}
	
	//	+/-, over 1000 or not
	if ( num/1000 ){ ledPtn[5] |= 0x80; }
	if ( num<0 ){
		ledPtn[2] |= 0x80;
		num = -num;
	}

	int num3digits = num%1000;
	int hundred = num3digits/100;
	int num2degits = num3digits%100;
	int deci = num2degits/10;
	int z2n = num2degits%10;

	for ( i=0; i<5; i++ ){
		ledPtn[i] |= numletter[hundred][i];
	}
	for ( i=0; i<5; i++ ){
		ledPtn[i] |= (numletter[deci][i]<<4);
	}
	for ( i=0; i<2; i++ ){
		ledPtn[i+6] = graph[z2n][i];
	}

	i2cBufx[0] = 0;
	for ( i=0; i<8; i++ ){
		i2cBufx[i*2+1] = ledPtn[i];
		i2cBufx[i*2+2] = 0;
	}
	write_i2cDevice( ADA88_I2C_ADRS, i2cBufx, 17 );
}
#else
void ada88_init( void ){}
void ada88_write( int letter ){}
void ada88_writeNumber( int num ){}
#endif

#ifdef USE_LPS22HB
//---------------------------------------------------------
//		<< LPS22HB >>
//---------------------------------------------------------
uint8		lps22hbEnable;		//	0: disable 1-: enable
uint8 isLps22hbAvailable( void ){ return lps22hbEnable; }
//---------------------------------------------------------
#define		LPS22HB_I2C_ADRS	0x5c
//---------------------------------------------------------
//		Initialize LPS22HB
//---------------------------------------------------------
void lps22hb_init( void )
{
	uint8 wrBuf = 0x0f;
	uint8 rdData;
	lps22hbEnable = 1;

	//	Read "Who am I?"
	read1byte_i2cDevice( LPS22HB_I2C_ADRS, &wrBuf, &rdData, 1 );
	
	//	Read correctly? 
	if ( rdData != 0xb1 ){
		lps22hbEnable = 0;
		return;
	}
	
	//	Set 75Hz
	uint8	i2cBuf[2] = { 0 };
	i2cBuf[0] = 0x10;
	i2cBuf[1] = 0x50;	//	75Hz(maximum)
	write_i2cDevice( LPS22HB_I2C_ADRS, i2cBuf, 2 );
}
//---------------------------------------------------------
//		LPS22HB Get Air Pressure
//			return value means [hPa*10]
//---------------------------------------------------------
uint16 lps22hb_getPressure( void )
{
	uint8	i2cBuf;
	uint8	value[2];
	int		i;

	if ( lps22hbEnable == 0 ) return 0;
	
	for ( i=0; i<2; i++ ){		
		i2cBuf = 0x29 + i;
		read1byte_i2cDevice( LPS22HB_I2C_ADRS, &i2cBuf, &value[i], 1 );
	}
	return ((value[0] + (value[1]<<8))*10)/16;
}
#else
uint8 isLps22hbAvailable( void ){return 0;}
void lps22hb_init( void ){}
uint16 lps22hb_getPressure( void ){return 0;}
#endif

#ifdef USE_LPS25H
//---------------------------------------------------------
//		<< LPS25H >>
//---------------------------------------------------------
//uint8		lps22hbEnable;		//	0: disable 1-: enable
//uint8 isLps22hbAvailable( void ){ return lps22hbEnable; }
//---------------------------------------------------------
#define		LPS25H_I2C_ADRS	0x5d
//	for Pressure Sencer
#define		PRES_SNCR_RESOLUTION		0x10
#define		PRES_SNCR_PWRON				0x20
#define		PRES_SNCR_START				0x21
#define		PRES_SNCR_ONE_SHOT			0x01
#define		PRES_SNCR_RCV_DT_FLG		0x27
#define		PRES_SNCR_RCV_TMPR			0x01
#define		PRES_SNCR_RCV_PRES			0x02
#define		PRES_SNCR_DT_L				0x28
#define		PRES_SNCR_DT_M				0x29
#define		PRES_SNCR_DT_H				0x2a
//-------------------------------------------------------------------------
void lps25h_init( void )
{
	uint8	i2cBuf[2] = { 0 };
	i2cBuf[0] = PRES_SNCR_PWRON;
	i2cBuf[1] = 0xc0;
	write_i2cDevice( LPS25H_I2C_ADRS, i2cBuf, 2 );	//	Power On
}
//---------------------------------------------------------
//		LPS25H Get Air Pressure
//			return value means [hPa*10]
//---------------------------------------------------------
uint16 lps25h_getPressure( void )
{
	unsigned char	dt[3];
	unsigned char adrs;
	int		err;
	uint16	retValue = 0;

	adrs = PRES_SNCR_DT_L|0x80;
	err = read_nbyte_i2cDevice( LPS25H_I2C_ADRS, &adrs, dt, 1, 3 );	

	if ( !err ){
		float tmpPrs = (float)(((unsigned long)dt[2]<<16)|((unsigned long)dt[1]<<8)|dt[0]);
		tmpPrs = tmpPrs*10/4096;
		retValue = (uint16)tmpPrs;
	}

	return retValue;
}
#else
void lps25h_init( void ){}
uint16 lps25h_getPressure( void ){ return 0; }
#endif


#ifdef USE_AQM1602XA
//---------------------------------------------------------
//		<< AQM1602XA >>		I2C freq. is less than 100[kHz]
//---------------------------------------------------------
#define		AQM1602XA_I2C_ADRS	0x3e
//---------------------------------------------------------
//		Initialize AQM0802A
//---------------------------------------------------------
void aqm1602xa_init( void )
{
	uint8	i2cBuf[2];
	int	err;
	
	CyDelay(40);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x38;
	err = write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }

	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x39;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }

	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x14;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x73;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x56;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x6a;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(200);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x38;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x01;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(20);
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x0c;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
	if ( err ){ tm32_i2cErrCode = err; return; }
	
	CyDelay(2);	
}
//---------------------------------------------------------
//		write AQM0802A
//---------------------------------------------------------
void aqm1602xa_setStringUpper( int locate, char* str, int strNum )
{
	uint8	i2cBuf[2];
	int		i;
	
	if ( locate >= 8 ) return;
	if ( locate + strNum > 8 ){ strNum = 8 - locate; }

	i2cBuf[0] = 0x00; i2cBuf[1] = (uint8)locate | 0x80;
	write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
    CyDelayUs(500);		//	needs more than this period

	for ( i=0; i<strNum; i++ ){
		i2cBuf[0] = 0x40; i2cBuf[1] = str[i]; 
		write_i2cDevice( AQM1602XA_I2C_ADRS, i2cBuf, 2 );
		CyDelayUs(500);//	needs more than this period
	}

}
#else
void aqm1602xa_init( void ){}
void aqm1602xa_setStringUpper( int locate, char* str, int strNum ){}
#endif


#ifdef USE_ADXL345
//---------------------------------------------------------
//		<< ADXL345 >>
//---------------------------------------------------------
#define		ADXL345_I2C_ADRS	0x1d
#define		ADXL345_I2C_ADRS2	0x53
//-------------------------------------------------------------------------
//			ADXL345 (Acceleration Sencer : I2c Device)
//-------------------------------------------------------------------------
//	for Acceleration Sencer
#define	ACCEL_SNCR_RATE				0x2c
#define ACCEL_SNCR_PWR_CTRL			0x2d
#define ACCEL_SNCR_DATA_FORMAT		0x31
//-------------------------------------------------------------------------
void adxl345_init( unsigned char chipnum )
{
	unsigned char i2cadrs = ADXL345_I2C_ADRS;
	if ( chipnum == 1 ){ i2cadrs = ADXL345_I2C_ADRS2; }

	uint8	i2cBuf[2];
	
	//	Start Access
	i2cBuf[0] = ACCEL_SNCR_PWR_CTRL; i2cBuf[1] = 0x08;
	write_i2cDevice(i2cadrs,i2cBuf,2);			//	Start Measurement
	i2cBuf[0] = ACCEL_SNCR_DATA_FORMAT; i2cBuf[1] = 0x04;
	write_i2cDevice(i2cadrs,i2cBuf,2 );		//	Left Justified, 2g

#if 0	//	if Shaker
	writeI2cWithCmd(i2cadrs,ACCEL_SNCR_RATE,0x0b);				//	200Hz (5msec)
	writeI2cWithCmd(i2cadrs,ACCEL_SNCR_PWR_CTRL,0x08);			//	Start Measurement
	writeI2cWithCmd(i2cadrs,ACCEL_SNCR_DATA_FORMAT,0x05);		//	Left Justified, 4g
#endif
}
//-------------------------------------------------------------------------
int adxl345_getAccel( unsigned char chipnum, signed short* value )
{
	unsigned short tmp;
	unsigned char reg[2];
	unsigned char adrs;
	unsigned char i2cadrs = ADXL345_I2C_ADRS;
	int err;

	if ( chipnum == 1 ){ i2cadrs = ADXL345_I2C_ADRS2; }

	adrs = 0x32;
	err = read_nbyte_i2cDevice( i2cadrs, &adrs, reg, 1, 2 );
	if (!err){
		tmp = reg[0];
		tmp |= (unsigned short)reg[1] << 8;
		*value = (signed short)tmp;
	}
	else {
		*value = 0;
	}

	adrs = 0x34;
	err = read_nbyte_i2cDevice( i2cadrs, &adrs, reg, 1, 2 );
	if (!err){
		tmp = reg[0];
		tmp |= (unsigned short)reg[1] << 8;
		*(value+1) = (signed short)tmp;
	}
	else {
		*(value+1) = 0;
	}

	adrs = 0x36;
	err = read_nbyte_i2cDevice( i2cadrs, &adrs, reg, 1, 2 );
	if (!err){
		tmp = reg[0];
		tmp |= (unsigned short)reg[1] << 8;
		*(value+2) = (signed short)tmp;
	}
	else {
		*(value+2) = 0;
	}
	return 0;
}
#else
void adxl345_init( unsigned char chipnum ){}
int adxl345_getAccel( unsigned char chipnum, signed short* value ){return 0;}
#endif

//-------------------------------------------------------------------------
//			PCA9685 (LED Driver : I2c Device)
//-------------------------------------------------------------------------
#ifdef USE_PCA9685    //	for LED Driver
static const unsigned char PCA9685_ADDRESS = 0x40;
//-------------------------------------------------------------------------
void PCA9685_init( int chipNumber )
{
	uint8	i2cBuf[2];
	
	//	Init Parameter
	i2cBuf[0] = 0x00; i2cBuf[1] = 0x00;
	write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2 );	//
	i2cBuf[0] = 0x01; i2cBuf[1] = 0x12;
	write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2 );	//	Invert, OE=high-impedance
}
//-------------------------------------------------------------------------
//		rNum, gNum, bNum : 0 - 4094  bigger, brighter
//-------------------------------------------------------------------------
int PCA9685_setFullColorLED( int chipNumber, int ledNum, unsigned short* color  )
{
    int err = 0;
	int	i;
    ledNum &= 0x03;
	uint8	i2cBuf[2];
	
	for ( i=0; i<3; i++ ){
		//	figure out PWM counter
		unsigned short colorCnt = *(color+i);
		colorCnt = 4095 - colorCnt;
		if ( colorCnt <= 0 ){ colorCnt = 1;}

		//	Set PWM On Timing
		i2cBuf[0] = (uint8)(0x06 + i*4 + ledNum*16);
		i2cBuf[1] = (uint8)(colorCnt & 0x00ff);
		err = write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2);	//
        if ( err != 0 ){ return err; }
		i2cBuf[0] = (uint8)(0x07 + i*4 + ledNum*16);
		i2cBuf[1] = (uint8)((colorCnt & 0xff00)>>8);
		err = write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2 );	//
        if ( err != 0 ){ return err; }

		//	Set PWM Off Timing
		i2cBuf[0] = (uint8)(0x08 + i*4 + ledNum*16); i2cBuf[1] = 0;
		err = write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2 );	//
        if ( err != 0 ){ return err; }
		i2cBuf[1] = (uint8)(0x09 + i*4 + ledNum*16); i2cBuf[1] = 0;
        err = write_i2cDevice( PCA9685_ADDRESS+chipNumber, i2cBuf, 2 );	//
        if ( err != 0 ){ return err; }
	}
    return err;
}
#else
void PCA9685_init( int chipNumber ){}
int PCA9685_setFullColorLED( int chipNumber, int ledNum, unsigned short* color  ){}
#endif

/* [] END OF FILE */
