#include "Vector.h"


//Constructeurs
Vector::Vector()
{
    X=0;
    Y=0;
    Z=0;
}

Vector::Vector(double x, double y, double z)
{
    X=x;
    Y=y;
    Z=z;
}

Vector::Vector(Vector v)
{
    X=v.x();
    Y=v.y();
    Z=v.z();
}




//Getters
double Vector::x()
{
    return X;
}

double Vector::y()
{
    return Y;
}

double Vector::z()
{
    return Z;
}

//Méthodes publiques
void Vector::add(Vector v)
{
    X+=v.x();
    Y+=v.y();
    Z+=v.z();
}

void Vector::add(double x, double y, double z)
{
    X+=x;
    Y+=y;
    Z+=z;
}

void Vector::multiply(double d)
{
    X*=d;
    Y*=d;
    Z*=d;
}

bool Vector::equals(Vector v)
{
    return (X==v.x()&&Y==v.y()&&Z==v.z());
}


Vector::~Vector()
{
    //dtor
}
