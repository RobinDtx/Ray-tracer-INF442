#include "Light.h"
#include <iostream>
using namespace std;

Light::Light()
{
}

Light::Light(Vector arg_source) : source(arg_source)
{
}

Light::Light(Vector arg_source, Color arg_color) : source(arg_source), color(arg_color)
{
}

const Vector* Light::getSource() const{
	return(&source);
}

const Color* Light::getColor() const{
	return(&color);
}

Light::~Light()
{
    //dtor
}

void Light::print() const
{
    cout<<"Origine : ";
    source.print();
    cout<< "Couleur : ";
    color.print();
}
