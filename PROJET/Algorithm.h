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
#include "Sphere.h"
#include "Light.h"
#include "Scene.h"
#include "Camera.h"
#include "Materiau.h"


class Algorithm {
	public:
		Algorithm();
		virtual ~Algorithm();

		std::pair<bool, Vector*> ray_sphere_intersection(RayDataStructure* r, Sphere* s);
		Color phong_reflection_model(const Vector* point, const Vector* normal);
		vector<vector<Color> >* ray_traced_algorithm();

	private:
		std::vector<Light> lights;
		Scene scene;
		Camera camera;
		Materiau materiau;
};

#endif /* ALGORITHM_H_ */
