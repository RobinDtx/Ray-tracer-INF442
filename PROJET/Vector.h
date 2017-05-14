#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(const Vector& v);

        double x();
        double y();
        double z();

        void add(const Vector& v);
        void add(double x, double y, double z);
        void multiply(double d);
        bool equals(const Vector& v);

        virtual ~Vector();
    protected:
    private:
        double X,Y,Z;
};

#endif // VECTOR_H
