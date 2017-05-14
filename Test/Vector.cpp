#include "Vector.h"

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

Vector::~Vector()
{
    //dtor
}
