#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        //Constructeur de copie d�j� cr��

        //Getters
        double x() const;
        double y() const;
        double z() const;

        //Setters
        void setX(double x);
        void setY(double y);
        void setZ(double z);

        //Op�rations
        void add(const Vector& v);
        void add(double x, double y, double z);
        void multiply(double d);
        bool equals(const Vector& v);

        //Surcharge op�rateurs
        //bool operator==(const Vector)



        virtual ~Vector();
    protected:
    private:
        double X,Y,Z;
};

#endif // VECTOR_H
