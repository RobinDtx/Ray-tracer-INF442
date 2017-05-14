#include "Vector.h"


//Constructeurs
Vector::Vector()
{
    x=0;
    y=0;
    z=0;
}

Vector::Vector(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

Vector::Vector(Vector v)
{
    this->x=v.x();
    this->y=v.y();
    this->z=v.z();
}




//Getters
double Vector::x()
{
    return this->x;
}

double Vector::y()
{
    return this->y;
}

double Vector::z()
{
    return this->z;
}

//Méthodes publiques
void Vector::add(Vector v)
{
    this->x+=v.x();
    this->y+=v.y();
    this->z+=v.z();
}

void Vector::add(double x, double y, double z)
{
    this->x+=x;
    this->y+=y;
    this->z+=z;
}

Vector::~Vector()
{
    //dtor
}
