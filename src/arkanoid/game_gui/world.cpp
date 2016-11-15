
#include "world.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	World::World(shared_ptr<Transformation> transform, shared_ptr<Game::Window> w, shared_ptr<Game::Grid> gr) :
	window(w), grid(gr),
	transformation(transform),
	player(4, 1, "sprites/player/player.png", transformation) {

		// TBI: create Walls on sides
		for(int w = 0; w < 9; w++) {
			// Remark: std::make_unique() not supported in c++11
			{
				unique_ptr<WallSFML> wall(new WallSFML(0, w, "sprites/wall/wall.png", transformation));
				walls.push_back(std::move(wall));
			}
			{
				unique_ptr<WallSFML> wall(new WallSFML(8, w, "sprites/wall/wall.png", transformation));
				walls.push_back(std::move(wall));
			}
		}
		for(int w = 1; w < 8; w++) {
			// Remark: std::make_unique() not supported in c++11
			unique_ptr<WallSFML> wall(new WallSFML(w, 0, "sprites/wall/wall.png", transformation));
			walls.push_back(std::move(wall));
		}
	}


	void World::drawAll(sf::RenderWindow &window) {
		window.clear();
		window.draw(player.sprite);
		for(int w = 0; w < walls.size(); w++) {
			window.draw(walls[w]->sprite);
		}
		window.display();
	}


}