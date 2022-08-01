#pragma once
#include "proc.h"
#include "memRef.h"



class GDMem
{
public:
	GDMem();
	~GDMem() {};

	// base addy

	void initBase(); 
	void initPlayer();

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

