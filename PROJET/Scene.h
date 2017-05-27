#ifndef SCENE_H
#define SCENE_H

#include "Sphere.h"
#include <vector>
using namespace std;

class Scene : public vector<Sphere>
{
    public:
        Scene();
        Scene(Color* ia);
        virtual ~Scene();

        const Color* getIa() const;
        void setIa(Color *ia);


    protected:

    private:
        Color ia;

};

#endif // SCENE_H
