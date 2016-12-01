#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

using namespace std;


namespace arkanoid {

	/// Representation of a vector.
	class Vector2D {
	public:

		double x;	///< The 'x' component of the Vector2D.
		double y;	///< The 'y' component of the Vector2D.

		/**
		* Default Constructor.
		*/
		Vector2D();

		/**
		* Constructor.
		*
		* @param newX	The 'x' component of the new constructed Vector2D.
		* @param newY	The 'y' component of the new constructed Vector2D.
		*/
		Vector2D(double newX, double newY);

		/**
		* '+' Overloader.
		*
		* Translates the Vector2D over the other Vector2D.
		*
		* @param other	The other Vector2D on which this Vector2D will be translated on.
		*
		* @return The result of the translation.
		*/
		Vector2D operator+(const Vector2D &other);

		/**
		* '=' Overloader.
		*
		* Asign new values to this Vector2D.
		*
		* @param other The Vector2D that contains the new values 'x' and 'y'.
		*/
		void operator=(const Vector2D &other);

		/**
		* '<<' Overloader.
		*
		* Prints the values of this Vector2D (debugging reasons).
		*
		* @param stream The stream where the outputs is in.
		* @param vector The vector of which the output is printed.
		*/
		friend ostream& operator<<(ostream& stream, Vector2D& vector);

	};

}

#endif /* VECTOR2D_H */