/*
 * Algorithm.cpp
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#include "Algorithm.h"
#include <Math.h>

Algorithm::Algorithm() {
	// TODO Auto-generated constructor stub

}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}

static std::pair<bool, Vector*> ray_sphere_intersection(RayDataStructure* rd, Sphere* s){
	// On écrit l'équation paramétrique de la droite
	// On écrit l'équation cartésienne de la droite
	// On résoud le système d'équation et on dit s'il existe une solution réelle au paramètre
	const Vector* o = rd->getOrigin();
	const Vector* d = rd->getDirection();
	const Vector* c = s->getCenter();
	double r = s->getRadius();

	// On doit trouver les racines de alpha*t^2 +beta*t + gamma
	double alpha = pow(d->module(),2);
	double beta = 2*(d->x()*(o->x()-c->x()) + d->y()*(o->y()-c->y()) + d->z()*(o->z()-c->z()));
	double gamma = pow(o->x() - c->x(),2) + pow(o->y() - c->y(),2) + pow(o->z() - c->z(),2) -r*r;
	double delta = beta*beta-4*alpha*gamma;

	if(delta < 0){
		return(std::make_pair(false, new Vector()));
	}
	double t1 = (-beta-sqrt(delta)) / (2*alpha);
	double t2 = (-beta + sqrt(delta)) / (2*alpha);

	if(t1 < 0){
		if(t2 <0){
			return(std::make_pair(false, new Vector()));
		}
		else{
			return(std::make_pair(true, Vector(o->x() + t2* d->x(), o->y() + t2*d->y(), o->z() + t2*d->z())));
		}
	}
	else{
		if(t2 < 0){
			return(std::make_pair(true, Vector(o->x() + t1* d->x(), o->y() + t1*d->y(), o->z() + t1*d->z())));
		}
		else{
			if(t1 < t2){
				return(std::make_pair(true, Vector(o->x() + t1* d->x(), o->y() + t1*d->y(), o->z() + t1*d->z())));
			}
			else{
				return(std::make_pair(true, Vector(o->x() + t2* d->x(), o->y() + t2*d->y(), o->z() + t2*d->z())));
			}
		}
	}
}









