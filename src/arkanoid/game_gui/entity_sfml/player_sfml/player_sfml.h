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
	private:
		sf::RenderWindow &windowSFML;

		sf::Sprite sprite;	///< The sprite of the PlayerSFML.
		sf::Texture texture;

		shared_ptr<Transformation> transformation;

	public:
		/**
		* Constructor.
		*
		* Creates a PlayerSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this PlayerSFML.
		*
		* @param x				The x (on screen) position of the Player.
		* @param y				The y (on screen) position of the Player.
		* @param window			The SFML window.
		* @param transform		The Transformation object thats needed to convert coordinates to screen pixels.
		* @param speed			(optional) The speed of the Player.
		* @param textureFile	(optional) The file that contains the texture of the PlayerSFML.
		*/
		PlayerSFML(double x, double y, sf::RenderWindow &window, shared_ptr<Transformation> transform, double speed = 10.0, const string &textureFile = "sprites/player/player.png");

		/**
		* Destructor.
		*/
		~PlayerSFML();

		/**
		* Check for user input and make the corresponding move if necessary.
		*/
		void update();

		/**
		* Draws the PlayerSFML in the game window.
		*/
		void draw() const;
	};

}

#endif /* PLAYER_SFML_H */