#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_gui/math/transformation.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/// Abstract Factory: Creates Entity.
class EntityFactory {
public:

	/**
	* Creates a Player.
	*/
	virtual arkanoid::Player* createPlayer(shared_ptr<arkanoidSFML::Transformation> transform) = 0;

	/**
	* Create a Wall.
	*/
	virtual vector<arkanoid::Wall*> createWalls(shared_ptr<arkanoidSFML::Transformation> transform) = 0;


	/**
	* Create a Ball.
	*/
	virtual arkanoid::Ball* createBall(shared_ptr<arkanoidSFML::Transformation> transform) = 0;

};

#endif /* ENTITY_FACTORY_H */