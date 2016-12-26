/// \file player_speed_block.h

#ifndef PLAYER_SPEED_BLOCK_H
#define PLAYER_SPEED_BLOCK_H

#include "../block.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// A "special" Block: when hit with a Ball, speed up or slow down the Player.
	class PlayerSpeedBlock : virtual public Block {
	private:
		double speedFactor;

	public:

		/**
		* Default Constructor.
		*
		* Initialise the PlayerSpeedBlock at origin ([0, 0]) in the World.
		*/
		PlayerSpeedBlock();

		/**
		* Constructor.
		*
		* Initialise the PlayerSpeedBlock at a specific position in the World.
		*
		* @param x			The x position (in the grid) of the PlayerSpeedBlock.
		* @param y			The y position (in the grid) of the PlayerSpeedBlock.
		* @param speedF		(optional) The factor of the speed up/down for the Ball.
		* @param size		(optional) The size (width and height respectively) of the PlayerSpeedBlock.
		*/
		PlayerSpeedBlock(double x, double y, double speedF = 1.5, pair<double, double> size = make_pair(1, 2));

		/**
		* Destructor.
		*/
		~PlayerSpeedBlock();
		
		/**
		* Do nothing...
		*/
		void update();

		/**
		* Do nothing...
		*/
		void draw() const;

		/**
		* Activate this PlayerSpeedBlock 'speciality': speed up or slow down the Player, depending on the speed factor.
		*
		* @param player	The Player that will be effected.
		*/
		void effectPlayer(unique_ptr<Player> &player) const;
	};

}

#endif /* BALL_SPEED_BLOCK_H */