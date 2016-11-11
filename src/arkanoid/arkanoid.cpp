
#include "arkanoid.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

// TEMPORARY: MIGHT CHANGE IT LATER --> READ FROM INPUT FILE
namespace SCREEN {
	const string NAME("Arkanoid");
	const int WIDTH(800);
	const int HEIGHT(600);
}
// ---

Arkanoid::Arkanoid() : window(sf::VideoMode(SCREEN::WIDTH, SCREEN::HEIGHT), SCREEN::NAME) {}

void Arkanoid::run() {
	while(window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {

			if(event.type == sf::Event::KeyPressed) {

				if(event.key.code == sf::Keyboard::Left) {
					// move player to left
				} else if(event.key.code == sf::Keyboard::Right) {
					// move player to right
				}

			}

			if(event.type == sf::Event::Closed) {
				window.close();
			}

		}
	}
}