#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector
        double x();
        double y();
        double z();
        virtual ~Vector();
    protected:
    private:
        double x,y,z;
};

#endif // VECTOR_H
