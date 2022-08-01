#include "BotRecorder.h"

void BotRecorder::waveBotRecorder() {
	// wave: true == hold, false == dont hold
	/*Outter vector stores the vector for EACH portal 
	* those vectors for each portal within the outer vector
	* store pairs where the first paramater is whether or not to click
	* and the second parameter is the coordinates 
	*/
	if (GD->isWave()) {
		/*
		The idea:
		As soon as the player enters the portal, record the starting coords of the portal entry 
		If the player happens to die upon entry, then go back to the last alive position (set that as our startingCoords)
		and then hold from there (it is unheld by default)
		If a player dies somewhere else in the wave, set the startingCoords to the point where the player was last alive, and do the opposite action of what was happening. 
		If however, the startingCoords is where the player was last alive, then pop out that last alive point from the vector, set the startingCoords to the point where the 
		player was alive before that point. 


		*/
		bool hold  = false;

		// initalize a vector for this wave 
		// only do so if there isn't already a vector present
		if (waveMacros.size() < (wavePortalIndex + 1)) {
			waveMacros.push_back({});
		}


		// fill in portal entry 
		if (waveMacros[wavePortalIndex].size() == 0) {
			// save the starting coords of the current run (the coords of portal entry or the last alive coords if a death occurs)

			waveStartingCoords = { GD->getX(),GD->getY() };
			cout << waveStartingCoords.first << endl;
			waveMacros[wavePortalIndex].push_back({ false,waveStartingCoords });
		}

		if (!(GD->isDead())) {

			// store the latest spot where the player is still alive
			lastAlive = { GD->getX(),GD->getY() };
			aliveSpots.push_back(lastAlive);


		}

		// death case
		else {

			// if the death occurs upon portal entry
			if ((abs(waveMacros[wavePortalIndex][0].second.first - GD->getX() < 1.0e-15)) && (abs(waveMacros[wavePortalIndex][0].second.second - GD->getY()) < 1.0e-15)) {

				// if the wave portal is immedate death
				waveMacros[wavePortalIndex][0].first = true;
				hold = true;
			}

			// if death occurs anywhere else
			else {

				// firstly check if the lastAlive spot on top of our vector is the starting point (if it is then pop it)
				if ((abs(waveStartingCoords.first - lastAlive.first) < 1.0e-15) && (abs(waveStartingCoords.second == lastAlive.second) < 1.0e-15)) {
					aliveSpots.pop_back();
					lastAlive = aliveSpots[size(aliveSpots) - 1];

					// remove that point from our waveMacros vector, as there would be an entry for it since a different hold mode was used.
					waveMacros[wavePortalIndex].pop_back();
				}
				// switch the hold mode
				if (hold) {
					hold = false;
				}
				else {
					hold = true;
				}

				// store the new values of holding
				waveMacros[wavePortalIndex].push_back({ hold,{lastAlive.first,lastAlive.second } });

				// set the waveStartingCoords to the last alive
				waveStartingCoords.first = lastAlive.first;
				waveStartingCoords.second = lastAlive.second;

			}


			// set the x and y to the last alive coords
			GD->setX(lastAlive.first);
			GD->setY(lastAlive.second);

		}

		if (hold) {
			GD->hold();
		}
		else {
			GD->stopHold();
		}
		
	}

	
}

void BotRecorder::reset() {

	aliveSpots.clear();
	lastAlive = { 0,0 };
	wavePortalIndex = 0;
	shipPortalIndex = 0;
	UFOPortalIndex = 0;
	ballPortalIndex = 0;
	robotPortalIndex = 0;
	spiderPortalIndex = 0;

	waveStartingCoords = { 0,0 };
	waveMacros.clear();
}