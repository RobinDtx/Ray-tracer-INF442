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

	Vector test (0,50,200);

	Color couleur (255,255,255); //LUMIERE BLANCHE
	Light light(test,couleur);

	Vector test2(0, -50, -200);
	Color couleur2(255,0,100);
	Light light2(test2, couleur2);
   // light.print();

    std::vector<Light> lights; //UNE SEULE LUMIERE
    lights.push_back(light);
    lights.push_back(light2);

    Sphere sphere(2000, 0, 0, 1500, 255, 255, 255);
    Sphere sphere2(200,0,0,100,255,255,255);
    Sphere sphere3(200, 200, 0, 100, 255, 255, 255);
    Color intensiteAmbiante(255,255,255);// LUMIERE AMBIANTE
    Scene scene(&intensiteAmbiante);
    scene.push_back(sphere);
    scene.push_back(sphere2);
    //scene.push_back(sphere3);

    Color ia((couleur.getRed()+couleur2.getRed())/2, (couleur.getGreen()+couleur2.getGreen())/2, (couleur.getBlue()+couleur2.getBlue())/2);
    scene.setIa(&ia);



    Materiau materiau (0,0,0,0.8,0.8,0,0.1,0.1,0.1,50);


    Vector point(10,0,0);
    Vector normale(-1,0,0);

    Vector eye(0,0,0);
    Vector target (100,0,0);
    Vector up(0,0,1);
    Camera camera(&eye, &target, &up, 2048, 4096);

    Algorithm algo(lights, scene, camera, materiau);
    // Color res = algo.phong_reflection_model(&point,&normale);
    // res.print();

//    Vector tesuto = target - up;
//    tesuto.print();

//    string const nomFichier("fichier/couleur2.ppm");
//	ofstream monFlux(nomFichier.c_str());
//	if(monFlux){
//		monFlux << "P3" << endl;
//		monFlux << 1;
//		monFlux << " ";
//		monFlux << 1 << endl;
//		monFlux << 255 << endl;
//
//				monFlux << res.getRed();
//				monFlux << " ";
//				monFlux << res.getGreen();
//				monFlux << " ";
//				monFlux << res.getBlue();
//				monFlux << "\t";
//				monFlux << endl;
//
//	}
//	else{
//		cout << "Probl�me" << endl;
//	}


    algo.ray_traced_algorithm();
    algo.ecrire();

	//test2.add(0,0,1.5);
	//test.multiply(1.1);
//	if (test==test2)
//	{
//	    std::cout << test.module();
//	}

//    char image_window[] = "Drawing: test";
//    Mat image_test = Mat::zeros(400,400, CV_8UC3);
//    Vec3b couleurp = Vec3b(100,0,0);
//    for(int i = 150; i< 250; i++){
//    	for(int j = 150; j < 250; j++){
//    		image_test.at<Vec3b>(i,j) = couleurp;
//    	}
//    }
//    imshow(image_window, image_test);
//    waitKey(0);
//
//	RayDataStructure *rd = new RayDataStructure(new Vector(0,0,0), new Vector(3,0,0));
//	Sphere *s = new Sphere(new Vector(3,0,0), 1);
//	std::pair<bool, std::pair<Vector*, double> > p = algo.ray_sphere_intersection(rd, s);
//	cout << p.first << endl;
//	if(p.first){
//		p.second.first->print();
//	}

}


