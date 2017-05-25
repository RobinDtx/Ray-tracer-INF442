#ifndef LIGHT_H
#define LIGHT_H

#include "Vector.h"
#include "Color.h"

class Light
{
    public:
        Light();
        Light(Vector arg_source);
        Light(Vector arg_source, Color arg_color);
        Light(Vector arg_source, Color arg_color, double is, double id);

        double getId() const;
        double getIs() const;

        void setId(double id);
        void setIs(double is);

        void print() const;

        ~Light();

    protected:

    private:
        Vector source;
        Color color;
        double id; // intensité diffuse
        double is; // intensité spéculaire

};

#endif // LIGHT_H
