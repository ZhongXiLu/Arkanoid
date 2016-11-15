
#include "arkanoid.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// MIGHT CHANGE IT LATER --> READ FROM CONFIG FILE
Arkanoid::Arkanoid() : 
	window {"arkanoid", 900.0, 700.0}, grid {9.0, 7.0},
	windowSFML(sf::VideoMode(window.width, window.height), window.name),
	world(make_shared<arkanoidSFML::Transformation>(grid.width, grid.height, window.width, window.height)) {
	
	// TBI: draw function
	windowSFML.clear();
	windowSFML.draw(world.player.sprite);
	for(int w = 0; w < world.walls.size(); w++) {
		windowSFML.draw(world.walls[w]->sprite);
	}
	windowSFML.display();
}

void Arkanoid::run() {
	while(windowSFML.isOpen()) {
		sf::Event event;

		while(windowSFML.pollEvent(event)) {

			if(event.type == sf::Event::KeyPressed) {

				if(event.key.code == sf::Keyboard::Left) {
					world.player.moveLeft();
					// TBI: draw function
					windowSFML.clear();
					windowSFML.draw(world.player.sprite);
					for(int w = 0; w < world.walls.size(); w++) {
						windowSFML.draw(world.walls[w]->sprite);
					}
					windowSFML.display();
				} else if(event.key.code == sf::Keyboard::Right) {
					world.player.moveRight();
					// TBI: draw function
					windowSFML.clear();
					windowSFML.draw(world.player.sprite);
					for(int w = 0; w < world.walls.size(); w++) {
						windowSFML.draw(world.walls[w]->sprite);
					}
					windowSFML.display();
				}
			}

			if(event.type == sf::Event::Closed) {
				windowSFML.close();
			}
		}
	}
}