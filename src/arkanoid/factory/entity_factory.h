#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_gui/math/transformation.h"

#include <iostream>
#include <vector>

using namespace std;

/// Abstract Factory: Creates Entity.
class EntityFactory {
public:

	/**
	* Creates a Player.
	*/
	virtual arkanoid::Player* createPlayer() = 0;

	/**
	* Create a Wall.
	*/
	virtual vector<arkanoid::Wall*> createWalls() = 0;


	/**
	* Create a Ball.
	*/
	virtual arkanoid::Ball* createBall() = 0;

};

#endif /* ENTITY_FACTORY_H */