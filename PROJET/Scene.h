#ifndef SCENE_H
#define SCENE_H

#include "Sphere.h"
#include <vector>
using namespace std;

class Scene : public vector<Sphere>
{
    public:
        Scene();
        Scene(double ia);
        virtual ~Scene();

        double getIa() const;
        void setIa();


    protected:

    private:
        double ia;

};

#endif // SCENE_H
