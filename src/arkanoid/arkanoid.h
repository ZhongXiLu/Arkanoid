/// \file arkanoid.h

#ifndef ARKANOID_H
#define ARKANOID_H

#include "logic/world.h"
#include "factory/sfml_factory.h"
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
	SFMLFactory factory;
	int currentLevel;

	sf::RenderWindow windowSFML;
	sf::Sprite background;
	sf::Texture texture;	///< Texture of the background

	/**
	* Creates the arkanoid::Player, arkanoid::Ball and arkanoid::Wall for the arkanoid::World.
	*/
	void initialise();

	/**
	* Loads a level in the Arkanoid game (is done when a level is finished).
	* Basically, creates the arkanoid::Block for the arkanoid::World.
	*
	* @param level	The level that will be loaded and played.
	*/
	void loadLevel(int level);

	/**
	* Checks for user input in the game window and process this input.
	*/
	void processInput();

	/**
	* Renders all the sprites of the arkanoid::World in the window.
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
	*
	* @param level	(optional) The level the Arkanoid game will start with.
	*/
	void run(int level = 1);
};

#endif /* ARKANOID_H */