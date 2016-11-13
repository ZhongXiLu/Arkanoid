#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include "../../../game_logic/entity/player/player.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Player in the game.
	class PlayerSFML : public arkanoid::Player {
	public:
		sf::Texture texture;

	public:
		sf::Sprite sprite; ///< The sprite of the PlayerSFML.

		/**
		* Default Constructor.
		*
		* Creates a (empty) PlayerSFML sprite in the World at origin ([0, 0]) in the game window.
		*/
		PlayerSFML();

		/**
		* Default Constructor.
		*
		* Creates a PlayerSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this PlayerSFML.
		*
		* @param x				The x (in the grid) position of the Player.
		* @param y				The y (in the grid) position of the Player.
		* @param textureFile 	The file that contains the texture of the PlayerSFML.
		*/
		PlayerSFML(int x, int y, const string &textureFile);

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