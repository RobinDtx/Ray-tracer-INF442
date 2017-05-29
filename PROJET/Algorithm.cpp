/*
 * Algorithm.cpp
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#include "Algorithm.h"
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

Algorithm::Algorithm() {
}

Algorithm::~Algorithm() {
	// TODO Auto-generated destructor stub
}

Algorithm::Algorithm(std::vector<Light> arg_lights, Scene arg_scene, Camera arg_camera, Materiau arg_materiau) : lights(arg_lights), scene(arg_scene), camera(arg_camera), materiau(arg_materiau)
{

}

std::pair<bool, std::pair<Vector*, double> > Algorithm::ray_sphere_intersection(RayDataStructure* rd, Sphere* s){
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
		return(std::make_pair(false, std::make_pair(new Vector(), 0)));
	}
	double t1 = (-beta-sqrt(delta)) / (2*alpha);
	double t2 = (-beta + sqrt(delta)) / (2*alpha);

	Vector *p1 = new Vector(o->x() + t1* d->x(), o->y() + t1*d->y(), o->z() + t1*d->z());
	Vector *p2 = new Vector(o->x() + t2* d->x(), o->y() + t2*d->y(), o->z() + t2*d->z());

	if(t1 < 0){
		if(t2 <0){
			return(std::make_pair(false, std::make_pair(new Vector(), 0)));
		}
		else{
			return(std::make_pair(true, std::make_pair(p2, t2)));
		}
	}
	else{
		if(t2 < 0){
			return(std::make_pair(true, std::make_pair(p1, t1)));
		}
		else{
			if(t1 < t2){
				return(std::make_pair(true, std::make_pair(p1, t1)));
			}
			else{
				return(std::make_pair(true, std::make_pair(p2, t2)));
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

Color Algorithm::phong_reflection_model(const Vector* p, const Vector* n){
    //A besoin des 9 k et alpha, de la couleur ambiante, de l'oeil, des lights (couleur et position)

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

	cout << Ipr << "/" << Ipg << "/" << Ipb << "/" << endl;


	Vector N(*n);
	N.normalize();

	Vector V(p, camera.getEye());
	V.normalize();

	cout << "Normalized N : " ;
	N.print();
	cout << "Normalized V : ";
	V.print();

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
		cout << "Normalized L : ";
		L.print();

		Vector R = 2*Vector::scalar(&L, &N)*N - L;
		R.normalize();
		cout << "Normalized R : ";
		R.print();

		double PS1 = Vector::scalar(&L, &N);
		cout << "PS1 L.N : " << PS1 << endl;
		double PS2 = max(0.,Vector::scalar(&R, &V));
		cout << "PS2 R.V : " << PS2 << endl;
		if (PS1<=0) {PS2=0;}

		cout << Ipr << "/" << Ipg << "/" << Ipb << "/" << endl;

        Ipr += kdr * max(0.,PS1) * color->getRed();
		Ipg += kdg * max(0.,PS1) * color->getGreen();
		Ipb += kdb * max(0.,PS1) * color->getBlue();

		cout << Ipr << "/" << Ipg << "/" << Ipb << "/" << endl;

		Ipr += ksr * pow(PS2, materiau.getAlpha()) * color->getRed();
		Ipg += ksg * pow(PS2, materiau.getAlpha()) * color->getGreen();
		Ipb += ksb * pow(PS2, materiau.getAlpha()) * color->getBlue();

		cout << Ipr << "/" << Ipg << "/" << Ipb << endl;

	}

	return(Color(Ipr, Ipg, Ipb));
}

void Algorithm::ray_traced_algorithm(){

	int width = camera.getWidth();
	int heigh = camera.getHeigh();
	Vector orientation(*camera.getOrientation());
	orientation.normalize();
	Vector direction(*camera.getTarget() - *camera.getEye());
	direction.normalize();
	Vector *abscisse_p = Vector::vectorial_dot(&direction, &orientation);
	Vector abscisse = *abscisse_p;
	abscisse.normalize();
	const Vector *eye = camera.getEye();
	const Vector *target = camera.getTarget();
	for (int i = 0; i< heigh; i++){
		vector<Color> d;
		for(int j = 0; j < width; j++){
			Vector point_cible = *target + (heigh/2 - i) * orientation + (j-width/2) * abscisse;
			Vector dir_cible = point_cible - *eye;
			RayDataStructure rd(eye, &dir_cible);
			bool intersect = false;
			std::pair<bool, std::pair<Vector*, double> > tmp;
			double t;
			Vector* p_on_sphere;
			Vector normal;
			for(vector<Sphere>::iterator it = scene.begin(); it != scene.end(); it++){
				tmp = ray_sphere_intersection(&rd, &*it);
				if(!intersect){
					intersect = tmp.first;
					if(tmp.first){
						t = tmp.second.second;
						p_on_sphere = tmp.second.first;
						normal = *p_on_sphere - *(it->getCenter());
					}
				}
				else{
					if(tmp.first){
						if(tmp.second.second < t){
							p_on_sphere = tmp.second.first;
							normal = *p_on_sphere - *(it->getCenter());
						}
					}
				}
			}


			//vector<Sphere>::iterator it = scene.begin();

			//while((!intersect) && (it != scene.end())){
			//	p = ray_sphere_intersection(&rd, &*it);
			//	intersect = p.first;
			//	it++;
			//}
			if(intersect){
				//const Vector* p_on_sphere = p.second;
				//Vector normal = *p_on_sphere - *(it->getCenter());
				Color col = this->phong_reflection_model(p_on_sphere, &normal);
				d.push_back(col);
			}
			else{
				d.push_back(*scene.getIa());
			}
		}
		c.push_back(d);
	}

}

void Algorithm::ecrire(){
	string const nomFichier("fichier/couleur.ppm");
	ofstream monFlux(nomFichier.c_str());
	if(monFlux){
		monFlux << "P3" << endl;
		monFlux << c[0].size();
		monFlux << " ";
		monFlux << c.size() << endl;
		monFlux << 255 << endl;
		for(vector<vector <Color> >::iterator i = c.begin(); i != c.end(); i++){
			for(vector<Color>::iterator j = i->begin(); j != i->end(); j++){
				monFlux << j->getRed();
				monFlux << " ";
				monFlux << j->getGreen();
				monFlux << " ";
				monFlux << j->getBlue();
				if(j<i->end()-1){
					monFlux << "\t";
				}
			}
			monFlux << endl;
		}
	}
	else{
		cout << "Problème" << endl;
	}
}
