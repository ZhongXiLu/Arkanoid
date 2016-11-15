#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>

using namespace std;

namespace Game {
	struct Grid {
		double width;			///< The width of the grid.
		double height;			///< The height of the grid.

		Grid(double w, double h);
	};
}

#endif /* GRID_H */