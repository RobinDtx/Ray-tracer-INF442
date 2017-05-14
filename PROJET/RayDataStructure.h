/*
 * RayDataStructure.h
 *
 *  Created on: 14 mai 2017
 *      Author: egoutierre
 */

#ifndef RAYDATASTRUCTURE_H_
#define RAYDATASTRUCTURE_H_
#include "Vector.h"

class RayDataStructure {
	public:
		RayDataStructure();
		RayDataStructure(Vector &origin, Vector &direction);
		virtual ~RayDataStructure();
		void setOrigin(Vector &origin);
		void setDirection(Vector &direction);
		Vector* getOrigin();
		Vector* getDirection();

	private:
		Vector* origin;
		Vector* direction;
};

#endif /* RAYDATASTRUCTURE_H_ */
