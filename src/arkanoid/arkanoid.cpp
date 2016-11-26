
#include "arkanoid.h"
#include "factory/sfml_factory.h"
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
transformation(make_shared<arkanoidSFML::Transformation>(grid->width, grid->height, window->width, window->height)) {

	render();	
	// world.drawAll(windowSFML);
	windowSFML.setFramerateLimit(30);
}

void Arkanoid::initialise() {
	SFMLFactory factory;

	world.addEntity(factory.createPlayer(transformation, window));

	// 	// TBI: create Walls on sides
	// 	for(int w = 0; w < 9; w++) {
	// 		// Remark: std::make_unique() not supported in c++11
	// 		{
	// 			unique_ptr<WallSFML> wall(new WallSFML(0, w, "sprites/wall/wall.png", transformation));
	// 			walls.push_back(std::move(wall));
	// 		}
	// 		{
	// 			unique_ptr<WallSFML> wall(new WallSFML(8, w, "sprites/wall/wall.png", transformation));
	// 			walls.push_back(std::move(wall));
	// 		}
	// 	}
	// 	for(int w = 1; w < 8; w++) {
	// 		// Remark: std::make_unique() not supported in c++11
	// 		unique_ptr<WallSFML> wall(new WallSFML(w, 0, "sprites/wall/wall.png", transformation));
	// 		walls.push_back(std::move(wall));
	// 	}
}

void Arkanoid::run() {
	initialise();

	// sf::Clock clock;

	while(windowSFML.isOpen()) {
		processInput();

		render();
		// cout << "Elapsed time: " << clock.getElapsedTime().asMicroseconds() << endl;
		// clock.restart();
	}
}

void Arkanoid::processInput() {
	sf::Event event;
	while(windowSFML.pollEvent(event)) {

		// if(event.type == sf::Event::KeyPressed) {

		// 	if(event.key.code == sf::Keyboard::Left) {
		// 		world.player.moveLeft();
		// 	} else if(event.key.code == sf::Keyboard::Right) {
		// 		world.player.moveRight();
		// 	}
		// }

		if(event.type == sf::Event::Closed) {
			windowSFML.close();
		}
	}
}

void Arkanoid::render() {
	windowSFML.clear();
	// world.drawAll(windowSFML);
	windowSFML.display();
}