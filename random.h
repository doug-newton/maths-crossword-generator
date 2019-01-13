#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>

/*	Can generate random numbers.
 */

class Random {

	public:
		void setSeed(int seed);
		int randomInt(int min,int max);
};

#endif
