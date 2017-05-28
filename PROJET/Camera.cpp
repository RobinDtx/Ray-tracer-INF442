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

Camera::Camera(int heigh, int width){
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

Camera::Camera(Vector* eye, Vector* target, Vector* orientation, int heigh, int width){
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

int Camera::getHeigh() const{
	return(heigh);
}

int Camera::getWidth() const{
	return(width);
}

void Camera::setEye(Vector* eye){
	this->eye.setX(eye->x());
	this->eye.setY(eye->y());
	this->eye.setZ(eye->z());
}

void Camera::setTarget(Vector* target){
	this->target.setX(target->x());
	this->target.setY(target->y());
	this->target.setZ(target->z());
}

void Camera::setOrientation(Vector* orientation){
	this->orientation.setX(orientation->x());
	this->orientation.setY(orientation->y());
	this->orientation.setZ(orientation->z());
}

void Camera::setHeigh(int heigh){
	this->heigh = heigh;
}

void Camera::setWidth(int width){
	this->width = width;
}

Camera::~Camera() {

}

