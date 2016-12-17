#ifndef SFML_FACTORY_H
#define SFML_FACTORY_H

#include "entity_factory.h"
#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_logic/entity/block/block.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/// Factory: Creates EntitySFML.
class SFMLFactory : public EntityFactory {
private:
	// Needed to create Entity.
	sf::RenderWindow &windowSFML;

public:

	/**
	* Constructor.
	*
	* @param window				The SFML window.
	*/
	SFMLFactory(sf::RenderWindow &window);

	/**
	* Creates the PlayerSFML.
	*
	* @return The PlayerSFML.
	*/
	shared_ptr<arkanoid::Player> createPlayer();

	/**
	* Creates all the WallSMFL.
	*
	* @return List of all the WallSMFL.
	*/
	vector<shared_ptr<arkanoid::Wall>> createWalls();

	/**
	* Creates all the BlockSMFL.
	*
	* @param file	The file where all the BlockSMFL are specified.
	*
	* @return List of all the BlockSMFL.
	*/
	vector<shared_ptr<arkanoid::Block>> createBlocks(const string &file);

	/**
	* Creates the BallSFML.
	*
	* @return The BallSFML.
	*/
	shared_ptr<arkanoid::Ball> createBall();
};

#endif /* SFML_FACTORY_H */