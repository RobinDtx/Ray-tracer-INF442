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
#include "Materiau.h"

class Sphere {
	public:
		Sphere();
		Sphere(Vector *center, double radius);
		Sphere(Vector *center, double radius, double r);
		Sphere(double x, double y, double z, double radius);
		Sphere(double x, double y, double z, double radius, double r);
		Sphere(Vector *center, double radius, Materiau *materiau);
		Sphere(Vector *center, double radius, Materiau *materiau, double r);
		Sphere(double x, double y, double z, double radius, Materiau *materiau);
		Sphere(double x, double y, double z, double radius, Materiau *materiau, double r);
		virtual ~Sphere();

		void setCenter(Vector *center);
		void setCenter(double x, double y, double z);
		void setCenterX(double x);
		void setCenterY(double y);
		void setCenterZ(double z);

		void setRadius(double radius);

		void setMateriau(Materiau* materiau);

		void setR(double r);

		const Vector* getCenter() const;
		double getRadius() const;
		const Materiau* getMateriau() const;
		double getR() const;

		void print() const;



	private:
		Vector center;
		double radius;
		Materiau* materiau;
		double r;
};

#endif /* SPHERE_H_ */
