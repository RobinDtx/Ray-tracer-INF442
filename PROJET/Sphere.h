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
		Sphere(Vector const& center, double radius);
		Sphere(double x, double y, double z, double radius);
		Sphere(Vector const& center, double radius, Color const& color);
		Sphere(double x, double y, double z, double radius, Color const& color);
		Sphere(Vector const& center, double radius, unsigned int red, unsigned int green, unsigned int blue);
		Sphere(double x, double y, double z, double radius, unsigned int red, unsigned int green, unsigned int blue);
		virtual ~Sphere();

		void setCenter(Vector const& center);
		void setCenter(double x, double y, double z);
		void setCenterX(double x);
		void setCenterY(double y);
		void setCenterZ(double z);

		void setRadius(double radius);

		void setColor(Color const& color);
		void setColor(unsigned int red, unsigned int green, unsigned blue);
		void setColorRed(unsigned int red);
		void setColorGreen(unsigned int green);
		void setColorBlue(unsigned int blue);

		const Vector& getCenter() const;
		double* getRadius() const;
		Color* getColor() const;



	private:
		Vector center;
		double radius;
		Color color;
};

#endif /* SPHERE_H_ */
