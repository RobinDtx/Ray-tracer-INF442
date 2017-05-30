/*
 * Sphere.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "Sphere.h"
#include <iostream>
using namespace std;

//Constructeurs
Sphere::Sphere() {
	// TODO Auto-generated constructor stub
	this->radius = 0;
	this->materiau = new Materiau();
}

Sphere::Sphere(Vector *center, double radius){
	this->center = Vector(center->x(), center->y(), center->z());
	this->radius = radius;
	this->materiau = new Materiau();
}

Sphere::Sphere(double x, double y, double z, double radius){
	this->center = Vector(x, y, z);
	this->radius = radius;
	this->materiau = new Materiau();
}

Sphere::Sphere(Vector *center, double radius, Materiau *materiau){
	this->center=  Vector(center->x(), center->y(), center->z());
	this->radius = radius;
	this->materiau = materiau;
}

Sphere::Sphere(double x, double y, double z, double radius, Materiau *materiau){
	this->center = Vector(x,y,z);
	this->radius = radius;
	this->materiau = materiau;
}


Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
    delete materiau;
}


//Setters
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

void Sphere::setMateriau(Materiau *materiau){
	this->materiau = materiau;
}



//Getters

const Vector* Sphere::getCenter() const{
	return(&center);
}

double Sphere::getRadius() const{
	return(radius);
}

const Materiau* Sphere::getMateriau() const{
	return(materiau);
}


//Print
void Sphere::print() const
{
    cout<<"Centre : ";
    center.print();
    cout<<"Rayon : "<<radius<<endl;
    cout<<"Couleur : ";
    materiau->print();
}


