/*
 * Sphere.h
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include "Vector.h"

class Sphere {
	public:
		Sphere();
		Sphere(Vector &center, double radius);
		virtual ~Sphere();

	private:
		Vector* center;
		double radius;
};

#endif /* SPHERE_H_ */
