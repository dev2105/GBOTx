#pragma once
#include "Windows.h"
struct memRef {
	// basic
	uintptr_t base;
	uintptr_t hold = base + 0x11;
	uintptr_t death = base + 0x3F;

	// coordinates 
	uintptr_t x = base + 0x7C;
	uintptr_t y = base + 0x80;

	// gamemodes
	uintptr_t wave = base + 0x3B;
};