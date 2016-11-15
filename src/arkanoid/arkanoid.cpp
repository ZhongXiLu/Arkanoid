
#include "arkanoid.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// MIGHT CHANGE IT LATER --> READ FROM CONFIG FILE
Arkanoid::Arkanoid() : 
	window {"arkanoid", 800, 600}, grid {9, 7},
	windowSFML(sf::VideoMode(window.width, window.height), window.name),
	world(make_shared<arkanoidSFML::Transformation>(grid.width, grid.height, window.width, window.height)) {
	
	windowSFML.clear();
	windowSFML.draw(world.player.sprite);
	windowSFML.display();
}

void Arkanoid::run() {
	while(windowSFML.isOpen()) {
		sf::Event event;

		while(windowSFML.pollEvent(event)) {

			if(event.type == sf::Event::KeyPressed) {

				if(event.key.code == sf::Keyboard::Left) {
					world.player.moveLeft();
					windowSFML.clear();
					windowSFML.draw(world.player.sprite);
					windowSFML.display();
				} else if(event.key.code == sf::Keyboard::Right) {
					world.player.moveRight();
					windowSFML.clear();
					windowSFML.draw(world.player.sprite);
					windowSFML.display();
				}
			}

			if(event.type == sf::Event::Closed) {
				windowSFML.close();
			}
		}
	}
}