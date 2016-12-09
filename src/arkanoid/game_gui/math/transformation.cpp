
#include "transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

using namespace std;

namespace arkanoidSFML {

	// Initialise singleton with nullptr at start
	Transformation* Transformation::singleton = nullptr;

	Transformation::Transformation() {}

	Transformation::Transformation(double gridWidth, double gridHeight, double windowWidth, double windowHeight)
	: widthScale(windowWidth/gridWidth), heightScale(windowHeight/gridHeight) {}

	Transformation* Transformation::getInstance() {
		if(!singleton) {
			// Create instance
			singleton = new Transformation;
		}
		return singleton;
	}

	Transformation* Transformation::getInstance(double gridWidth, double gridHeight, double windowWidth, double windowHeight) {
		if(!singleton) {
			// Create instance
			singleton = new Transformation(gridWidth, gridHeight, windowWidth, windowHeight);
		}
		return singleton;
	}

	arkanoid::Vector2D Transformation::convertVector(const sf::Vector2f &vector) {
		return arkanoid::Vector2D(vector.x / widthScale, vector.y / heightScale);
	}

	double Transformation::convertX(double x) {
		return x / widthScale;
	}

	double Transformation::convertY(double y) {
		return  y / heightScale;
	}

}