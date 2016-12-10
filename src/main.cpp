
#include "arkanoid/arkanoid.h"

#include <iostream>

/**
* \mainpage Arkanoid
*
* \section howToBuild How to build
*
* (in the project main directory)
*
* \code{.sh}
* mkdir build
* cd build
* cmake ..
* make install
* cd ../bin
* ./arkanoid
* \endcode
*
* \section howToRun How to run
*
* \code{.sh}
* ./arkanoid
* \endcode
*
* \section controls Controls
* <ul>
* 	<li>Spacebar: shoot the ball after start game or after death</li>
* 	<li>Left arrow: move the player to the left</li>
* 	<li>Right arrow: move the player to the right</li>
* </ul>
*
* \section remarks Remarks
* <ul>
* 	<li>The directory "sprites" (in the project main directory) should be copied to the same directory of the executable. (sprites are needed for the program to work)</li>
* </ul>
*/
int main() {

	try {

		Arkanoid arkanoid;
		arkanoid.run();

	} catch(exception &e) {
		cout << "ERROR: " << e.what() << endl;
	}

	return 0;
}