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
	// Needed to create Entity.
	sf::RenderWindow &windowSFML;
	shared_ptr<arkanoidSFML::Transformation> transform;

public:

	/**
	* Constructor.
	*
	* @param window				The SFML window.
	* @param transformation		Transformation object for translations between coordinates and pixels.
	*/
	SFMLFactory(sf::RenderWindow &window, shared_ptr<arkanoidSFML::Transformation> transformation);

	/**
	* Creates a PlayerSFML.
	*/
	arkanoid::Player* createPlayer();

	/**
	* Create a WallSMFL.
	*/
	vector<arkanoid::Wall*> createWalls();

	/**
	* Creates a BallSFML.
	*/
	arkanoid::Ball* createBall();
};

#endif /* SFML_FACTORY_H */