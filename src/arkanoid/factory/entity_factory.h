#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_logic/entity/block/block.h"
#include "../game_gui/math/transformation.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/// Abstract Factory: Creates Entity.
class EntityFactory {
public:

	/**
	* Creates the Player.
	*
	* @return The Player.
	*/
	virtual unique_ptr<arkanoid::Player> createPlayer() = 0;

	/**
	* Creates all the Wall.
	*
	* @return List of all the Wall.
	*/
	virtual vector<unique_ptr<arkanoid::Wall>> createWalls() = 0;

	/**
	* Creates all the Block.
	*
	* @param file	The file where all the Block are specified.
	*
	* @return List of all the Block.
	*/
	virtual vector<unique_ptr<arkanoid::Block>> createBlocks(const string &file) = 0;

	/**
	* Creates the Ball.
	*
	* @return The Ball.
	*/
	virtual unique_ptr<arkanoid::Ball> createBall() = 0;

};

#endif /* ENTITY_FACTORY_H */