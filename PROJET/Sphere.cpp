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

Sphere::Sphere(Vector *center, double radius){
	this->center = Vector(center->x(), center->y(), center->z());
	this->radius = radius;
}

Sphere::Sphere(double x, double y, double z, double radius){
	this->center = Vector(x, y, z);
	this->radius = radius;
}

Sphere::Sphere(Vector *center, double radius, Color *color){
	this->center=  Vector(center->x(), center->y(), center->z());
	this->radius = radius;
	this->color = Color(color->getRed(), color->getGreen(), color->getBlue());
}

Sphere::Sphere(double x, double y, double z, double radius, Color *color){
	this->center = Vector(x,y,z);
	this->radius = radius;
	this->color = Color(color->getRed(), color->getGreen(), color->getBlue());
}

Sphere::Sphere(Vector *center, double radius, unsigned int red, unsigned int green, unsigned int blue){
	this->center = Vector(center->x(), center->y(), center->z());
	this->radius = radius;
	this->color = Color(red, green, blue);
}

Sphere::Sphere(double x, double y, double z, double radius, unsigned int red, unsigned int green, unsigned blue){
	this->center = Vector(x,y,z);
	this->radius = radius;
	this->color = Color(red, green, blue);
}

void Sphere::setCenter(Vector *center){
	this->center.setX(center->x());
	this->center.setY(center->y());
	this->center.setZ(center->z());
}

void Sphere::setCenter(double x, double y, double z){
	this->center.setX(x);
	this->center.setY(y);
	this->center.setZ(z);
}

void Sphere::setCenterX(double x){
	this->center.setX(x);
}

void Sphere::setCenterY(double y){
	this->center.setY(y);
}

void Sphere::setCenterZ(double z){
	this->center.setZ(z);
}

void Sphere::setRadius(double radius){
	this->radius = radius;
}

void Sphere::setColor(Color *color){
	this->color.setRed(color->getRed());
	this->color.setGreen(color->getGreen());
	this->color.setBlue(color->getBlue());
}

void Sphere::setColor(unsigned int red, unsigned int green, unsigned int blue){
	this->color.setRed(red);
	this->color.setGreen(green);
	this->color.setBlue(blue);
}

void Sphere::setColorRed(unsigned int red){
	this->color.setRed(red);
}

void Sphere::setColorGreen(unsigned int green){
	this->color.setGreen(green);
}

void Sphere::setColorBlue(unsigned int blue){
	this->color.setBlue(blue);
}

const Vector* Sphere::getCenter() const{
	return(&center);
}

double Sphere::getRadius() const{
	return(radius);
}

const Color* Sphere::getColor() const{
	return(&color);
}



Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

