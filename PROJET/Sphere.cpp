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

Sphere::Sphere(double x, double y, double z, double radius){
	this->center = Vector(x, y, z);
	this->radius = radius;
}

Sphere::Sphere(Vector &center, double radius, Color &color){
	this->center=  Vector(center);
	this->radius = radius;
	this->color = Color(color);
}

Sphere::Sphere(double x, double y, double z, double radius, Color &color){
	this->center = Vector(x,y,z);
	this->radius = radius;
	this->color = Color(color);
}

Sphere::Sphere(Vector &center, double radius, unsigned int red, unsigned int green, unsigned int blue){
	this->center = Vector(center);
	this->radius = radius;
	this->color = Color(red, green, blue);
}

Sphere::Sphere(double x, double y, double z, double radius, unsigned int red, unsigned int green, unsigned blue){
	this->center = Vector(x,y,z);
	this->radius = radius;
	this->color = Color(red, green, blue);
}

void Sphere::setCenter(Vector &center){
	this->center = Vector(center);
}

void Sphere::setCenter(double x, double y, double z){

}



Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

