#ifndef ARKANOID_H
#define ARKANOID_H

#include "game_gui/world.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// TEMPORARY: MIGHT CHANGE IT LATER --> READ FROM INPUT FILE
namespace SCREEN {
	const string NAME("Arkanoid");
	const int WIDTH(800);
	const int HEIGHT(600);
}
namespace GRID {
	const int WIDTH(9);
	const int HEIGHT(7);
}
// ---

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	// Game Logic
	arkanoidSFML::World world;

	// Game GUI
	sf::RenderWindow window;

public:

	/**
	* Default Constructor.
	*
	* Creates a game window.
	*/
	Arkanoid();

	/**
	* Run the Arkanoid game until the user closes the window.
	*
	* Cycles through the game and checks for events each cycle, depending on this event the game will update all it's data.
	*/
	void run();
};

#endif /* ARKANOID_H */