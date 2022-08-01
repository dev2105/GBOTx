#pragma once
#include "proc.h"
#include "memRef.h"



class GDMem
{
public:
	GDMem();
	~GDMem() {};

	// base addy
	void setBase(uintptr_t baseAddy);

	uintptr_t getBase(); /* useful to check if level is loaded or not.
						 if no level is loaded then the value will be 0,
						 however if it is, then the value is greater than 0.
						 if the value happens to be 0, then setBase needs to be 
						 ran again.*/

	// Basic
	void hold();
	void stopHold();
	void jump();
	bool isDead();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void setDeath(bool isDead);
	// Gamemodes
	bool isWave();

	// set the base address 

private:

	HANDLE handle;
	DWORD procID;
	const WCHAR* name = L"GeometryDash.exe";
	uintptr_t base = 0;
	memRef ref = memRef(base);

	// backup of baseAddress
	uintptr_t baseBack = 0;
};

