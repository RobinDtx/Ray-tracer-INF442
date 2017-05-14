#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        Vector(Vector v);

        double x();
        double y();
        double z();

        void add(Vector v);
        virtual ~Vector();
    protected:
    private:
        double x,y,z;
};

#endif // VECTOR_H
