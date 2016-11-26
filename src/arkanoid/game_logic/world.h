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

namespace arkanoid {

	/// The World of the Arkanoid game that contains all Entity objects.
	class World : public Entity {
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
		* Updates all Entity in the World.
		*/
		void update();

		/**
		* Adds an Entity to the World.
		*
		* @param entity		The Entity that will be added.
		*/
		void addEntity(arkanoid::Entity* entity);

	};

}

#endif /* WORLD_H */