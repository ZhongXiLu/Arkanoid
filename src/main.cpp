/// \file main.cpp

#include "arkanoid/arkanoid.h"

#include <iostream>
#include <string>

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
* 	<li><b>Spacebar</b>: shoot the ball after start game or after death</li>
* 	<li><b>Left arrow</b>: move the player to the left</li>
* 	<li><b>Right arrow</b>: move the player to the right</li>
* </ul>
*
*
* \section blocks Blocks
* <ul>
* 	<li><b>Blue block</b>: when hit, gets destroyed</li>
* 	<li><b>Yellow block</b>: when hit, gets destroyed + <b>speed up</b> the ball by factor two until player hits the ball or misses the ball</li>
* 	<li><b>Red block</b>: when hit, gets destroyed + make the ball <b>invisible</b> until player hits the ball or misses the ball</li>
* </ul>
*
* \section remarks Remarks
* <ul>
* 	<li>If the program is runned from a different place then in "bin", you should copy the "data" folder to the directory of the executable.</li>
* </ul>
*/
int main(int argc, char* argv[]) {

	try {

		Arkanoid arkanoid;

		// Start from level_1
		if(argc == 1) {
			arkanoid.run();

		// Jump to a level
		} else if(argc == 2) {
			try {
				string arg = string(argv[1]);
				if(arg.substr(0, 3) == "-l=") {
					int level;
					try {
						level = stoi(arg.substr(3, arg.size()-3));
					} catch(...) {
						throw runtime_error("Second argument should be \"-l=<level>\" (with <level> an int)");
					}
					arkanoid.run(level);
				} else {
				throw runtime_error("Second argument should be \"-l=<level>\" (with <level> an int)");
				}
			} catch(...) {
				throw;
			}

		} else {
			throw runtime_error("Unvalid arguments");
		}

	} catch(exception &e) {
		cout << "ERROR: " << e.what() << endl;
	}

	return 0;
}