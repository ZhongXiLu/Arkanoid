#ifndef INVIS_BLOCK_SFML_H
#define INVIS_BLOCK_SFML_H

#include "../../../../game_logic/entity/block/special_block/invis_block.h"
#include "../block_sfml.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the InvisBlock in the game.
	class InvisBlockSFML : public arkanoid::InvisBlock, public BlockSFML {
	public:

		/**
		* Constructor.
		*
		* Creates a InvisBlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this InvisBlockSFML.
		*
		* @param x				The x (on screen) position of the Block.
		* @param y				The y (on screen) position of the Block.
		* @param textureFile 	(optional) The file that contains the texture of the InvisBlockSFML.
		*/
		InvisBlockSFML(double x, double y, sf::RenderWindow &window, const string &textureFile = "data/sprites/blocks/red_block.png");

		/**
		* Destructor.
		*/
		~InvisBlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the InvisBlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* INVIS_BLOCK_SFML_H */