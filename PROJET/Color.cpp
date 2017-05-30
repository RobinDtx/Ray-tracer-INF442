/*
 * Color.cpp
 *
 *  Created on: 16 mai 2017
 *      Author: egoutierre
 */

#include "Color.h"
#include <algorithm>
using namespace std;
#include <iostream>
using namespace std;

Color::Color() {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(unsigned int red, unsigned int green, unsigned int blue){
	this->red = min(red,(unsigned int)255);
	this->green = min(green,(unsigned int)255);
	this->blue = min(blue,(unsigned int)255);
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

void Color::setRed(unsigned int red){
	this->red = min(red,(unsigned int)255);
}

void Color::setGreen(unsigned int green){
	this->green = min(green,(unsigned int)255);
}

void Color::setBlue(unsigned int blue){
	this->blue = min(blue,(unsigned int)255);

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

void Color::print() const
{
    cout << "RGB " << getRed() << "/" << getGreen() << "/" << getBlue() << endl;
}

//Color& Color::operator*=(double l){
//	setRed(l*red);
//	setGreen(l*green);
//	setBlue(l*blue);
//	return *this;
//}
//
//Color& Color::operator/=(double l){
//	setRed(red/l);
//	setGreen(green/l);
//	setBlue(blue/l);
//	return(*this);
//}
//
//Color& Color::operator+=(const Color& c){
//	setRed(red + c.getRed());
//	setGreen(green + c.getGreen());
//	setBlue(blue + c.getBlue());
//	return(*this);
//}
//
//Color& Color::operator-=(const Color& c){
//	setRed(red - c.getRed());
//	setGreen(green - c.getGreen());
//	setBlue(blue - c.getBlue());
//	return(*this);
//}
//
//Color operator*(double l, Color const& c){
//	Color copie(c);
//	copie *= l;
//	return(copie);
//}
//
//Color operator/(Color const& c, double l){
//	Color copie(c);
//	copie /= l;
//	return(copie);
//}
//
//Color operator+(Color const& c1, Color const& c2){
//	Color copie(c1);
//	copie += c2;
//	return(copie);
//}
//
//Color operator-(Color const& c1, Color const& c2){
//	Color copie(c1);
//	copie -= c2;
//	return(copie);
//}
