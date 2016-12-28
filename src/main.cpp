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
* ./arkanoid <level_nr>
* \endcode
* <p>(optional) <level_nr>: The level the Arkanoid game will start with.</p>
*
* \section gameplay Gameplay
*
* <p>The goal of the game is to clear every block in the current level by hitting it with the Ball. (Note: some blocks have special effects) However, you should try to NOT let the ball hit the bottom of the screen by moving the paddle horizontally.</p>
* <p>If you manage to clear a level, the next level will be loaded. You beat the game if you can clear every level.</p>
* <p>Good luck and have fun!</p>
*
* \section controls Controls
* <ul>
* 	<li><b>Spacebar</b>: shoot the ball after start game or after death</li>
* 	<li><b>Left arrow</b>: move the player to the left</li>
* 	<li><b>Right arrow</b>: move the player to the right</li>
* 	<li><b>Escape</b>: ONLY press it if the game bugs out and is unplayable; resets player and ball</li>
* </ul>
*
*
* \section blocks Blocks
* <p>If multiple effects are activated, the first one will stay active and the second one will be discarded; if both are the same, the duration is reset.
* <ul>
* 	<li><b>Blue block</b>: when hit, gets destroyed (arkanoid::Block)</li>
* 	<li><b>Green block</b>: when hit, gets destroyed + speed up the player by factor 2 for 3 seconds (arkanoid::PlayerSpeedBlock)</li>
* 	<li><b>Yellow block</b>: when hit, gets destroyed + speed up the ball by factor 1.5 until player hits the ball or misses the ball (arkanoid::BallSpeedBlock)</li>
* 	<li><b>Purple block</b>: when hit, gets destroyed + slow down the ball by factor 0.5 until player hits the ball or misses the ball (arkanoid::BallSpeedBlock)</li>
* 	<li><b>Red block</b>: when hit, gets destroyed + make the ball invisible for 2 seconds (arkanoid::InvisBlock)</li>
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