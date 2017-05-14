/*
 * Sphere.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "Sphere.h"

Sphere::Sphere() {
	// TODO Auto-generated constructor stub
	this->center = new Vector();
	this->radius = 0;
}

Sphere::Sphere(Vector &center, double radius){
	this->center = &center;
	this->radius = radius;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

