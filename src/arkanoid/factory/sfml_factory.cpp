
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

unique_ptr<arkanoid::Player> SFMLFactory::createPlayer() {
	unique_ptr<arkanoid::Player> player(new arkanoidSFML::PlayerSFML(400.0, 600.0, windowSFML, transform));
	return player;
}

vector<unique_ptr<arkanoid::Wall>> SFMLFactory::createWalls() {

	vector<unique_ptr<arkanoid::Wall>> walls;

	for(double w = 0.0; w < 700.0; w += 30.0) {
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(0.0, w, windowSFML, transform));
			walls.push_back(std::move(wall));
		}
		{
			unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(866.0, w, windowSFML, transform));
			walls.push_back(std::move(wall));
		}
	}
	for(double w = 0.0; w < 900.0; w += 30) {
		unique_ptr<arkanoid::Wall> wall(new arkanoidSFML::WallSFML(w, 0.0, windowSFML, transform));
		walls.push_back(std::move(wall));
	}

	return walls;
}

unique_ptr<arkanoid::Ball> SFMLFactory::createBall() {
	unique_ptr<arkanoid::Ball> ball(new arkanoidSFML::BallSFML(400.00, 580.0, windowSFML, transform));
	return ball;
}