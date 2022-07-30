#include "proc.h"
using namespace std;

DWORD getProcID(const char* name) {
	DWORD procID = 0;
	// Find the Window's name
	HWND Window = FindWindowA(NULL, name);

	if (!Window) {
		cout << "Unable to find window.\n";
		cout << "Press enter to continue.\n";
		// press enter to continue:
		cin.ignore();
		exit(-1);
	}

	else {
		// Returns the thread that was used to create the window and the procID variable is assigned
		// the identifier to the process (the PID).
		GetWindowThreadProcessId(Window, &procID);
	}

	return procID;
		
}

uintptr_t GetModuleBaseAddress(DWORD procID, const WCHAR* modName) {
	uintptr_t base = 0;

	// Take a snapshot of the modules in the current process
	HANDLE modSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procID);

	if (modSnap != INVALID_HANDLE_VALUE) {

		// initalize a structure to store all the modules in the snapshot
		tagMODULEENTRY32W modules;
		modules = { 0 };
		modules.dwSize = sizeof(MODULEENTRY32);


		// store the first module into modules 
		Module32First(modSnap, &modules);

		do {
			// Check if we found the module we are looking for 
			if (!wcscmp(modules.szModule, modName)) {

				base = (uintptr_t)modules.modBaseAddr;
				break;
			}

		} while (Module32Next(modSnap, &modules));

		CloseHandle(modSnap);

	}

	return base;

}
