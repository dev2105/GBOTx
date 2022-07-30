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

	// gamemodes
	uintptr_t wave;
};