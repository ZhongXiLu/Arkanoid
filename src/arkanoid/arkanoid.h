#ifndef ARKANOID_H
#define ARKANOID_H

#include "game_gui/world.h"
#include "grid_window/grid.h"
#include "grid_window/window.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	// Game window and grid
	shared_ptr<Game::Window> window;
	shared_ptr<Game::Grid> grid;

	// Game Logic
	arkanoidSFML::World world;

	// Game GUI
	sf::RenderWindow windowSFML;

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