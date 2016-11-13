#ifndef ARKANOID_H
#define ARKANOID_H

#include "game_gui/world.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	// Game window and grid
	string windowName;	///< The title of the game window.
	int windowWidth;	///< The width of the game window.
	int windowHeight;	///< The height of the game window.
	int gridWidth;		///< The width of the grid.
	int gridHeight;		///< The height of the grid.

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