#pragma once

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <TlHelp32.h>


DWORD getProcID(const char* name);

uintptr_t GetModuleBaseAddress(DWORD procID, const WCHAR* modName);