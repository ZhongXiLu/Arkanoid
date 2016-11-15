#ifndef SCREEN_H
#define SCREEN_H

#include "../../game_logic/math/vector2D.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	/// This class provides a method to convert coordinates from the grid to the corresponding screen pixels.
	class Transformation {
	private:
		double widthScale;
		double heightScale;

		double maxWindowHeight;

	public:
		/**
		* Default Constructor.
		*
		* Sets all members to zero.
		*/
		Transformation();

		/**
		* Constructor.
		*
		* @param gridWidth		The width of the grid.
		* @param gridHeight		The height of the grid.
		* @param windowWidth	The width of the screen (game window).
		* @param windowHeight 	The height of the screen (game window).
		*/
		Transformation(double gridWidth, double gridHeight, double windowWidth, double windowHeight);

		/*
		* Converts coordinates (of the grid) to screen pixels.
		*
		* @param vector 	The vector2D (in the grid) that needs to converted to screen pixels.
		*
		* @return 			The converted screen pixels (of the game window).
		*/
		sf::Vector2f toScreenPixels(const arkanoid::Vector2D &vector);

	};

}

#endif /* SCREEN_H */