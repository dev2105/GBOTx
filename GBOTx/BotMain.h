#pragma once
#include "GDMem.h"
#include <unordered_map>
#include <utility>	
#include <math.h>

using namespace std;
class BotMain
{
public:
	BotMain(GDMem* GDBOT){
		GD = GDBOT;
	}

	// Macro Recorders
	void waveBotRecorder();

private:

	// create a vector to store all the spots where the player is alive 
	// allows us to keep going back if the player is trapped. 

	vector<pair<float, float>> aliveSpots = {};
	pair<float, float> lastAlive = { 0,0 };
	unsigned int wavePortalIndex = 0;
	unsigned int shipPortalIndex = 0;
	unsigned int UFOPortalIndex = 0;
	unsigned int ballPortalIndex = 0;
	unsigned int robotPortalIndex = 0;
	unsigned int spiderPortalIndex = 0;
	GDMem* GD;
	// record the clicks 

	// wave: true == hold, false == dont hold
	/*Outter vector stores the vector for EACH portal 
	* those vectors for each portal within the outer vector
	* store pairs where the first paramater is whether or not to click
	* and the second parameter is the coordinates 
	*/

	// wave
	pair<double, double> waveStartingCoords = { 0,0 };
	vector<vector<pair<bool,pair<float,float>>>> waveMacros = {{}};
};

