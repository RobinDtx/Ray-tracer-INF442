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

Light::Light(Vector arg_source, Color arg_color, double is, double id) : source(arg_source), color(arg_color)
{
	if(id <0){
		this->id = 0;
	}
	else{
		this->id = id;
	}

	if(is < 0){
		this->is = 0;
	}
	else{
		this->is = is;
	}
}

double Light::getId() const{
	return(id);
}

double Light::getIs() const{
	return(is);
}

void Light::setId(double id){
	if(id <0){
		this->id = 0;
	}
	else{
		this->id = id;
	}
}

void Light::setIs(double is){
	if(is < 0){
		this->is = 0;
	}
	else{
		this->is = is;
	}
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
