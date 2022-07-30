#pragma once
#include "proc.h"
#include "memRef.h"

class GDMem
{
public:
	GDMem();
	~GDMem() {};

	// Basic
	void hold();
	void stopHold();
	void jump();
	int isDead();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

	// Gamemodes
	int isWave();

private:
	DWORD procID;
	HANDLE handle;
	const WCHAR* name = L"GeometryDash.exe";
	uintptr_t base = 0;
	memRef ref = memRef(base);
};

