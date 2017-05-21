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
#include "Sphere.h"


class Algorithm {
	public:
		Algorithm();
		virtual ~Algorithm();

		static std::pair<bool, Vector*> ray_sphere_intersection(RayDataStructure* r, Sphere* s);
};

#endif /* ALGORITHM_H_ */
