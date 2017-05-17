#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>



class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        //Constructeur de copie deja cree

        //Getters
        double x() const;
        double y() const;
        double z() const;

        //Setters
        void setX(double x);
        void setY(double y);
        void setZ(double z);

        //Operations
        void add(const Vector& v);
        void add(double x, double y, double z);
        void multiply(double d);
        bool equals(const Vector& v) const;

        double module() const;

        //Affichage
        void print() const;
        void print(std::ostream &flux) const;

        //Surcharge operateurs
        bool operator==(const Vector& v);
        bool operator!=(const Vector& v);



        virtual ~Vector();
    protected:
    private:
        double X,Y,Z;
};




#endif // VECTOR_H
