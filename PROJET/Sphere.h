/*
 * Sphere.h
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Vector.h"
#include "Color.h"

class Sphere {
	public:
		Sphere();
		Sphere(Vector &center, double radius);
		Sphere(Vector &center, double radius, Color &color);
		Sphere(Vector &center, double radius, unsigned int red, unsigned int green, unsigned int blue);
		virtual ~Sphere();

		void setCenter(Vector *center);
		void setRadius(double radius);
		void setColor(Color *color);
		void setColor(unsigned int red, unsigned int green, unsigned blue);

		Vector* getCenter();
		double getRadius();
		Color* getColor();



	private:
		Vector center;
		double radius;
		Color color;
};

#endif /* SPHERE_H_ */
