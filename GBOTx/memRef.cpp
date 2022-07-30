#include "memRef.h"

memRef::memRef(uintptr_t baseAddy) {
	base = baseAddy;
	hold = base + 0x11;
	death = base + 0x3F;
	x = base + 0x7C;
	y = base + 0x80;
	wave = base + 0x3B;
}