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
		RayDataStructure(const Vector *origin, const Vector *direction);
		virtual ~RayDataStructure();
		void setOrigin(Vector *origin);
		void setDirection(Vector *direction);
		const Vector* getOrigin() const;
		const Vector* getDirection() const;
		void print() const;

	private:
		Vector origin;
		Vector direction;
};

#endif /* RAYDATASTRUCTURE_H_ */
