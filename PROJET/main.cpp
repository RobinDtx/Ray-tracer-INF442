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
    Materiau jaune (0.6,0.6,0,0.3,0.3,0,0.1,0.1,0.1,50);
    Materiau vert (0,0.6,0,0,0.3,0,0.1,0.1,0.1,50);
    Scene scene;
    std::vector<Light> lights;

    //Vision à l'infini
        //Vision près
    string nomFichier = "visionpres";
    Sphere sphere(0, -250, 0, 100, &jaune, 0);
    Vector eye(-300,0,0);
    scene.push_back(sphere);


	Vector origineLumiere (0,0,1000000);
	Color couleurLumiere (255,255,255);
	Light light(origineLumiere,couleurLumiere);
    lights.push_back(light);

        //Vsio







    //Partie commune


    Vector target (0,0,0);
    Vector up(0,0,1);
    Camera camera(&eye, &target, &up, 1400, 1400);

    Algorithm algo(lights, scene, camera, jaune);
    algo.ray_traced_algorithm();
    algo.ecrire(nomFichier);



}


