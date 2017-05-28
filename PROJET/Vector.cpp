#include "Vector.h"
#include <iostream>
#include <math.h>


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

Vector::Vector(const Vector* p1, const Vector* p2){
	X = p2->x()-p1->x();
	Y = p2->y()-p1->y();
	Z = p2->z()-p1->z();
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

//Methodes publiques
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

bool Vector::equals(const Vector& v) const
{
    return (X==v.x()&&Y==v.y()&&Z==v.z());
}

void Vector::normalize(){
	double mod = this->module();
	X = X/mod;
	Y = Y/mod;
	Z = Z/mod;
}

double Vector::module() const
{
    return (sqrt(X*X+Y*Y+Z*Z));
}

double Vector::scalar(const Vector* p1, const Vector* p2){
	return(p1->x()*p2->x() + p1->y()*p2->y() + p1->z()*p2->z());
}

Vector* Vector::scalar_dot(const Vector* p1, const Vector* p2){
	return(new Vector(p1->y() * p2->z() - p1->z() * p2->y(), p1->z() * p2->x() - p1->x() * p2->z(), p1->x() * p2->y() - p2->y()* p1->x()));
}

void Vector::print() const
{
    std::cout << "x = " << X << " ; y = " << Y << " ; z = " << Z << std::endl;
}

void Vector::print(std::ostream &flux) const
{
    flux << "x = " << X << " ; y = " << Y << " ; z = " << Z << std::endl;
}


bool Vector::operator==(const Vector& v)
{
    return equals(v);
}

bool Vector::operator!=(const Vector& v)
{
    return !equals(v);
}

Vector& Vector::operator+=(const Vector& v){
	X += v.x();
	Y += v.y();
	Z += v.z();
	return *this;
}




Vector::~Vector()
{
    //dtor
}



