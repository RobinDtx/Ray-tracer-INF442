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

        const Vector* getSource() const;
        const Color* getColor() const;

        void print() const;

        ~Light();

    protected:

    private:
        Vector source;
        Color color;

};

#endif // LIGHT_H
