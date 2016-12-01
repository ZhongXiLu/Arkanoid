#ifndef ARKANOID_H
#define ARKANOID_H

#include "game_logic/world.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/// The actual game that can be run. Interacts with the Game Logic and the Game GUI.
class Arkanoid {
private:
	shared_ptr<arkanoidSFML::Transformation> transformation;	///< Transformation object for translations between coordinates and pixels.

	arkanoid::World world;
	sf::RenderWindow windowSFML;

	/**
	* Creates all Entity for the World.
	*/
	void initialise();

	/**
	* Checks for user input in the game window and process this input.
	*/
	void processInput();

	/**
	* Renders all the sprites of the World in the window.
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