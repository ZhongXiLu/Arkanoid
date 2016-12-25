/// \file sfml_factory.h

#ifndef SFML_FACTORY_H
#define SFML_FACTORY_H

#include "entity_factory.h"
#include "../logic/entity/player/player.h"
#include "../logic/entity/ball/ball.h"
#include "../logic/entity/wall/wall.h"
#include "../logic/entity/block/block.h"

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
	* Creates the arkanoidSFML::PlayerSFML.
	*
	* @return The arkanoidSFML::PlayerSFML.
	*/
	unique_ptr<arkanoid::Player> createPlayer();

	/**
	* Creates all the arkanoidSFML::WallSFML.
	*
	* @return List of all the arkanoidSFML::WallSFML.
	*/
	vector<unique_ptr<arkanoid::Wall>> createWalls();

	/**
	* Creates all the arkanoidSFML::BlockSFML.
	*
	* @param file	The file where all the arkanoidSFML::BlockSFML are specified.
	*
	* @return List of all the arkanoidSFML::BlockSFML.
	*/
	vector<unique_ptr<arkanoid::Block>> createBlocks(const string &file);

	/**
	* Creates the arkanoidSFML::BallSFML.
	*
	* @return The arkanoidSFML::BallSFML.
	*/
	unique_ptr<arkanoid::Ball> createBall();
};

#endif /* SFML_FACTORY_H */