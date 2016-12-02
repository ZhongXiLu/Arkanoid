
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
windowSFML(sf::VideoMode(900.0, 700.0), "arkanoid"),
transformation(make_shared<arkanoidSFML::Transformation>(9, 7, windowSFML.getSize().x, windowSFML.getSize().y)) {

	render();
	windowSFML.setFramerateLimit(60);
}

void Arkanoid::initialise() {
	SFMLFactory factory(windowSFML, transformation);

	// Create Player
	world.addEntity(factory.createPlayer());

	// Create Ball
	world.addEntity(factory.createBall());

	// Create Walls
	vector<arkanoid::Wall*> walls = factory.createWalls();
	for(auto &w: walls) {
		world.addEntity(w);
	}
}

void Arkanoid::run() {
	initialise();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(windowSFML.isOpen()) {

		sf::Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;

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

		if(event.type == sf::Event::Closed) {
			windowSFML.close();
		}
	}
}

void Arkanoid::render() {
	windowSFML.clear();
	world.draw();
	windowSFML.display();
}
