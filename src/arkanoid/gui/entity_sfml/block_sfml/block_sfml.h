/// \file block_sfml.h

#ifndef BLOCK_SFML_H
#define BLOCK_SFML_H

#include "../../../logic/entity/block/block.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the arkanoid::Block in the game.
	class BlockSFML : virtual public arkanoid::Block {
	protected:
		sf::RenderWindow &windowSFML;

		sf::Sprite sprite; ///< The sprite of the BlockSFML.
		sf::Texture texture;
		
		Transformation* transformation;

	public:

		/**
		* Constructor.
		*
		* Creates a BlockSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this BlockSFML.
		*
		* @param x				The x (on screen) position of the arkanoid::Block.
		* @param y				The y (on screen) position of the arkanoid::Block.
		* @param window			The SFML window.
		* @param textureFile 	(optional) The file that contains the texture of the BlockSFML.
		*/
		BlockSFML(double x, double y, sf::RenderWindow &window, const string &textureFile = "data/sprites/blocks/blue_block.png");

		/**
		* Destructor.
		*/
		~BlockSFML();

		/**
		* Do nothing...
		*/
		void update();

		/**
		* Draws the BlockSFML in the game window.
		*/
		void draw() const;
		
	};

}

#endif /* BLOCK_SFML_H */