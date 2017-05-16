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

Color::Color(unsigned int red, unsigned int green, unsigned int blue){
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

void Color::setRed(unsigned int red){
	if(red > 255){
		this->red = 255;
	}
	else{
		this->red = red;
	}
}

void Color::setGreen(unsigned int green){
	if(green > 255){
		this->green = 255;
	}
	else{
		this->green = green;
	}
}

void Color::setBlue(unsigned int blue){
	if(blue > 255){
		this->blue = 255;
	}
	else{
		this->blue = blue;
	}

}

unsigned int Color::getRed() const{
	return(red);
}

unsigned int Color::getGreen() const{
	return(green);
}

unsigned int Color::getBlue() const{
	return(blue);
}

