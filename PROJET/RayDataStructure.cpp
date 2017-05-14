/*
 * RayDataStructure.cpp
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#include "RayDataStructure.h"

RayDataStructure::RayDataStructure() {
	this->origin = new Vector();
	this->directino = new Vector();
}

RayDataStructure::~RayDataStructure() {
	// TODO Auto-generated destructor stub
}

RayDataStructure::RayDataStructure(Vector origin, Vector direction){
	this->origin = origin;
	this->direction = direction;
}

