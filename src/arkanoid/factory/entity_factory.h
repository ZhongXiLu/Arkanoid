#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_gui/math/transformation.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/// Abstract Factory: Creates Entity.
class EntityFactory {
public:

	/**
	* Creates a Player.
	*/
	virtual unique_ptr<arkanoid::Player> createPlayer() = 0;

	/**
	* Create a Wall.
	*/
	virtual vector<unique_ptr<arkanoid::Wall>> createWalls() = 0;


	/**
	* Create a Ball.
	*/
	virtual unique_ptr<arkanoid::Ball> createBall() = 0;

};

#endif /* ENTITY_FACTORY_H */