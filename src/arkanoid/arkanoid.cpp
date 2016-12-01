
#include "arkanoid.h"
#include "factory/sfml_factory.h"
#include "game_gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

const sf::Time TIME_PER_FRAME = sf::seconds(1.0/60.0);

// MIGHT CHANGE IT LATER --> READ FROM CONFIG FILE
Arkanoid::Arkanoid() : 
grid(make_shared<Game::Grid>(9.0, 7.0)),
windowSFML(sf::VideoMode(900.0, 700.0), "arkanoid"),
transformation(make_shared<arkanoidSFML::Transformation>(grid->width, grid->height, windowSFML.getSize().x, windowSFML.getSize().y)) {

	render();	
	windowSFML.setFramerateLimit(60);
}

void Arkanoid::initialise() {
	SFMLFactory factory(windowSFML);

	// Create Player
	arkanoid::Player* player = factory.createPlayer(transformation);
	world.addEntity(player);
	world.player = player;

	// Create Ball
	world.addEntity(factory.createBall(transformation));

	// Create Walls
	vector<arkanoid::Wall*> walls = factory.createWalls(transformation);
	for(auto w: walls) {
		world.addEntity(w);
	}
}

void Arkanoid::run() {
	initialise();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(windowSFML.isOpen()) {
		windowSFML.clear();

		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while(timeSinceLastUpdate > TIME_PER_FRAME) {
			processInput();
			world.update();
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}

		render();
	}
}

void Arkanoid::processInput() {
	sf::Event event;
	while(windowSFML.pollEvent(event)) {

		// if(event.type == sf::Event::KeyPressed) {
		// 	if(event.key.code == sf::Keyboard::Left) {
		// 		world.player->move(-35.0, 0);
		// 	} else if(event.key.code == sf::Keyboard::Right) {
		// 		world.player->move(35.0, 0);
		// 	}
		// }

		if(event.type == sf::Event::Closed) {
			windowSFML.close();
		}
	}
}

void Arkanoid::render() {
	// world.update();
	windowSFML.display();
}