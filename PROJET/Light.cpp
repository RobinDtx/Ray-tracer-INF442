#include "Light.h"
#include <iostream>
using namespace std;

Light::Light()
{
    //ctor
}

Light::Light(Vector arg_source) : source(arg_source)
{

}

Light::Light(Vector arg_source, Color arg_color) : source(arg_source), color(arg_color)
{

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
