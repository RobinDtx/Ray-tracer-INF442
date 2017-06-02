#include <iostream>
using namespace std;
#include "Vector.h"
#include "RayDataStructure.h"
#include "Color.h"
#include "Sphere.h"
#include "Scene.h"
#include "Light.h"
#include "Algorithm.h"

//#include "opencv2/core/core.hpp"
//#include "opencv2/flann/miniflann.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/photo/photo.hpp"
//#include "opencv2/video/video.hpp"
//#include "opencv2/features2d/features2d.hpp"
//#include "opencv2/objdetect/objdetect.hpp"
//#include "opencv2/calib3d/calib3d.hpp"
//#include "opencv2/ml/ml.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/core/core_c.h"
//#include "opencv2/highgui/highgui_c.h"
//#include "opencv2/imgproc/imgproc_c.h"
//
//using namespace cv;





int main(int argc, char** argv)
{

	Vector test (0,0,1000000);

	Color couleur (255,255,255);
	Light light(test,couleur);

	Vector test2(-1000000, -100000, 100000);
	Color couleur2(255,0,100);
	Light light2(test2, couleur2);
   // light.print();

    std::vector<Light> lights;
    lights.push_back(light);
    //lights.push_back(light2);
    Materiau un (0.6,0.6,0,0.3,0.3,0,0.1,0.1,0.1,50);
    Materiau deux (0,0.6,0,0,0.3,0,0.1,0.1,0.1,50);
    Sphere sphere(0, 0, 0, 500, &un, 0.15);
    Sphere sphere2(-900,-200,50,100,&deux,0.15);
    Sphere sphere3(200, 200, 0, 100, &un);
    Scene scene;
    scene.push_back(sphere);
    scene.push_back(sphere2);
    //scene.push_back(sphere3);


    Vector eye(-100000,0,0);
    Vector target (0,0,0);
    Vector up(0,0,1);
    Camera camera(&eye, &target, &up, 1400, 1400);

    Algorithm algo(lights, scene, camera, un);
    algo.ray_traced_algorithm();
    algo.ecrire("problème");



//	RayDataStructure *rd = new RayDataStructure(new Vector(0,0,0), new Vector(3,0,0));
//	Sphere *s = new Sphere(new Vector(3,0,0), 1);
//	std::pair<bool, std::pair<Vector*, double> > p = algo.ray_sphere_intersection(rd, s);
//	cout << p.first << endl;
//	if(p.first){
//		p.second.first->print();
//	}

}


