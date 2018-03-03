// fmsd1_psoc.c
#include "SPI.h"
#include "SPI_SPI_UART.h"
#include "RST_N.h"
#include "tm32_lib.h"

#define		SS_ENABLE	0
#define		SS_DISABLE	1


void ss(int en)
{
	if (en == 0){ SPI_SpiSetActiveSlaveSelect(0);}
}
void writeSingle( unsigned char adrs, unsigned char data )
{
	while( SPI_SpiIsBusBusy() ){}
	ss(SS_ENABLE);
	SPI_SpiUartWriteTxData(adrs);
	SPI_SpiUartWriteTxData(data);
	ss(SS_DISABLE);
}
void writeBurst( unsigned char adrs, unsigned char* data, int count )
{
	int i;
	while( SPI_SpiIsBusBusy() ){}
	ss(SS_ENABLE);
	SPI_SpiUartWriteTxData(adrs);
	for (i = 0; i<count; i++) {
		SPI_SpiUartWriteTxData(*(data + i));
	}
	ss(SS_DISABLE);
}
void delayMs( int ms )
{
//	uint32_t cnt = tm32_systemTimer;
//	if ( 0xffffffff - cnt < (uint32_t)ms*4 ){
//		cnt = 0;
//		ms -= (0xffffffff - cnt)*4;
//	}
//	while((volatile uint32_t)tm32_systemTimer < cnt + ms*4){}

	volatile int cnt=0;
	int i, tm;
	tm = 10000*ms;
	for ( i=0; i<tm; i++ ){
		cnt += 1;
	}
}
void initSPI(void)
{
	SPI_Start();

	ss(SS_DISABLE);
	// change to 3.3V for reading value
	//writeSingle(0x1d, 1);
}
void initSD1( void )
{
	//	1.	powerOnReset( void );
	RST_N_Write(0);

	//	2. wait 100usec
	delayMs(1);

	//	3.	RST_N : high
	RST_N_Write(1);

	//	4.	DRV_SEL	: low
	writeSingle(29, 0);  //  5v

	//	5.	AP0 : 0
	writeSingle(2, 0x0e);

	//	6.	wait for Quarz stability
	delayMs(1);

	//	7.	CLKE : "1"
	writeSingle(0, 0x01);

	//	8.	ALRST : low
	writeSingle(1, 0x00);

	//	9.	SFTRST	:	0xa3
	writeSingle(26, 0xa3);
	delayMs(1);

	//	10.	SFTRST	:	0x00
	writeSingle(26, 0x00);

	//	11.	wait 30msec
	delayMs(30);

	//	12.	AP1 AP3: "0"
	writeSingle(2, 0x04);

	//	13.	wait 10usec
	delayMs(1);

	//	14.	AP2: "0"
	writeSingle(2, 0x00);

	writeSingle(25, 0x81);	//	-18[dB]
	writeSingle(27, 0x3f);	//	set itp max
	writeSingle(20, 0x00);	//	set itp on
	writeSingle(3, 0x01);	//	amp gain(6.5[dB])
	writeSingle(9, 0xcc);	//	0[dB] Sequencer Volume
}
void powerDown( void )
{
	//	1.	damp

	//	2.	mute

	//	3.	AP3,2,1: "0"
    writeSingle(2,0x01);

	//	4.	ALRST: "1"
    writeSingle(1,0x80);

	//	5.	CLKE: "0"
    writeSingle(0,0x00);
}