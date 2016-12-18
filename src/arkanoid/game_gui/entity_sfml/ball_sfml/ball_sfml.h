/// \file ball_sfml.h

#ifndef BALL_SFML_H
#define BALL_SFML_H

#include "../../../game_logic/entity/ball/ball.h"
#include "../../math/transformation.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The SFML element that represents the arkanoid::Ball in the game.
	class BallSFML : public arkanoid::Ball {
	private:
		arkanoid::Vector2D screenOrigin;	///< The initial position of the BallSFML.

		sf::RenderWindow &windowSFML;

		sf::Sprite sprite;	///< The sprite of the BallSFML.
		sf::Texture texture;

		Transformation* transformation;

	public:
		/**
		* Constructor.
		*
		* Creates a BallSFML sprite in the World at a specific position in the game window.
		* Also applies the texture to this BallSFML.
		*
		* @param x				The x (on screen) position of the arkanoid::Ball.
		* @param y				The y (on screen) position of the arkanoid::Ball.
		* @param window			The SFML window.
		* @param speed			(optional) The speed of the arkanoid::Ball.
		* @param textureFile	(optional) The file that contains the texture of the BallSFML.
		*/
		BallSFML(double x, double y, sf::RenderWindow &window, double speed = 8.0, const string &textureFile = "data/sprites/ball/ball.png");

		/**
		* Destructor.
		*/
		~BallSFML();

		/**
		* Updates the BallSFML position.
		*/
		void update();

		/**
		* Draws the BallSFML in the game window.
		*/
		void draw() const;

		/**
		* Reset the position and direction of the arkanoid::Ball to the one of the starting position.
		* (-> call this method when the Player missed the arkanoid::Ball).
		*/
		void reset();
	};

}

#endif /* BALL_SFML_H */