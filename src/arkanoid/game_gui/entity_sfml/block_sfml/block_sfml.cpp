
#include "block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	BlockSFML::BlockSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, const string &textureFile) : windowSFML(window), transformation(transform), Block(transform->convertX(x), transform->convertY(y)) {

		// Set texture
		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		// Set position
		sprite.setPosition(x, y);
		setPosition(std::move(transformation->convertVector(sprite.getPosition())));

		// Set size (width and height) of BlockSFML
		sf::FloatRect rect = sprite.getLocalBounds();
		setSize(make_pair(transform->convertX(rect.width), transform->convertY(rect.height)));
	}

	BlockSFML::~BlockSFML() {}

	void BlockSFML::update() {
		// ...
	}

	void BlockSFML::draw() const {
		windowSFML.draw(sprite);
	}

}