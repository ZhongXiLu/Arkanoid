
#include "sfml_factory.h"
#include "../game_gui/entity_sfml/player_sfml/player_sfml.h"
#include "../game_gui/entity_sfml/wall_sfml/wall_sfml.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

SFMLFactory::SFMLFactory(sf::RenderWindow &window) : windowSFML(window) {}

// TBI: read data from file?

arkanoid::Player* SFMLFactory::createPlayer(shared_ptr<arkanoidSFML::Transformation> transform) {
	arkanoidSFML::PlayerSFML* player = new arkanoidSFML::PlayerSFML(4, 1, windowSFML, "sprites/player/player.png", transform);

	return player;
}

vector<arkanoid::Wall*> SFMLFactory::createWalls(shared_ptr<arkanoidSFML::Transformation> transform) {

	vector<arkanoid::Wall*> walls;

	// arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(0, 0, windowSFML, "sprites/wall/wall.png", transform);

	for(int w = 0; w < 9; w++) {
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(0, w, windowSFML, "sprites/wall/wall.png", transform);
			walls.push_back(wall);
		}
		{
			arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(8, w, windowSFML, "sprites/wall/wall.png", transform);
			walls.push_back(wall);
		}
	}
	for(int w = 1; w < 8; w++) {
		arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(w, 0, windowSFML, "sprites/wall/wall.png", transform);
		walls.push_back(wall);
	}

	return walls;
}
