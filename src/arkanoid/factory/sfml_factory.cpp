
#include "sfml_factory.h"
#include "../game_gui/entity_sfml/player_sfml/player_sfml.h"
#include "../game_gui/entity_sfml/ball_sfml/ball_sfml.h"
#include "../game_gui/entity_sfml/wall_sfml/wall_sfml.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

SFMLFactory::SFMLFactory(sf::RenderWindow &window) : windowSFML(window) {}

// TBI: read data from file?

arkanoid::Player* SFMLFactory::createPlayer(shared_ptr<arkanoidSFML::Transformation> transform) {
	arkanoidSFML::PlayerSFML* player = new arkanoidSFML::PlayerSFML(4, 1, 10, windowSFML, "sprites/player/player.png", transform);

	return player;
}

vector<arkanoid::Wall*> SFMLFactory::createWalls(shared_ptr<arkanoidSFML::Transformation> transform) {

	vector<arkanoid::Wall*> walls;

	for(double w = 0.0; w < 27.0; w++) {
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(0.0, w/3, windowSFML, "sprites/wall/wall.png", transform);
			walls.push_back(wall);
		}
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(8.666, w/3, windowSFML, "sprites/wall/wall.png", transform);
			walls.push_back(wall);
		}
	}
	for(double w = 1; w < 27.0; w++) {
		arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(w/3, 0.0, windowSFML, "sprites/wall/wall.png", transform);
		walls.push_back(wall);
	}

	return walls;
}

arkanoid::Ball* SFMLFactory::createBall(shared_ptr<arkanoidSFML::Transformation> transform) {
	arkanoidSFML::BallSFML* ball = new arkanoidSFML::BallSFML(4, 4, 8, windowSFML, "sprites/ball/ball.png", transform);

	return ball;
}