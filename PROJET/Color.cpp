/*
 * Color.cpp
 *
 *  Created on: 16 mai 2017
 *      Author: egoutierre
 */

#include "Color.h"

Color::Color() {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(int red, int green, int blue){
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

void Color::setRed(int red){
	this->red = red;
}

void Color::setGreen(int green){
	this->green = green;
}

void Color::setBlue(int blue){
	this->blue = blue;
}

int Color::getRed(){
	return(red);
}

int Color::getGreen(){
	return(green);
}

int Color::getBlue(){
	return(blue);
}

