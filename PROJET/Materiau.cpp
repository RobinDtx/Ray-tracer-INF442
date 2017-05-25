/*
 * Materiau.cpp
 *
 *  Created on: 25 mai 2017
 *      Author: egoutierre
 */

#include "Materiau.h"

Materiau::Materiau() {
	ka = 0;
	kd = 0;
	ks = 0;
	alpha = 0;
}

Materiau::Materiau(double ka, double kd, double ks, double alpha){
	if(ka<0){
		this->ka = 0;
	}
	else if(ka > 1 ){
		this->ka = 1;
	}
	else{
		this->ka = ka;
	}

	if(kd <0){
		this->kd = 0;
	}
	else if(kd>1){
		this->kd = 1;
	}
	else{
		this->kd = kd;
	}

	if(ks <0){
		this->ks = 0;
	}
	else if(ks>1){
		this->ks = 1;
	}
	else{
		this->ks = ks;
	}

	this->alpha = alpha;
}


double Materiau::getKa() const{
	return(ka);
}

double Materiau::getKd() const{
	return(kd);
}

double Materiau::getKs() const{
	return(ks);
}

double Materiau::getAlpha() const{
	return(alpha);
}

void Materiau::setKa(double ka){
	if(ka<0){
		this->ka = 0;
	}
	else if(ka>1){
		this->ka = 1;
	}
	else{
		this->ka = ka;
	}
}

void Materiau::setKd(double kd){
	if(kd<0){
		this->kd = 0;
	}
	else if(kd>1){
		this->kd = 1;
	}
	else{
		this->kd = kd;
	}
}

void Materiau::setKs(double ks){
	if(ks<0){
		this->ks = 0;
	}
	else if(ks>1){
		this->ks = 1;
	}
	else{
		this->ks = ks;
	}
}

void Materiau::setAlpha(double alpha){
	this->alpha = alpha;
}

Materiau::~Materiau() {
	// TODO Auto-generated destructor stub
}

