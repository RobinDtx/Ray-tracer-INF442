#include <iostream>
using namespace std;
#include "Vector.h"
#include "RayDataStructure.h"
#include "Color.h"
#include "Sphere.h"
#include "Scene.h"
#include "Light.h"

#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"

using namespace cv;


std::ostream& operator<<(std::ostream &flux, const Vector& v )
{
    v.print(flux);
    return flux;
}

int main(int argc, char** argv)
{
	Vector test (1,2,3);
	Color couleur (0,12,600);
	Light light(test,couleur);
    light.print();
	//test2.add(0,0,1.5);
	//test.multiply(1.1);
//	if (test==test2)
//	{
//	    std::cout << test.module();
//	}

    char image_window[] = "Drawing: test";
    Mat image_test = Mat::zeros(400,400, CV_8UC3);
    Vec3b couleurp = Vec3b(100,0,0);
    for(int i = 150; i< 250; i++){
    	for(int j = 150; j < 250; j++){
    		image_test.at<Vec3b>(i,j) = couleurp;
    	}
    }
    imshow(image_window, image_test);
    waitKey(0);
}


