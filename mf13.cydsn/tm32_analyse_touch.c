/* 
 * File:   analyse_touch.c
 * Author: jca03205
 * 
 * Created on 2014/12/21, 0:05
 */

#include "tm32_analyse_touch.h"


//-------------------------------------------------------------------------
static uint8_t     _lastTouch;
static uint8_t     _crntTouch;
static uint8_t     _tapTouch;
static uint8_t     _lastNote;

//  Time Measurement
static long        _startTime;  //  !=0 means during deadBand
static int         _deadBand;


//-------------------------------------------------------------------------
//  Adjustable Value
#define     DEADBAND_POINT_TIME     5      //  ×10[msec]
//-------------------------------------------------------------------------
#define     OCT_SW      0x30
#define     CRO_SW      0x08
#define     SX_SW       0x07
#define     ALL_SW      (OCT_SW|CRO_SW|SX_SW)
#define     TAP_FLAG    0x80
//-------------------------------------------------------------------------
const unsigned char tSwTable[64] = {

//   ooo   oox   oxo   oxx   xoo   xox   xxo   xxx  right hand
//  do(hi) so    fa    la    mi    ti    re    do
    0x24, 0x1f, 0x1d, 0x21, 0x1c, 0x23, 0x1a, 0x18,     //  ooo left hand
    0x25, 0x20, 0x1e, 0x20, 0x1b, 0x22, 0x1b, 0x19,     //  oox
    0x18, 0x13, 0x11, 0x15, 0x10, 0x17, 0x0e, 0x0c,     //  oxo
    0x19, 0x14, 0x12, 0x14, 0x0f, 0x16, 0x0f, 0x0d,     //  oxx
    0x18, 0x13, 0x11, 0x15, 0x10, 0x17, 0x0e, 0x0c,     //  xoo
    0x19, 0x14, 0x12, 0x14, 0x0f, 0x16, 0x0f, 0x0d,     //  xox
    0x0c, 0x07, 0x05, 0x09, 0x04, 0x0b, 0x02, 0x00,     //  xxo
    0x0d, 0x08, 0x06, 0x08, 0x03, 0x0a, 0x03, 0x01      //  xxx
};

//-------------------------------------------------------------------------
void AnalyseTouch_init( void )
{
	_lastTouch		=	0;
	_crntTouch		=	0;
	_tapTouch		=	0;
	_lastNote		=	0x24;    //  any touch senser isn't on
	_startTime		=	0;
	_deadBand		=	0;
}
//-------------------------------------------------------------------------
void AnalyseTouch_setNewTouch( uint8_t tch ){ _crntTouch = tch;}
//-------------------------------------------------------------------------
static uint8_t getNewNote( void )
{
    _lastNote = tSwTable[_crntTouch];
    _tapTouch = 0;
    _startTime = 0;
    _deadBand = 0;

    return _lastNote+60;
}
//-------------------------------------------------------------------------
bool AnalyseTouch_catchEventOfPeriodic( uint8_t* midiValue, long crntTime )
{
    bool    ret = false;
    *midiValue = _lastNote;

    if ( _crntTouch == _lastTouch ){
        if ( _deadBand > 0 ){
            if ( _startTime != 0 ){
                if ( crntTime-_startTime > DEADBAND_POINT_TIME*_deadBand ){
                    //  KeyOn
                    *midiValue = getNewNote();
                    ret = true;
                }
            }
        }
    }

    else {
        if ((_deadBand > 0) && (_tapTouch&TAP_FLAG) && ((_tapTouch&ALL_SW) == _crntTouch)){
            //  KeyOn
            //if (_dbg) _dbg->printf("<<Tapped>>\n");
            *midiValue = getNewNote();
            ret = true;
        }

        else {
            int diff;
            uint8_t newNote = tSwTable[_crntTouch & ALL_SW];

            if ( newNote > _lastNote ) diff = newNote - _lastNote;
            else diff = _lastNote - newNote;

            if ( diff >= 12 ){
                _startTime = crntTime;
                _deadBand = 3;
                if ((_crntTouch^_lastTouch)&_crntTouch){
                    //if (_dbg) _dbg->printf("<<Set Tap>>\n");
                    _tapTouch = _lastTouch|TAP_FLAG;
                }
            }
            else if ( diff >= 9 ){
                // 9 - 11
                _startTime = crntTime;
                _deadBand = 2;
            }
            else if ( diff >= 3 ){
                // 3 - 8
                _startTime = crntTime;
                _deadBand = 1;
            }
            else {
                // 0 - 2
                *midiValue = getNewNote();
                ret = true;
            }
        }

        //  update lastSwData
        _lastTouch = _crntTouch;
    }

    return ret;
}
