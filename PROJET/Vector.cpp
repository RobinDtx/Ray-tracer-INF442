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





//Getters
double Vector::x() const
{
    return X;
}

double Vector::y() const
{
    return Y;
}

double Vector::z() const
{
    return Z;
}

//Setters
void Vector::setX(double x){
	this->X = x;
}
void Vector::setY(double y){
	this->Y = y;
}
void Vector::setZ(double z){
	this->Z = z;
}

//M�thodes publiques
void Vector::add(const Vector& v)
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

bool Vector::equals(const Vector& v)
{
    return (X==v.x()&&Y==v.y()&&Z==v.z());
}


Vector::~Vector()
{
    //dtor
}
