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
    x=v.x();
    y=v.y();
    z=v.z();
}




//Getters
double Vector::x()
{
    return x;
}

double Vector::y()
{
    return y;
}

double Vector::z()
{
    return z;
}

//Méthodes publiques
void Vector::add(Vector v)
{
    x+=v.x();
    y+=v.y();
    z+=v.z();
}

void Vector::add(double x, double y, double z)
{
    this->x+=x;
    this->y+=y;
    this->z+=z;
}

void Vector::multiply(double d)
{
    x*=d;
    y*=d;
    z*=d;
}

bool Vector::equals(Vector v)
{
    return (x==v.x()&&y==v.y()&&z==v.z());
}


Vector::~Vector()
{
    //dtor
}
