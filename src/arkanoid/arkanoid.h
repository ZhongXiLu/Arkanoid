#ifndef ARKANOID_H
#define ARKANOID_H

#include "game_gui/world.h"
#include "field/grid.h"
#include "field/window.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	shared_ptr<Game::Window> window;
	shared_ptr<Game::Grid> grid;

	arkanoidSFML::World world;
	sf::RenderWindow windowSFML;

	/**
	* Check for user input in the game window and process this input.
	*/
	void processInput();

	/**
	* Render all the sprites of the World in the window.
	*/
	void render();

public:

	/**
	* Default Constructor.
	*
	* Creates a game window.
	*/
	Arkanoid();

	/**
	* Run the Arkanoid game until the user closes the window.
	*/
	void run();
};

#endif /* ARKANOID_H */