#include "BotMain.h"

void BotMain::waveBotRecorder() {
	// wave: true == hold, false == dont hold
	/*Outter vector stores the vector for EACH portal 
	* those vectors for each portal within the outer vector
	* store pairs where the first paramater is whether or not to click
	* and the second parameter is the coordinates 
	*/
	if (GD->isWave()) {
		bool hold  = false;

		// initalize a vector for this wave 
		// only do so if there isn't already a vector present
		if (waveMacros.size() < (wavePortalIndex + 1)) {
			waveMacros.push_back({});
		}


		// fill in portal entry 
		if (waveMacros[wavePortalIndex].size() == 0) {

			// create the pointers t
			pair<bool, pair<float, float>> startClick;
			pair<float, float> start;


			waveMacros[wavePortalIndex].push_back({ false,{GD->getX(),GD->getY() } });
		}
		

		if (!(GD->isDead())) {

			// store the latest spot where the player is still alive
			lastAlive = { GD->getX(),GD->getY() };

		}
		else {

			if (waveMacros[wavePortalIndex][0].second.first == GD->getX()) {

				// if the wave portal is immedate death
				waveMacros[wavePortalIndex][0].first = true;
			}

			// store the area where you hold/unhold
			if (hold) {
				hold = false;
				GD->stopHold();
			}else{
				hold = true;
				GD->hold();
			}

			// store the new values of holding
			waveMacros[wavePortalIndex].push_back({ hold,{lastAlive.first,lastAlive.second } });

			// set the x and y to the last alive coords
			GD->setX(lastAlive.first);
			GD->setY(lastAlive.second);
		}
		
	}
}
