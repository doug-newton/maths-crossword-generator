#include "random.h"
#include <iostream>
#include <cassert>

void Random::setSeed(int seed) {
	srand(seed);
}

int Random::randomInt(int min,int max) {
	assert(max-min+1 > 0);
	return rand()%(max-min+1) + min;
}
