
#include "arkanoid.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Arkanoid::Arkanoid() : window(VideoMode(800, 600), "Arkanoid") {}

void Arkanoid::run() {
	while(window.isOpen()) {
		Event event;

		while(window.pollEvent(event)) {

			if(event.type == Event::KeyPressed) {

				if(event.key.code == Keyboard::Left) {
					// move player to left
				} else if(event.key.code == Keyboard::Right) {
					// move player to right
				}

			}

			if(event.type == Event::Closed) {
				window.close();
			}

		}
	}
}