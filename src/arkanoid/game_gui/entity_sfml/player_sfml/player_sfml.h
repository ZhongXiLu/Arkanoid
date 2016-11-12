#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include "../../../game_logic/entity/player/player.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the Player in the game.
	class PlayerSFML : public arkanoid::Player {

	public:
		sf::Sprite sprite; ///< The sprite of the Player.

		/**
		* Default Constructor.
		*
		* Creates a Player sprite in the World at origin ([0, 0]) in the game window.
		*/
		PlayerSFML();

		/**
		* Default Constructor.
		*
		* Creates a Player sprite in the World at a specific position in the game window.
		*
		* @param x	The x (in the grid) position of the Player.
		* @param y	The y (in the grid) position of the Player.
		*/
		PlayerSFML(int x, int y);

	};

}

#endif /* PLAYER_SFML_H */