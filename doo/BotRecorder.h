#pragma once
#include "GDMem.h"
#include <unordered_map>
#include <utility>	
#include <math.h>
#include <Windows.h>

using namespace std;
class BotRecorder
{
public:
	BotRecorder(GDMem* GDBOT){
		GD = GDBOT;
	}

	// Macro Recorders
	void waveBotRecorder(bool isWave);
	void reset();

private:

	// create a vector to store all the spots where the player is alive 
	// allows us to keep going back if the player is trapped. 

	vector<pair<float, float>> aliveSpots = {};
	pair<float, float> lastAlive = { 0.0F,0.0F };
	size_t wavePortalIndex = 0;
	size_t  shipPortalIndex = 0;
	size_t  UFOPortalIndex = 0;
	size_t  ballPortalIndex = 0;
	size_t  robotPortalIndex = 0;
	size_t spiderPortalIndex = 0;
	GDMem* GD;
	// record the clicks 

	// wave: true == hold, false == dont hold
	/*Outter vector stores the vector for EACH portal 
	* those vectors for each portal within the outer vector
	* store pairs where the first paramater is whether or not to click
	* and the second parameter is the coordinates 
	*/
	
	// forbidden coords 
	vector<pair<float, float>> forbidden = {};

	// wave
	pair<float, float> currWPortalCoords = { 0.0F,0.0F };
	pair<float, float> lastWaveRunCoords = { 0.0F,0.0F };
	vector<vector<pair<bool,pair<float,float>>>> waveMacros = {};
	bool wasWave = false;
};

