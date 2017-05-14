/*
 * RayDataStructure.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "RayDataStructure.h"

RayDataStructure::RayDataStructure(){
	origin = new Vector();
	direction = new Vector();
}

RayDataStructure::~RayDataStructure() {
	// TODO Auto-generated destructor stub
}

RayDataStructure::RayDataStructure(Vector &origin, Vector &direction){
	this->origin = &origin;
	this->direction = &direction;
}

Vector* RayDataStructure::getOrigin(){
	return(origin);
}

Vector* RayDataStructure::getDirection(){
	return(direction);
}

void RayDataStructure::setOrigin(Vector &origin){
	this->origin = &origin;
}

void RayDataStructure::setDirection(Vector &direction){
	this->direction = &direction;
}

