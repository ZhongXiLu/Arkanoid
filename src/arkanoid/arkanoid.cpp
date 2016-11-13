
#include "arkanoid.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// MIGHT CHANGE IT LATER --> READ FROM CONFIG FILE
Arkanoid::Arkanoid() : 
	windowName("Arkanoid"), windowWidth(800), windowHeight(600), gridWidth(9), gridHeight(7), 
	window(sf::VideoMode(windowWidth, windowHeight), "Arkanoid"),
	world(make_shared<arkanoidSFML::Transformation>(gridWidth, gridHeight, windowWidth, windowHeight)) {
	
	window.clear();
	window.draw(world.player.sprite);
	window.display();
}

void Arkanoid::run() {
	while(window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {

			if(event.type == sf::Event::KeyPressed) {

				if(event.key.code == sf::Keyboard::Left) {
					world.player.moveLeft();
					window.clear();
					window.draw(world.player.sprite);
					window.display();
				} else if(event.key.code == sf::Keyboard::Right) {
					world.player.moveRight();
					window.clear();
					window.draw(world.player.sprite);
					window.display();
				}
			}

			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}