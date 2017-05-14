#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);
        //Constructeur de copie déjà créé

        //Getters
        double x() const;
        double y() const;
        double z() const;

        //Opérations
        void add(const Vector& v);
        void add(double x, double y, double z);
        void multiply(double d);
        bool equals(const Vector& v);

        //Surcharge opérateurs
        //bool operator==(const Vector)



        virtual ~Vector();
    protected:
    private:
        double X,Y,Z;
};

#endif // VECTOR_H
