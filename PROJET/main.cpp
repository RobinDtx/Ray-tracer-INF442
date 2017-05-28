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


std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main(int argc, char** argv)
{
	Vector test (1,2,3);
	Color couleur (255,255,255);
	Light light(test,couleur);
    light.print();

    std::vector<Light> lights;
    lights.push_back(light);

    Sphere sphere(0,10,0, 1, 255, 255, 255);
    Color intensiteAmbiante(0,0,0);
    Scene scene(&intensiteAmbiante);
    scene.push_back(sphere);


    Materiau materiau (0.5,0.5,0.5,1);


    Vector point(0,9,0);
    Vector normale(0,-1,0);

    Vector eye(0,0,0);
    Vector target (0,10,0);
    Vector up(0,0,1);
    Camera camera(&eye, &target, &up, 10, 10);

    Algorithm algo(lights, scene, camera, materiau);
    algo.phong_reflection_model(&point,&normale).print();

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
}


