#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include "../../../game_logic/entity/player/player.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Player in the game.
	class PlayerSFML : public arkanoid::Player {
	public:
		sf::Texture texture;
		shared_ptr<Transformation> transformation;

	public:
		sf::Sprite sprite; ///< The sprite of the PlayerSFML.

		/**
		* Default Constructor.
		*
		* Creates a (empty) PlayerSFML sprite in the World at origin ([0, 0]) in the game window.
		*/
		PlayerSFML();

		/**
		* Constructor.
		*
		* Creates a PlayerSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this PlayerSFML.
		*
		* @param x				The x (in the grid) position of the Player.
		* @param y				The y (in the grid) position of the Player.
		* @param textureFile 	The file that contains the texture of the PlayerSFML.
		* @param transform 		The Transformation object thats needed to convert coordinates to screen pixels.
		*/
		PlayerSFML(double x, double y, const string &textureFile, shared_ptr<Transformation> transform);

		/*
		* Moves the PlayerSFML one "block" to the left on the screen and in the grid.
		*
		* @return True if move was valid and made, otherwise False.
		*/
		bool moveLeft();

		/*
		* Moves the PlayerSFML one "block" to the right on the screen and in the grid.
		*
		* @return True if move was valid and made, otherwise False.
		*/
		bool moveRight();

	};

}

#endif /* PLAYER_SFML_H */