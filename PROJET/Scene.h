#ifndef SCENE_H
#define SCENE_H

#include "Sphere.h"
#include <vector>
using namespace std;

class Scene : protected vector<Sphere>
{
    public:
        Scene();
        virtual ~Scene();


    protected:

    private:

};

#endif // SCENE_H
