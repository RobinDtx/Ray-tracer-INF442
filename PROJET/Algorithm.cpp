/*
 * Algorithm.cpp
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#include "Algorithm.h"
#include <math.h>

Algorithm::Algorithm() {
}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}

std::pair<bool, Vector*> ray_sphere_intersection(RayDataStructure* rd, Sphere* s){
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
			return(std::make_pair(true, new Vector(o->x() + t2* d->x(), o->y() + t2*d->y(), o->z() + t2*d->z())));
		}
	}
	else{
		if(t2 < 0){
			return(std::make_pair(true, new Vector(o->x() + t1* d->x(), o->y() + t1*d->y(), o->z() + t1*d->z())));
		}
		else{
			if(t1 < t2){
				return(std::make_pair(true, new Vector(o->x() + t1* d->x(), o->y() + t1*d->y(), o->z() + t1*d->z())));
			}
			else{
				return(std::make_pair(true, new Vector(o->x() + t2* d->x(), o->y() + t2*d->y(), o->z() + t2*d->z())));
			}
		}
	}
}

Vector operator*(double l, Vector const& v){
	Vector copie(v);
	copie.multiply(l);
	return(copie);
}

Vector operator+(Vector const& v1, Vector const& v2){
	Vector copie(v1);
	copie += v2;
	return(copie);
}

Vector operator-(Vector const& v1, Vector const& v2){
	return(v1 + (-1)*v2);
}

Color Algorithm::phong_reflection_model(Vector* p, Vector* n){

	double Ipr = 0;
	double Ipg = 0;
	double Ipb = 0;

	double kar = materiau.getKar();
	double kag = materiau.getKag();
	double kab = materiau.getKab();

	const Color* ia = scene.getIa();

	Ipr = kar*ia->getRed();
	Ipg = kag*ia->getGreen();
	Ipb = kab*ia->getBlue();

	Vector N(*n);
	N.normalize();

	Vector V(p, camera.getEye());

	double kdr = materiau.getKdr();
	double kdg = materiau.getKdg();
	double kdb = materiau.getKdb();

	double ksr = materiau.getKsr();
	double ksg = materiau.getKsg();
	double ksb = materiau.getKsb();

	for(vector<Light>::iterator it = lights.begin(); it != lights.end(); it++){

		const Color* color = it->getColor();
		Vector L(p, it->getSource());
		L.normalize();

		Vector R = 2*Vector::scalar(&L, &N)*N - L;
		R.normalize();

		Ipr += kdr * Vector::scalar(&L, &N)*color->getRed() + ksr*Vector::scalar(&R, &V)*color->getRed();
		Ipg += kdg * Vector::scalar(&L, &N)*color->getGreen() + ksg*Vector::scalar(&R, &V)*color->getGreen();
		Ipb += kdb * Vector::scalar(&L, &N)*color->getBlue() + ksb*Vector::scalar(&R, &V)*color->getBlue();

	}

	return(Color(Ipr, Ipg, Ipb));
}









