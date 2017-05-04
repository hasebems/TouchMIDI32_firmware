/*
 * File:   analyse_pressure.h
 * Author: jca03205
 *
 * Created on 2014/12/21, 0:00
 */

#ifndef ANALYSE_PRESSURE_H
#define	ANALYSE_PRESSURE_H

#include <stdbool.h>
#include <stdint.h>
//#include    "system.h"

extern void AnalysePressure_Init( void );
extern void AnalysePressure_setNewRawPressure( int prs );
extern bool AnalysePressure_catchEventOfPeriodic( uint8_t* midiValue );

#if 0
class analyse_pressure {
public:
    analyse_pressure() :
        _lastRawPressure(0.0),
        _currentStandard(10000), _samePressureCounter(0),
        _lastMidiValue(0), _afterStartCounter(0)/*, _dbg(0)*/ {}
    analyse_pressure(const analyse_pressure& orig);
    virtual ~analyse_pressure();

//private:
//    AirPressure( void ) :
//        _lastRawPressure(0.0),
//        _currentStandard(10000), _samePressureCounter(0),
//        _lastMidiValue(0), _afterStartCounter(0), _dbg(0) {}

    void setNewRawPressure( float prs ){ _lastRawPressure = prs;}
//    void setDebug( Debug* serial ){ _dbg = serial; }
    bool catchEventOfPeriodic( uint8_t& midiValue );

private:
    void analyseStandardPressure( int crntPrs );
    uint8_t interpolateMidiExp( uint8_t realExp );

    static const int MAX_EXP_WIDTH = 200;
    static const int MIDI_EXP_ITP_STEP = 4;

    static const unsigned char tExpValue[MAX_EXP_WIDTH];

    float   _lastRawPressure;
    int     _currentStandard;
    int     _newProposedPressure;
    int     _samePressureCounter;
    uint8_t _lastMidiValue;
    int     _afterStartCounter;

//    Debug* _dbg;


};
#endif
#endif	/* ANALYSE_PRESSURE_H */
