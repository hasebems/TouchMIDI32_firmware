/* ========================================
 *
 *	tm32_hcb4_dle.h
 *		description: DLE Class for HCB4
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include <stdbool.h>
#include <stdint.h>

//---------------------------------------------------------
//			Macros
//---------------------------------------------------------
#define		DOREMI_MAX			12
#define		VOLUME_ARRAY_MAX	4	//	number of Max Color

/*	_count	*/
#define		SEG_NOT_USE				(-2)
#define		SEG_IN_TOUCH			(-1)
#define		SEG_DECAY				0
/*-------------------------------------------------------*/
typedef struct {
	int			_count;						//	decay count
	uint16_t	_orgColor[VOLUME_ARRAY_MAX];
	uint16_t*	_colorArrayPtr;				//	Pointer to colorArray[]
	uint8_t		_doremi;						//
} DLE;
/*-------------------------------------------------------*/
int DLE_getSegment( DLE* this );
void DLE_init( DLE* this );
void DLE_on( DLE* this, uint16_t* ptr, uint8_t doremi );
void DLE_off( DLE* this );
bool DLE_count( DLE* this );

/* [] END OF FILE */
