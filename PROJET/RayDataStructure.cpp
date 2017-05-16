/*
 * RayDataStructure.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "RayDataStructure.h"

RayDataStructure::RayDataStructure(){
	origin = Vector();
	direction = Vector();
}

RayDataStructure::~RayDataStructure() {
	// TODO Auto-generated destructor stub
}

RayDataStructure::RayDataStructure(Vector *origin, Vector *direction){
	this->origin = Vector(origin->x(), origin->y(), origin->z());
	this->direction = Vector(direction->x(), direction->y(), direction->z());
}

const Vector* RayDataStructure::getOrigin() const{
	return(&origin);
}

const Vector* RayDataStructure::getDirection() const{
	return(&direction);
}

void RayDataStructure::setOrigin(Vector *origin){
	this->origin.setX(origin->x());
	this->origin.setY(origin->y());
	this->origin.setZ(origin->z());
}

void RayDataStructure::setDirection(Vector *direction){
	this->direction.setX(direction->x());
	this->direction.setY(direction->y());
	this->direction.setZ(direction->z());
}

