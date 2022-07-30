#include "BotRecorder.h"

using namespace std;

int main() {


	bool running = true;
	bool recording = false;
	bool wasRecording = false;
	string input = "";
	// make a pointer to GDMem
	GDMem* mem = new GDMem();
	BotRecorder recorder = BotRecorder(mem);
	
	while (running) {

		cin >> input;
		if ((input == "record") || (input == "Record")) {
			recording = true;
			// open level if there is a level, if there is no level then show error
			// enter practice mode 
			// 

			wasRecording = true;
		}

		while (recording) {

			// record wave macros
			recorder.waveBotRecorder();


			// exit loop upon level complete/practice complete

		}

		if (wasRecording) {
			// reset the recorder once its done recording
			recorder.reset();
			wasRecording = false;
		}

	}

	return 0;
}