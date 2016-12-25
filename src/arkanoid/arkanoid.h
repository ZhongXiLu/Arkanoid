/// \file arkanoid.h

#ifndef ARKANOID_H
#define ARKANOID_H

#include "logic/world.h"
#include "gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/// The actual game that can be run. Interacts with the arkanoid and the arkanoidSFML.
class Arkanoid {
private:
	arkanoid::World world;
	arkanoidSFML::Transformation* transformation;	///< Transformation object for translations between coordinates and pixels.

	sf::RenderWindow windowSFML;
	sf::Sprite background;
	sf::Texture texture;	///< Texture of the background

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