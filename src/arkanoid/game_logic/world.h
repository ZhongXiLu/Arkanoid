#ifndef WORLD_H
#define WORLD_H

#include "entity/entity.h"
#include "grid/grid.h"
#include "../window/window.h"
#include "../game_gui/math/transformation.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

namespace arkanoidSFML {

	/// The World of the Arkanoid game that contains all Entity objects.
	class World {
	private:
		vector<arkanoid::Entity*> entities;		///< List of all Entity in the World.

	public:
		/**
		* Default Constructor.
		*/
		World();

		/**
		* Destructor.
		*/
		~World();

		/**
		* Add an Entity to the World.
		*
		* @param entity		The Entity that will be added.
		*/
		void addEntity(arkanoid::Entity* entity);

	};

}

#endif /* WORLD_H */