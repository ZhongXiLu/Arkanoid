
#include "arkanoid.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

Arkanoid::Arkanoid() : window(sf::VideoMode(SCREEN::WIDTH, SCREEN::HEIGHT), SCREEN::NAME) {
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
				} else if(event.key.code == sf::Keyboard::Right) {
					world.player.moveRight();
				}

			}

			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}