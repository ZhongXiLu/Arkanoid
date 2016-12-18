/// \file entity_factory.h

#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_logic/entity/block/block.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/// Abstract Factory: Creates arkanoid::Entity.
class EntityFactory {
public:

	/**
	* Creates the arkanoid::Player.
	*
	* @return The arkanoid::Player.
	*/
	virtual unique_ptr<arkanoid::Player> createPlayer() = 0;

	/**
	* Creates all the arkanoid::Wall.
	*
	* @return List of all the arkanoid::Wall.
	*/
	virtual vector<unique_ptr<arkanoid::Wall>> createWalls() = 0;

	/**
	* Creates all the arkanoid::Block.
	*
	* @param file	The file where all the arkanoid::Block are specified.
	*
	* @return List of all the arkanoid::Block.
	*/
	virtual vector<unique_ptr<arkanoid::Block>> createBlocks(const string &file) = 0;

	/**
	* Creates the arkanoid::Ball.
	*
	* @return The arkanoid::Ball.
	*/
	virtual unique_ptr<arkanoid::Ball> createBall() = 0;

};

#endif /* ENTITY_FACTORY_H */