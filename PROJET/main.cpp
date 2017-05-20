#include <iostream>
using namespace std;
#include "Vector.h"
#include "RayDataStructure.h"
#include "Color.h"
#include "Sphere.h"
#include "Scene.h"

std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main()
{
	Vector test (1,2,3);
	Sphere sph (&test,3);
    Scene scene;
    cout<<scene.spheres.size()<<endl;
    scene.spheres.push_back(sph);
    cout<<scene.spheres.size();
	//test2.add(0,0,1.5);
	//test.multiply(1.1);
//	if (test==test2)
//	{
//	    std::cout << test.module();
//	}
}


