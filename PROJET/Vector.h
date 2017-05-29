#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>



class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(const Vector* p1, const Vector* p2); //Construit le vecteur de p1 à p2
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
        void normalize();

        double module() const;

        static double scalar(const Vector* p1, const Vector* p2);

        static Vector* vectorial_dot(const Vector* p1, const Vector* p2);

        //Affichage
        void print() const;
        void print(std::ostream &flux) const;

        //Surcharge operateurs
        bool operator==(const Vector& v);
        bool operator!=(const Vector& v);
        Vector& operator+=(const Vector& v);




        virtual ~Vector();
    protected:
    private:
        double X,Y,Z;
};




#endif // VECTOR_H
