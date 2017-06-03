/* ========================================
 *
 *	tm32_hcb4_dle.c
 *		description: DLE Class for HCB4
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include	"tm32_hcb4_dle.h"

/*----------------------------------------------------------------------------*/
//
//      Decay Light Effect Class (DLE)
//
/*----------------------------------------------------------------------------*/
const unsigned short tLEDPattern[DOREMI_MAX][VOLUME_ARRAY_MAX] =
{
	//	R		B		G
		{2000,	0,		0,		2000},		//	C
		{1850,	0,		250,	2000},
		{1700,	0,		500,	2000},		//	D
		{1300,	0,		750,	2000},
		{1000,	0,		1000,	2000},		//	E
		{0,		0,		2000,	2000},		//	F
		{0,		1500,	1500,	2000},
		{0,		2000,	0,		2000},		//	G
		{200,	1800,	0,		2000},
		{500,	1500,	0,		2000},		//	A
		{800,	1000,	0,		2000},
		{1200,	300,	0,		2000}		//	B
};
/*----------------------------------------------------------------------------*/
#define		DECAY_COUNT_MAX			50		//	* 10msec
#define		START_DECAY_COUNT		15		//	* 10msec
#define		DECAY_COEF				10		//	* (COEF-1)/COEF

/*----------------------------------------------------------------------------*/
int DLE_getSegment( DLE* this ){ return this->_count; }
/*----------------------------------------------------------------------------*/
void DLE_init( DLE* this )
{
	int i;
	this->_count = SEG_NOT_USE;		//	decay count
	this->_colorArrayPtr = 0;		//	Pointer to colorArray[]
	this->_doremi = 0;
	for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
		this->_orgColor[i] = 0;
	}
}
/*----------------------------------------------------------------------------*/
void DLE_on( DLE* this, uint16_t* ptr, uint8_t doremi )
{
	int i;
	this->_count = SEG_IN_TOUCH;
	this->_colorArrayPtr = ptr;
	this->_doremi = doremi;
	while ( doremi >= DOREMI_MAX ){ doremi -= DOREMI_MAX; }
	for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
		*(this->_colorArrayPtr+i) = this->_orgColor[i] = tLEDPattern[doremi][i];
	}
}
/*----------------------------------------------------------------------------*/
void DLE_off( DLE* this )
{
	this->_count = SEG_DECAY;
}
/*----------------------------------------------------------------------------*/
bool DLE_count( DLE* this )
{
	int i;
	if ( this->_count >= SEG_DECAY ){
		this->_count++;
		if (( this->_count > START_DECAY_COUNT ) && ( this->_count < DECAY_COUNT_MAX )){
//			int dcy = this->_count - START_DECAY_COUNT;
			for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
				this->_orgColor[i] = (this->_orgColor[i]*(DECAY_COEF-1))/DECAY_COEF;
				*(this->_colorArrayPtr+i) = this->_orgColor[i];
			}
			return true;
		}
		else if ( this->_count >= DECAY_COUNT_MAX ){
			//	End of Decay
			for ( i=0; i<VOLUME_ARRAY_MAX; i++ ){
				*(this->_colorArrayPtr+i) = 0;
			}
			this->_count = SEG_NOT_USE;
			return true;
		}
	}
	return false;
}
/*----------------------------------------------------------------------------*/


/* [] END OF FILE */
