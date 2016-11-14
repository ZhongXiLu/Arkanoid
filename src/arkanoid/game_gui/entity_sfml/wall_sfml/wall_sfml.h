#ifndef WALL_SFML_H
#define WALL_SFML_H

#include "../../../game_logic/entity/wall/wall.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Wall in the game.
	class WallSFML : public arkanoid::Wall {
	public:
		sf::Texture texture;
		shared_ptr<Transformation> transformation;

	public:
		sf::Sprite sprite; ///< The sprite of the WallSFML.

		/**
		* Default Constructor.
		*
		* Creates a (empty) WallSFML sprite in the World at origin ([0, 0]) in the game window.
		*/
		WallSFML();

		/**
		* Constructor.
		*
		* Creates a WallSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this WallSFML.
		*
		* @param x				The x (in the grid) position of the Wall.
		* @param y				The y (in the grid) position of the Wall.
		* @param textureFile 	The file that contains the texture of the WallSFML.
		* @param transform 		The Transformation object thats needed to convert coordinates to screen pixels.
		*/
		WallSFML(int x, int y, const string &textureFile, shared_ptr<Transformation> transform);

	};

}

#endif /* WALL_SFML_H */