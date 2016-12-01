#ifndef WALL_H
#define WALL_H

#include "../entity.h"
#include "../../math/vector2D.h"

#include <iostream>

using namespace std;


namespace arkanoid {

	/// The Wall (left/right/top side) in the Arkanoid game that represents a single "square".
	class Wall : public Entity {

	public:

		/**
		* Default Constructor.
		*
		* Initialise the Wall at origin ([0, 0]) in the World.
		*/
		Wall();

		/*
		* Constructor.
		*
		* Initialise the Wall at a specific position in the World.
		*
		* @param x 	The x position (in the grid) of the Wall.
		* @param y 	The y position (in the grid) of the Wall.
		*/
		Wall(double x, double y);

		/*
		* Destructor.
		*/
		~Wall();
		
		/*
		* Do nothing...
		*/
		void update();

		/*
		* Do nothing...
		*/
		void draw() const;
	};

}

#endif /* WALL_H */