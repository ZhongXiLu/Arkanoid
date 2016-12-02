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
		* @param windowHeight	The height of the screen (game window).
		*/
		Transformation(double gridWidth, double gridHeight, double windowWidth, double windowHeight);

		/**
		* Converts a screen pixel to their corresponding game world coordinate.
		*
		* @param vector		The Vector2D (on screen) that needs to converted to the game world space.
		*
		* @return			The converted screen pixels (of the game window) as a Vector2D.
		*/
		arkanoid::Vector2D convertVector(const sf::Vector2f &vector);

		/**
		* Converts an 'x' to their corresponding game world 'x'.
		*
		* @param x		The 'x' component (on screen) that needs to converted to the game world space.
		*
		* @return		The corresponding 'x' in the game world space.
		*/
		double convertX(double x);

		/**
		* Converts an 'y' to their corresponding game world 'y'.
		*
		* @param y		The 'y' component (on screen) that needs to converted to the game world space.
		*
		* @return		The corresponding 'y' in the game world space.
		*/
		double convertY(double y);


	};

}

#endif /* SCREEN_H */