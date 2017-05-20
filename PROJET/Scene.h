#ifndef SCENE_H
#define SCENE_H

#include "Sphere.h"
#include <vector>
using namespace std;

class Scene
{
    public:
        Scene();
        virtual ~Scene();

        vector<Sphere> spheres;

    protected:

    private:

};

#endif // SCENE_H
