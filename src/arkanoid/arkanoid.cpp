/// \file arkanoid.cpp

#include "arkanoid.h"
#include "gui/math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

const sf::Time TIME_PER_FRAME = sf::seconds(1.0/60.0);

Arkanoid::Arkanoid() : 
windowSFML(sf::VideoMode(896.0, 704.0), "arkanoid"), factory(windowSFML) {

	// Create singleton Transformation first instance
	transformation = transformation->getInstance(9, 7, windowSFML.getSize().x, windowSFML.getSize().y);

	windowSFML.setFramerateLimit(60);

	// Create background
	if(!texture.loadFromFile("data/sprites/background/background.png")) {
		throw runtime_error("Couldn't load background texture image: data/sprites/background/background.jpg");
	}
	texture.setSmooth(true);
	texture.setRepeated(true);		// Repeat background texture, so that it fits the screen
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0, 0, windowSFML.getSize().x, windowSFML.getSize().y));
}

void Arkanoid::initialise() {
	// Create Player
	world.setPlayer(std::move(factory.createPlayer()));

	// Create Ball
	world.setBall(std::move(factory.createBall()));

	// Create Walls
	vector<unique_ptr<arkanoid::Wall>> walls = std::move(factory.createWalls());
	for(auto &w: walls) {
		world.addWall(std::move(w));
	}
}

void Arkanoid::loadLevel(int level) {
	// Create Blocks
	try {
		vector<unique_ptr<arkanoid::Block>> blocks = std::move(factory.createBlocks("data/levels/level_" + to_string(level) + "/blocks.json"));
		for(auto &b: blocks) {
			world.addBlock(std::move(b));
		}
	} catch(...) {
		throw runtime_error("Cannot find level " + to_string(level));
	}
}

void Arkanoid::run(int level) {
	currentLevel = level;

	// Create game entities and load first level
	initialise();
	loadLevel(currentLevel);

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(windowSFML.isOpen()) {

		sf::Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;

		while(timeSinceLastUpdate > TIME_PER_FRAME) {
			processInput();
			if(!world.levelEnded()) {
				world.update();
			} else {
				// Level ended --> load next level
				currentLevel++;
				try {
					loadLevel(currentLevel);
				} catch(...) {
					// No more levels available --> end game
					windowSFML.close();
					cout << "Congratulations, you beat the game! \\(^o^)/" << endl;
					return;
				}
				world.reset();
			}
			timeSinceLastUpdate -= TIME_PER_FRAME;
		}

		render();
	}
}

void Arkanoid::processInput() {
	sf::Event event;
	while(windowSFML.pollEvent(event)) {

		// Reset world (if game happen to bug out)
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			world.reset();
		}

		if(event.type == sf::Event::Closed) {
			windowSFML.close();
		}
	}
}

void Arkanoid::render() {
	windowSFML.clear();
	windowSFML.draw(background);
	world.draw();
	windowSFML.display();
}
