/*
 * Materiau.cpp
 *
 *  Created on: 25 mai 2017
 *      Author: egoutierre
 */

#include "Materiau.h"

Materiau::Materiau() {
	kar = 0;
	kag = 0;
	kab = 0;

	kdr = 0;
	kdg = 0;
	kdb = 0;

	ksr = 0;
	ksg = 0;
	ksb = 0;

	alpha = 0;
}

Materiau::Materiau(double ka, double kd, double ks, double alpha){
	if(ka<0){
		this->kar = 0;
		this->kag = 0;
		this->kab = 0;
	}
	else if(ka > 1 ){
		this->kar = 1;
		this->kag = 1;
		this->kab = 1;
	}
	else{
		this->kar = ka;
		this->kag = ka;
		this->kab = ka;
	}

	if(kd <0){
		this->kdr = 0;
		this->kdg = 0;
		this->kdb = 0;
	}
	else if(kd>1){
		this->kdr = 1;
		this->kdg = 1;
		this->kdb = 1;
	}
	else{
		this->kdr = kd;
		this->kdg = kd;
		this->kdb = kd;
	}

	if(ks <0){
		this->ksr = 0;
		this->ksg = 0;
		this->ksb = 0;
	}
	else if(ks>1){
		this->ksr = 1;
		this->ksg = 1;
		this->ksb = 1;
	}
	else{
		this->ksr = ks;
		this->ksg = ks;
		this->ksb = ks;
	}

	this->alpha = alpha;
}


double Materiau::getKar() const{
	return(kar);
}

double Materiau::getKag() const{
	return(kag);
}

double Materiau::getKab() const{
	return(kab);
}

double Materiau::getKdr() const{
	return(kdr);
}

double Materiau::getKdg() const{
	return(kdg);
}

double Materiau::getKdb() const{
	return(kdb);
}

double Materiau::getKsr() const{
	return(ksr);
}

double Materiau::getKsg() const{
	return(ksg);
}

double Materiau::getKsb() const{
	return(ksb);
}

double Materiau::getAlpha() const{
	return(alpha);
}

void Materiau::setKa(double ka){
	if(ka<0){
		this->kar = 0;
		this->kag = 0;
		this->kab = 0;
	}
	else if(ka>1){
		this->kar = 1;
		this->kag = 1;
		this->kab = 1;
	}
	else{
		this->kar = ka;
		this->kag = ka;
		this->kab = ka;
	}
}

void Materiau::setKd(double kd){
	if(kd<0){
		this->kdr = 0;
		this->kdg = 0;
		this->kdb = 0;
	}
	else if(kd>1){
		this->kdr = 1;
		this->kdg = 1;
		this->kdb = 1;
	}
	else{
		this->kdr = kd;
		this->kdg = kd;
		this->kdb = kd;
	}
}

void Materiau::setKs(double ks){
	if(ks<0){
		this->ksr = 0;
		this->ksg = 0;
		this->kdb = 0;
	}
	else if(ks>1){
		this->ksr = 1;
		this->ksg = 1;
		this->ksb = 1;
	}
	else{
		this->ksr = ks;
		this->ksg = ks;
		this->ksb = ks;
	}
}

void Materiau::setAlpha(double alpha){
	this->alpha = alpha;
}

Materiau::~Materiau() {
	// TODO Auto-generated destructor stub
}

