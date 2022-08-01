#include "memRef.h"

memRef::memRef(uintptr_t baseAddy) {
	base = baseAddy;
	hold = base + 0x11;
	death = base + 0x3F;
	x = base + 0x7C;
	y = base + 0x80;
	x2 = base + 0x4C;
	y2 = base + 0x50;
	wave = base + 0x3B;
}