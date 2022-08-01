#include "BotRecorder.h"
#include <stdlib.h>

using namespace std;

int main() {
	// firstly create a process of GDMem 
	GDMem* mem = new GDMem();

	// create a process of the bot recorder 
	BotRecorder rec = BotRecorder(mem);

	bool running = true;

	string mode = "";
	bool recording = false;
	uintptr_t base = mem->getBase();
	bool baseSet = false;

	// mode selection
	bool modeSelection = true;
	bool wasRecording = false;

	bool lvlOpen = true;



	while (running) {

		if (modeSelection) {
			cin >> mode;
		}

		if ((mode == "Record") || (mode == "record")) {
			recording = true;
			wasRecording = true;
			modeSelection = false;
		}

		if (!base) {
			if (recording) {
				base = mem->getBase();
				cout << "open the level to continue and press enter" << endl;
				baseSet = false;
				lvlOpen = false;
				cin.ignore();

			}
			  
		}

		if (!baseSet && base) {
			mem->setBase(base);
			baseSet = true;
			lvlOpen = true;
		}else {
			// check for recording mode 
			if (recording && lvlOpen) {
				//cout << mem->isDead() << endl;
				//cout << "Base address:" << mem->getBase() << endl;
				base = mem->getBase();
				if ((!base)) {
					cout << "recording failed because level was exited" << endl;
					recording = false;
					baseSet = false;
					lvlOpen = false;
					cin.ignore();
				}

				else {
					
					rec.waveBotRecorder(mem->isWave());

					// once recording is complete, exit the recording mode and exit to main menu, make 
					// base sert false. 
				}

			}
			
			// must run immediately after recordign stopped (hence why its not else if)
			if (wasRecording && !recording) {
				wasRecording = false;
				modeSelection = true;
				rec.reset();
			}
		}
		//cout << lvlOpen << endl;
		
	}

	return 0;
}