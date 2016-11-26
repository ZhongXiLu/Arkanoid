#ifndef SFML_FACTORY_H
#define SFML_FACTORY_H

#include "entity_factory.h"
#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_gui/math/transformation.h"
#include "../window/window.h"

#include <iostream>
#include <memory>

using namespace std;

/// Abstract Factory: Creates EntitySFML.
class SFMLFactory : public EntityFactory {
public:

	/**
	* Creates a PlayerSFML.
	*/
	arkanoid::Player* createPlayer(shared_ptr<arkanoidSFML::Transformation> transform, shared_ptr<Game::Window> window);

	/*
	* Create a WallSMFL.
	*/
	arkanoid::Wall* createWall(shared_ptr<arkanoidSFML::Transformation> transform);
};

#endif /* SFML_FACTORY_H */