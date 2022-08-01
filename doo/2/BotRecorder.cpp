#include "BotRecorder.h"


void BotRecorder::waveBotRecorder(bool isWave) {
	// wave: true == hold, false == dont hold
	/*Outter vector stores the vector for EACH portal 
	* those vectors for each portal within the outer vector
	* store pairs where the first paramater is whether or not to click
	* and the second parameter is the coordinates 
	*/
	bool inForbidden = false;
	bool sameCoords = false;
	bool isInit = false;
	if (!isInit && GD->isDead()) {

	}
	else if (isWave) {
		Sleep((1.0 / 60.0));
		/* Check if the directory for all wave macros has 1
		* less vector than the number of wave portals entered
		*/
		wasWave = true;
		sameCoords = false;
		inForbidden = false;
		if (waveMacros.size() < (wavePortalIndex + 1)) {

			isInit = true;
			currWPortalCoords = { GD->getX(), GD->getY() };
			vector<pair<bool, pair<float, float>>> temp = { {false,currWPortalCoords} };
			waveMacros.push_back(temp);
		}

		// check if the current coordinates are in the forbidden coords or not 
		for (auto i : forbidden) {
			if ((fabs(i.first - GD->getX()) <= 1.0e-10F) && (fabs(i.second - GD->getY()) <= 1.0e-15F)) {
				inForbidden = true;
				break;
			}

			
		}
		cout << "last alive: "<< lastAlive.first << wavePortalIndex << endl;
		cout << "last X: " << GD->getX() << wavePortalIndex << endl;
		cout << "forbidden: " << forbidden.size() << wavePortalIndex << endl;
		cout << "alive spots: " << aliveSpots.size() << wavePortalIndex << endl;
		// check if the current coordinates are already coords in last alive

	/*	if ((aliveSpots.size() > 0) && ((fabs(GD->getX() - aliveSpots[aliveSpots.size() - 1].first) < 1.0e-15F) && (fabs(GD->getY() - aliveSpots[aliveSpots.size() - 1].second) < 1.0e-15F))) {
			sameCoords = true;
		}*/

		for (auto j : aliveSpots) {
			if (((fabs(GD->getX() - j.first) <= 1.0e-15F) && (fabs(GD->getY() -j.second) <= 1.0e-15F))) {
				sameCoords = true;
				break;
			}

		}

		if ((!GD->isDead()) && (!inForbidden) && !sameCoords) {

			if (!(GD->getX() < lastAlive.first)) {
				lastAlive.first = GD->getX();
				lastAlive.second = GD->getY();
				aliveSpots.push_back(lastAlive);
			}
			
		}
		else if (GD->isDead()) {
			
			/* Check if the last alive point was attempted before. If it was,
			push it into forbidden. */
			if ((fabs(lastWaveRunCoords.first - lastAlive.first) <= 1.0e-15F)) {
				forbidden.push_back(lastAlive);

				// remove the entry from wave macros and lastAlive
				cout << "test1" << endl;
				if (aliveSpots.size() > 0) {
					aliveSpots.pop_back();
					lastAlive = aliveSpots[aliveSpots.size() - 1];
				}
				
				if (waveMacros[waveMacros.size() - 1].size() > 1) {
					waveMacros[waveMacros.size() - 1].pop_back();
				}
			
			}

			if (waveMacros[waveMacros.size() - 1][waveMacros[waveMacros.size() - 1].size() - 1].first) {
				waveMacros[waveMacros.size() - 1].push_back({ false,lastAlive });
			}
			else {
				waveMacros[waveMacros.size() - 1].push_back({ true,lastAlive });
			}

			lastWaveRunCoords = lastAlive;

			while (GD->isDead()) {
				/*cout << "lol" << endl;*/
				// stops anymore actions from occuring if the player is dead still 
				if (!GD->isDead()) {
					cout << "test2" << endl;
					break;
				}
			}
			while ((fabs(GD->getX() - lastAlive.first) > 1.0e-15F) && (fabs(GD->getY() - lastAlive.second) > 1.0e-15F)) {

				GD->setX(lastAlive.first);
				GD->setY(lastAlive.second);

			}

		}

		while ((GD->getX()) < lastAlive.first) {
			GD->setX(lastAlive.first);
			GD->setY(lastAlive.second);
		}

		/*cout << waveMacros[waveMacros.size() - 1][waveMacros[waveMacros.size() - 1].size() - 1].first << endl;*/
		if (waveMacros[waveMacros.size() - 1][waveMacros[waveMacros.size() - 1].size() - 1].first) {
			GD->hold();
		}
		else {
			GD->stopHold();
		}
		
	}
	else if (wasWave && !isWave && !GD->isDead()) {
		//wavePortalIndex++;
		wasWave = false;
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
	lastWaveRunCoords = { 0,0 };
	currWPortalCoords = { 0,0 };
	waveMacros.clear();
	forbidden.clear();
}