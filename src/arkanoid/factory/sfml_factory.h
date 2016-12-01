#ifndef SFML_FACTORY_H
#define SFML_FACTORY_H

#include "entity_factory.h"
#include "../game_logic/entity/player/player.h"
#include "../game_logic/entity/ball/ball.h"
#include "../game_logic/entity/wall/wall.h"
#include "../game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/// Abstract Factory: Creates EntitySFML.
class SFMLFactory : public EntityFactory {
private:
	sf::RenderWindow &windowSFML;	///< Needed to create Entity.

public:

	/**
	* Constructor.
	*
	* @param window		The SFML window.
	*/
	SFMLFactory(sf::RenderWindow &window);

	/**
	* Creates a PlayerSFML.
	*/
	arkanoid::Player* createPlayer(shared_ptr<arkanoidSFML::Transformation> transform);

	/**
	* Create a WallSMFL.
	*/
	vector<arkanoid::Wall*> createWalls(shared_ptr<arkanoidSFML::Transformation> transform);

	/**
	* Creates a BallSFML.
	*/
	arkanoid::Ball* createBall(shared_ptr<arkanoidSFML::Transformation> transform);
};

#endif /* SFML_FACTORY_H */