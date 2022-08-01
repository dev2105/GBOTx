#pragma once
#include "Windows.h"
class memRef {

	

public:
	memRef(uintptr_t baseAddy);
	// basic
	uintptr_t base;
	uintptr_t hold;
	uintptr_t death;

	// coordinates 
	uintptr_t x;
	uintptr_t y;
	uintptr_t x2;
	uintptr_t y2;

	// gamemodes
	uintptr_t wave;
};