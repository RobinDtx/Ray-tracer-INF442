#ifndef SCENE_H
#define SCENE_H

#include "Sphere.h"
#include <vector>
using namespace std;

class Scene : public vector<Sphere>
{
    public:
        Scene();
        virtual ~Scene();


    protected:

    private:

};

#endif // SCENE_H
