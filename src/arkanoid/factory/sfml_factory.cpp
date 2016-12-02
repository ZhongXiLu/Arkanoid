
#include "sfml_factory.h"
#include "../game_gui/entity_sfml/player_sfml/player_sfml.h"
#include "../game_gui/entity_sfml/ball_sfml/ball_sfml.h"
#include "../game_gui/entity_sfml/wall_sfml/wall_sfml.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

SFMLFactory::SFMLFactory(sf::RenderWindow &window, shared_ptr<arkanoidSFML::Transformation> transformation) : windowSFML(window), transform(transformation) {}

// TBI: read data from file?

arkanoid::Player* SFMLFactory::createPlayer() {
	arkanoidSFML::PlayerSFML* player = new arkanoidSFML::PlayerSFML(400.0, 600.0, windowSFML, transform);
	return player;
}

vector<arkanoid::Wall*> SFMLFactory::createWalls() {

	vector<arkanoid::Wall*> walls;

	for(double w = 0.0; w < 700.0; w += 30.0) {
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(0.0, w, windowSFML, transform);
			walls.push_back(wall);
		}
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(866.0, w, windowSFML, transform);
			walls.push_back(wall);
		}
	}
	for(double w = 0.0; w < 900.0; w += 30) {
		arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(w, 0.0, windowSFML, transform);
		walls.push_back(wall);
	}

	return walls;
}

arkanoid::Ball* SFMLFactory::createBall() {
	arkanoidSFML::BallSFML* ball = new arkanoidSFML::BallSFML(400.00, 580.0, windowSFML, transform);
	return ball;
}