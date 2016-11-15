
#include "arkanoid.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// MIGHT CHANGE IT LATER --> READ FROM CONFIG FILE
Arkanoid::Arkanoid() : 
	window(make_shared<Game::Window>("arkanoid", 900.0, 700.0)), grid(make_shared<Game::Grid>(9.0, 7.0)),
	windowSFML(sf::VideoMode(window->width, window->height), window->name),
	world(make_shared<arkanoidSFML::Transformation>(grid->width, grid->height, window->width, window->height), window, grid) {
	
	world.drawAll(windowSFML);
}

void Arkanoid::run() {
	while(windowSFML.isOpen()) {
		sf::Event event;

		while(windowSFML.pollEvent(event)) {

			if(event.type == sf::Event::KeyPressed) {

				if(event.key.code == sf::Keyboard::Left) {
					world.player.moveLeft();
					world.drawAll(windowSFML);
				} else if(event.key.code == sf::Keyboard::Right) {
					world.player.moveRight();
					world.drawAll(windowSFML);
				}
			}

			if(event.type == sf::Event::Closed) {
				windowSFML.close();
			}
		}
	}
}