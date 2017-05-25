/*
 * Camera.cpp
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#include "Camera.h"

Camera::Camera() {
	heigh = 0;
	width = 0;
	eye = Vector();
	target = Vector();
	orientation = Vector();
}

Camera::Camera(double heigh, double width){
	this->heigh = heigh;
	this->width = width;
	eye = Vector();
	target = Vector();
	orientation = Vector();
}

Camera::Camera(Vector* eye, Vector* target, Vector* orientation){
	heigh = 0;
	width = 0;
	this->eye = Vector(eye->x(), eye->y(), eye->z());
	this->target = Vector(target->x(), target->y(), target->z());
	this->orientation = Vector(orientation->x(), orientation->y(), orientation->z());
}

Camera::Camera(Vector* eye, Vector* target, Vector* orientation, double heigh, double width){
	this->heigh = heigh;
	this->width = width;
	this->eye = Vector(eye->x(), eye->y(), eye->z());
	this->target = Vector(target->x(), target->y(), target->z());
	this->orientation = Vector(orientation->x(), orientation->y(), orientation->z());
}

const Vector* Camera::getEye() const{
	return(&eye);
}

const Vector* Camera::getTarget() const{
	return(&target);
}

const Vector* Camera::getOrientation() const{
	return(&orientation);
}

double Camera::getHeigh() const{
	return(heigh);
}

double Camera::getWidth() const{
	return(width);
}


Camera::~Camera() {

}

