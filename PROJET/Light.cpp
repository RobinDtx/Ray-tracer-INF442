#include "Light.h"
#include <iostream>
using namespace std;

Light::Light()
{
	is = 0;
	id = 0;
    //ctor
}

Light::Light(Vector arg_source) : source(arg_source)
{
	is = 0;
	id = 0;
}

Light::Light(Vector arg_source, Color arg_color) : source(arg_source), color(arg_color)
{
	is = 0;
	id = 0;
}

const Vector* Light::getSource() const{
	return(&source);
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
