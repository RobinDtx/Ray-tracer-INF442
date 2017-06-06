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


    Materiau jaune (0.5,0.5,0,0.4,0.4,0,0.1,0.1,0.1,50);
    Materiau vert (0,0.4,0,0,0.1,0,0.05,0.05,0.05,50);
    Scene scene;
    std::vector<Light> lights;

//    //Vision à l'infini
//    Sphere sphere(0, -250, 0, 100, &jaune, 0);
//    scene.push_back(sphere);
//
//
//	Vector origineLumiere (0,0,1000000);
//	Color couleurLumiere (255,255,255);
//	Light light(origineLumiere,couleurLumiere);
//    lights.push_back(light);
//        //Vision près
//        string nomFichier = "visionpres";
//        Vector eye(-300,0,0);
//
//
//        //Vision loin
//        string nomFichier = "visionloin";
//        Vector eye(-100000,0,0);




//    //Changement alpha
//
//    Vector eye(-100000,0,0);
//
//	Vector origineLumiere (0,0,1000000);
//	Color couleurLumiere (255,255,255);
//	Light light(origineLumiere,couleurLumiere);
//    lights.push_back(light);
//        //Vision près
//        string nomFichier = "alpha50";
//        Sphere sphere(0, 0, 0, 500, &jaune, 0);
//
//
//        //Vision loin
//        string nomFichier = "alpha500";
//        Materiau jaunebis (0.5,0.5,0,0.4,0.4,0,0.1,0.1,0.1, 500);
//        Sphere sphere(0, 0, 0, 500, &jaunebis, 0);
//
//    scene.push_back(sphere);

//    //Changement réflexion
//
//    Vector eye(-100000,0,0);
//
//	Vector origineLumiere (-10000,-1000000,1000000);
//	Color couleurLumiere (255,255,255);
//	Light light(origineLumiere,couleurLumiere);
//
//    lights.push_back(light);
//        //Sans réflexion
//        string nomFichier = "sansreflexion";
//        Sphere sphere(0, 0, 0, 500, &jaune, 0);
//        Sphere sphere2(-600, -300, 0, 100, &vert, 0);
//
//
//        //Sans réflexion
//        string nomFichier = "avecreflexion";
//        Sphere sphere(0, 0, 0, 500, &jaune, 0.2);
//        Sphere sphere2(-600, -300, 0, 100, &vert, 0);
//
//        //Avec réflexion mais on voit pas la sphère
//        string nomFichier = "avecreflexionbis";
//        Sphere sphere(0, 0, 0, 500, &jaune, 0.2);
//        Sphere sphere2(-800, -800, 0, 100, &vert, 0);
//
//
//    scene.push_back(sphere);
//    scene.push_back(sphere2);







    //Ombre
    	// Pas d'ombre : aller mettre le coef à 1
    ////// WARNING !!!!!!!!!! : Commenter la ligne dans algorithme.cpp
    /*
    Vector eye(-100000000, 100000000, 50000000);

    string nomFichier = "pasdombre";
    Sphere sol(0,0,-1000000, 1000000, &vert, 0);
    Sphere sphereVolante(0,0,250,250, &jaune, 0);
    scene.push_back(sol);
    scene.push_back(sphereVolante);

    Vector origineLumiere (0,1000000,1000000);
    Color couleurLumiere(255,255,255);
    Light light(origineLumiere,couleurLumiere);
    lights.push_back(light);
	*/

    	// Avec ombre :
    ////// WARNING !!!!!!!!!! : Décommenter la ligne dans algorithme.cpp
    /*

    Vector eye(-100000000, 100000000, 50000000);

    string nomFichier = "avecombre";
    Sphere sol(0,0,-1000000, 1000000, &vert, 0);
    Sphere sphereVolante(0,0,250,250, &jaune, 0);
    scene.push_back(sol);
    scene.push_back(sphereVolante);

    Vector origineLumiere (0,1000000,1000000);
    Color couleurLumiere(255,255,255);
    Light light(origineLumiere,couleurLumiere);
    lights.push_back(light);
    */

    	// Avec double ombre
    /*
    Vector eye(-100000000, 0, 50000000);
    string nomFichier = "avecplusieurombre";
    Sphere sol(0,0,-1000000, 1000000, &vert, 0);
    Sphere spherePose1(-250,250,250,250, &jaune, 0);
    Sphere spherePose2(-250,-250,250,250, &jaune, 0);
    scene.push_back(sol);
    scene.push_back(spherePose1);
    scene.push_back(spherePose2);

    Vector origineLumiere1(-100000,100000,100000);
    Vector origineLumiere2(100000,100000,100000);
    Color couleurLumiere(255,255,255);
    Light light1(origineLumiere1,couleurLumiere);
    Light light2(origineLumiere2,couleurLumiere);
    lights.push_back(light1);
    lights.push_back(light2);
	*/
    //Partie commune


    Vector target (0,0,0);
    Vector up(0,0,1);
    Camera camera(&eye, &target, &up, 1400, 1400);

    Algorithm algo(lights, scene, camera, jaune);
    algo.ray_traced_algorithm();
    algo.ecrire(nomFichier);



}


