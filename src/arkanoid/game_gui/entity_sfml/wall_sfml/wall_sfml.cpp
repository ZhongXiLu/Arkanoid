
#include "wall_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	WallSFML::WallSFML() {
		sprite.setOrigin(50, 0);
		sprite.setPosition(0, 0);
		transformation = nullptr;
	}

	WallSFML::WallSFML(double x, double y, const string &textureFile, shared_ptr<Transformation> transform) : transformation(transform), Wall(x, y) {

		if(!texture.loadFromFile(textureFile)) {
			throw runtime_error("Couldn't load texture image.");
		}
		sprite.setTexture(texture);
		
		sprite.scale(3, 3);
		sprite.setPosition(x*100.0, y*100.0);		// TBI: Transformation: make other conversion (double scale)
	}

	WallSFML::~WallSFML() {}

	void WallSFML::update() {
		// ...
	}

}