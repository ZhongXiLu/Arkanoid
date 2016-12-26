/// \file player_speed_block_sfml.h

#ifndef PLAYER_SPEED_BLOCK_SFML_H
#define PLAYER_SPEED_BLOCK_SFML_H

#include "../../../../logic/entity/block/special_block/player_speed_block.h"
#include "../block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the arkanoid::PlayerSpeedBlock in the game.
	class PlayerSpeedBlockSFML : public arkanoid::PlayerSpeedBlock, public BlockSFML {
	public:

		/**
		* Constructor.
		*
		* Creates a PlayerSpeedBlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this PlayerSpeedBlockSFML.
		*
		* @param x				The x (on screen) position of the arkanoid::Block.
		* @param y				The y (on screen) position of the arkanoid::Block.
		* @param window			The SFML window.
		* @param speedF			(optional) The factor of the speed up/down for the arkanoid::Ball.
		* @param textureFile 	(optional) The file that contains the texture of the PlayerSpeedBlockSFML.
		*/
		PlayerSpeedBlockSFML(double x, double y, sf::RenderWindow &window, double speedF = 1.5, const string &textureFile = "data/sprites/blocks/yellow_block.png");

		/**
		* Destructor.
		*/
		~PlayerSpeedBlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the PlayerSpeedBlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* PLAYER_SPEED_BLOCK_SFML_H */