/* 
 * File:   analyse_pressure.cpp
 * Author: jca03205
 * 
 * Created on 2014/12/21, 0:00
 */

#include "tm32_analyse_pressure.h"


//-------------------------------------------------------------------------
static int	_lastRawPressure;
static int	_currentStandard;
static int	_newProposedPressure;
static int	_samePressureCounter;
static uint8_t	_lastMidiValue;
static int	_afterStartCounter;

static void analyseStandardPressure( int crntPrs );
static uint8_t interpolateMidiExp( uint8_t realExp );


//-------------------------------------------------------------------------
#define		MAX_EXP_WIDTH		200
#define		MIDI_EXP_ITP_STEP	16

#define     STABLE_COUNT        600		//	*5msec
#define     NOISE_WIDTH         1

#define		START_DEAD_BAND_TIME	400	// *5msec

//-------------------------------------------------------------------------
static const unsigned char tExpValue[MAX_EXP_WIDTH+1] = {

0,0,0,0,0,0,0,3,6,9,

12,15,18,20,22,24,25,27,29,31,
32,34,35,37,38,40,41,42,44,45,
46,47,48,50,51,52,53,54,55,56,
57,58,59,60,61,62,63,63,64,65,
66,67,68,68,69,70,71,71,72,73,
74,74,75,76,76,77,78,78,79,80,
80,81,82,82,83,83,84,85,85,86,
86,87,87,88,88,89,89,90,91,91,
92,92,93,93,94,94,94,95,95,96,

96,97,97,98,98,99,99,100,100,100,
101,101,102,102,102,103,103,104,104,104,
105,105,106,106,106,107,107,108,108,108,
109,109,109,110,110,110,111,111,111,112,
112,113,113,113,114,114,114,114,115,115,
115,116,116,116,117,117,117,118,118,118,
119,119,119,119,120,120,120,121,121,121,
121,122,122,122,123,123,123,123,124,124,
124,125,125,125,125,126,126,126,126,127,
127,127,127,127,127,127,127,127,127,127,127
};

//-------------------------------------------------------------------------
void AnalysePressure_Init( void )
{
	_lastRawPressure	=	0;
	_currentStandard	=	10000;
	_samePressureCounter	=	0;
	_lastMidiValue		=	0;
	_afterStartCounter	=	0;
}
//-------------------------------------------------------------------------
void AnalysePressure_setNewRawPressure( int prs ){ _lastRawPressure = prs;}
//-------------------------------------------------------------------------
bool AnalysePressure_catchEventOfPeriodic( uint8_t* midiValue )
{
    bool    ret = false;

    if ( _afterStartCounter < START_DEAD_BAND_TIME ){
        //  3sec. of the begining
        *midiValue = 0;
		_afterStartCounter++;
		_currentStandard = _lastRawPressure;
        return false;
    }

    int     currentPrs = _lastRawPressure;

    //  Analyse & Generate Standard Pressure
    analyseStandardPressure(currentPrs);

    //  Generate MIDI Value
    int diff = currentPrs - _currentStandard;
    if ( diff < 0 ) diff = 0;
    else if ( diff > MAX_EXP_WIDTH ) diff = MAX_EXP_WIDTH;
    uint8_t md = tExpValue[diff];
	uint8_t exp = _lastMidiValue;

    if ( md != _lastMidiValue ){
        //  interpolate MIDI value
        exp = interpolateMidiExp(md);
		_lastMidiValue = exp;
        ret = true;
    }

	//	output
	*midiValue = exp;
    return ret;
}
//-------------------------------------------------------------------------
static void analyseStandardPressure( int crntPrs )
{
	//	far from current standard (more than 1hPa)
	if (( _currentStandard+10 < crntPrs ) ||
		( _currentStandard-10 > crntPrs )){
        _samePressureCounter = 0;		
		return;
	}

	//  Analize Standard Pressure
    if (( _newProposedPressure+NOISE_WIDTH < crntPrs ) ||
        ( _newProposedPressure-NOISE_WIDTH > crntPrs )){
        _samePressureCounter = 0;
        _newProposedPressure = crntPrs;
    }
    else {
        _samePressureCounter++;
        if ( _samePressureCounter > STABLE_COUNT ){
            _samePressureCounter = 0;
            if ( _currentStandard != _newProposedPressure ){
                //if (_dbg) _dbg->printf("<<Change Standard Pressure=%d>>\n",_newProposedPressure);
                _currentStandard = _newProposedPressure;
            }
        }
    }
}
//-------------------------------------------------------------------------
static uint8_t interpolateMidiExp( uint8_t realExp )
{
    if ( realExp > _lastMidiValue ){
		if ( _lastMidiValue < 127 - MIDI_EXP_ITP_STEP ){
			if ( realExp > _lastMidiValue + MIDI_EXP_ITP_STEP )
				realExp = _lastMidiValue + MIDI_EXP_ITP_STEP;
		}
    }
    else {  // realExp < _lastMidiValue
        if ( _lastMidiValue > MIDI_EXP_ITP_STEP ){
            if ( realExp < _lastMidiValue - MIDI_EXP_ITP_STEP )
                realExp = _lastMidiValue - MIDI_EXP_ITP_STEP;
        }
    }
	//	never come when realExp == _lastMidiValue

	_lastMidiValue = realExp;
    return realExp;
}
