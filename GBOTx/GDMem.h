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
	bool isDead();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

	// Gamemodes
	bool isWave();

private:
	DWORD procID;
	HANDLE handle;
	const WCHAR* name = L"GeometryDash.exe";
	uintptr_t base;
	struct memRef ref = {base};
};

