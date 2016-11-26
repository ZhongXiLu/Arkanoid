
#include "sfml_factory.h"
#include "../game_gui/entity_sfml/player_sfml/player_sfml.h"
#include "../game_gui/entity_sfml/wall_sfml/wall_sfml.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

arkanoid::Player* SFMLFactory::createPlayer(shared_ptr<arkanoidSFML::Transformation> transform, shared_ptr<Game::Window> window) {
	arkanoidSFML::PlayerSFML* player = new arkanoidSFML::PlayerSFML(4, 1, "sprites/player/player.png", window, transform);

	return player;
}

arkanoid::Wall* SFMLFactory::createWall(shared_ptr<arkanoidSFML::Transformation> transform) {
	arkanoidSFML::WallSFML* wall = new arkanoidSFML::WallSFML(0, 0, "sprites/wall/wall.png", transform);

	return wall;
}
