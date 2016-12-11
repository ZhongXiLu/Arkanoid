
#include "random.h"

#include <iostream>
#include <time.h>

using namespace std;

namespace arkanoid {

	// Initialise singleton with nullptr at start
	Random* Random::singleton = nullptr;

	Random::Random() {
		// Set random seed
		srand(time(NULL));
	}

	Random* Random::getInstance() {
		if(!singleton) {
			// Create instance
			singleton = new Random;
		}
		return singleton;
	}

	double Random::randomDouble(int from, int to) {
		return static_cast<double>((rand() % (to - from + 1)) + from);
	}

}