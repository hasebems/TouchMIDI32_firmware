/*
 * File:   analyse_touch.h
 * Author: jca03205
 *
 * Created on 2014/12/21, 0:05
 */

#ifndef ANALYSE_TOUCH_H
#define	ANALYSE_TOUCH_H

#include <stdbool.h>
#include <stdint.h>
//#include    "system.h"

extern void AnalyseTouch_init( void );
extern void AnalyseTouch_setNewTouch( uint8_t tch );
extern bool AnalyseTouch_catchEventOfPeriodic( uint8_t* midiValue, long crntTime );

#if 0
class analyse_touch {
public:
    analyse_touch() : _lastTouch(0), _crntTouch(0), _tapTouch(0),
                      _lastNote(0x24),    //  any touch senser isn't on
                      /*_dbg(0),*/ _startTime(0), _deadBand(0) {}

    analyse_touch(const analyse_touch& orig);
    virtual ~analyse_touch();

//    Touch( void ) : _lastTouch(0), _crntTouch(0), _tapTouch(0),
//                    _lastNote(0x24),    //  any touch senser isn't on
//                    _dbg(0), _startTime(0), _deadBand(0) {}

//    void setDebug( Debug* serial ){ _dbg = serial; }
    void setNewTouch( uint8_t tch ){ _lastTouch = _crntTouch; _crntTouch = tch;}

    uint8_t getNewNote( void );
    bool catchEventOfPeriodic( uint8_t& midiValue, long crntTime );

private:
    static const unsigned char tSwTable[64];

    uint8_t     _lastTouch;
    uint8_t     _crntTouch;
    uint8_t     _tapTouch;
    uint8_t     _lastNote;
//    Debug*      _dbg;

//  Time Measurement
    long        _startTime;  //  !=0 means during deadBand
    int         _deadBand;
};
#endif
#endif	/* ANALYSE_TOUCH_H */
