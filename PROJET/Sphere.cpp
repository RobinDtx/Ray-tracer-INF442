/*
 * Sphere.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "Sphere.h"

Sphere::Sphere() {
	// TODO Auto-generated constructor stub
	this->radius = 0;
}

Sphere::Sphere(Vector &center, double radius){
	this->center = Vector(center);
	this->radius = radius;
}

Sphere::Sphere(Vector &center, double radius, Color color){
	this->center = Vector(center);
	this->radius = radius;
	this->color = Color(color);
}



Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

