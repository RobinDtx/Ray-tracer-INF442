/*
 * Algorithm.h
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include "RayDataStructure.h"
#include <utility>
#include <vector>
#include <fstream>
#include "Sphere.h"
#include "Light.h"
#include "Scene.h"
#include "Camera.h"
#include "Materiau.h"


class Algorithm {
	public:
		Algorithm();
		Algorithm(std::vector<Light> arg_lights, Scene arg_scene, Camera arg_camera, Materiau arg_materiau);
		virtual ~Algorithm();

		std::pair<bool, std::pair<Vector*, double> > ray_sphere_intersection(RayDataStructure* rd, Sphere* s);
		Color phong_reflection_model(const Vector* point, const Vector* normal, const Sphere* s); //A besoin des 9 k et alpha, de la couleur ambiante, de l'oeil, des lights (couleur et position)
		void ray_traced_algorithm();
		void ecrire();

	private:
		std::vector<Light> lights;
		Scene scene;
		Camera camera;
		Materiau materiau;
		std::vector<std::vector<Color> > c;
		bool debug;
};

#endif /* ALGORITHM_H_ */
