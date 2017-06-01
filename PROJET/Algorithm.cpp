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
    double red = 0;
	double green = 0;
	double blue = 0;
    for (std::vector<Light>::iterator it = lights.begin();it!=lights.end();it++)
    {
        red+=it->getColor()->getRed();
        green+=it->getColor()->getGreen();
        blue+=it->getColor()->getBlue();
    }

    red/=lights.size();
    green/=lights.size();
    blue/=lights.size();
    Color couleur(red,green,blue);
    scene.setIa(&couleur);
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



Color Algorithm::phong_reflection_model(const Vector* p, const Vector* n, const Sphere* s){
    //A besoin des 9 k et alpha, de la couleur ambiante, de l'oeil, des lights (couleur et position)

	double Ipr = 0;
	double Ipg = 0;
	double Ipb = 0;

	double kar = s->getMateriau()->getKar();
	double kag = s->getMateriau()->getKag();
	double kab = s->getMateriau()->getKab();

	const Color* ia = scene.getIa();

	Ipr = kar*ia->getRed();
	Ipg = kag*ia->getGreen();
	Ipb = kab*ia->getBlue();

	Vector N(*n);
	N.normalize();

	Vector V(p, camera.getEye());
	V.normalize();

    if (debug)
    {
        cout << "Normalized N : " ;
        N.print();
        cout << "Normalized V : ";
        V.print();
    }


	double kdr = s->getMateriau()->getKdr();
	double kdg = s->getMateriau()->getKdg();
	double kdb = s->getMateriau()->getKdb();

	double ksr = s->getMateriau()->getKsr();
	double ksg = s->getMateriau()->getKsg();
	double ksb = s->getMateriau()->getKsb();

	for(vector<Light>::iterator it = lights.begin(); it != lights.end(); it++){
		double coef = 1;
		Vector *source = new Vector(*(it->getSource()));
		for(vector<Sphere>::iterator jt = scene.begin(); jt != scene.end(); jt++){
			if(&*jt != s){
				Vector dir(*p - *source);
				RayDataStructure *rd = new RayDataStructure(source, &dir);
				std::pair<bool, std::pair<Vector*, double> > pa = ray_sphere_intersection(rd, &*jt);
				if(pa.first){
					Vector d1 = *p - *source;
					double dist1 = d1.module();
					Vector d2 = *pa.second.first - *source;
					double dist2 = d2.module();
					if(dist2 < dist1){
						coef *= 0.2;
					}
				}
				delete rd;
			}
		}
		const Color* color = it->getColor();
		Vector L(p, it->getSource());
		L.normalize();
		if(debug)
        {
            cout << "Normalized L : ";
            L.print();
        }


		Vector R = 2*Vector::scalar(&L, &N)*N - L;
		R.normalize();
		if (debug) {
            cout << "Normalized R : ";
            R.print();
		}

		double PS1 = Vector::scalar(&L, &N);

		double PS2 = max(0.,Vector::scalar(&R, &V));
		if (debug)
        {
            cout << "PS1 L.N : " << PS1 << endl;
            cout << "PS2 R.V : " << PS2 << endl;
            cout << Ipr << "/" << Ipg << "/" << Ipb << "/" << endl;
        }

		if (PS1<=0) {PS2=0;}



        Ipr += (kdr * max(0.,PS1) * color->getRed())*coef;
		Ipg += (kdg * max(0.,PS1) * color->getGreen())*coef;
		Ipb += (kdb * max(0.,PS1) * color->getBlue())*coef;

		if (debug) {cout << Ipr << "/" << Ipg << "/" << Ipb << "/" << endl;}


		Ipr += (ksr * pow(PS2, s->getMateriau()->getAlpha()) * color->getRed())*coef;
		Ipg += (ksg * pow(PS2, s->getMateriau()->getAlpha()) * color->getGreen())*coef;
		Ipb += (ksb * pow(PS2, s->getMateriau()->getAlpha()) * color->getBlue())*coef;

		if (debug) {cout << Ipr << "/" << Ipg << "/" << Ipb << endl << endl;}

    delete source;

	}

	return(Color(Ipr, Ipg, Ipb));
}

Color Algorithm::compute_reflection_rec(RayDataStructure *rd, Sphere *s, Vector *n, int nombre){
	std::pair<bool, std::pair<Vector*, double> > tmp;
	bool intersect;
	Vector* p_on_sphere;
	Vector normal;
	Sphere *new_s;
	double t;
	for(vector<Sphere>::iterator it = scene.begin(); it != scene.end(); it++){
		if(&*it != s){
			tmp = ray_sphere_intersection(rd, &*it);
			if(!intersect){
				intersect = tmp.first;
				if(tmp.first){
					t = tmp.second.second;
					p_on_sphere = tmp.second.first;
					normal = *p_on_sphere - *(it->getCenter());
					new_s = &*it;
				}
			}
			else{
				if(tmp.first){
					if(tmp.second.second < t){
						t = tmp.second.second;
						p_on_sphere = tmp.second.first;
						normal = *p_on_sphere - *(it->getCenter());
						new_s = &*it;
					}
				}
			}
		}
	}
	if((intersect) && (nombre < 10)){
		nombre++;
		rd->setOrigin(p_on_sphere);
		Vector direction = -2*Vector::scalar(&normal, rd->getDirection()) * normal + *rd->getDirection();
		rd->setDirection(&direction);
		Color cs = this->phong_reflection_model(p_on_sphere, &normal, new_s);
		Color cr = this->compute_reflection_rec(rd, s, &normal, nombre);
		return(new_s->getR() * cr + (1 - new_s->getR()) * cs);
	}
	else{
		Color col = this->phong_reflection_model(rd->getOrigin(), n, s);
		return(col);
	}
}

void Algorithm::ray_traced_algorithm(){

	int width = camera.getWidth();
	int heigh = camera.getHeigh();
	const Vector *eye = camera.getEye();
	const Vector *target = camera.getTarget();
	Vector orientation(*camera.getOrientation());
	orientation.normalize();
	Vector direction(*target - *eye);
	direction.normalize();
	Vector abscisse = *(Vector::vectorial_dot(&direction, &orientation));
	abscisse.normalize();

	for (int i = 0; i< heigh; i++){
		vector<Color> d;
		for(int j = 0; j < width; j++){
			Vector point_cible = *target + (heigh/2 - i) * orientation + (j-width/2) * abscisse;
			Vector dir_cible = point_cible - *eye;
			RayDataStructure rd(eye, &dir_cible);
			bool intersect = false;
			std::pair<bool, std::pair<Vector*, double> > tmp;
			double t; //distance du point à l'oeil
			Vector* p_on_sphere; //point sur la sphère
			Vector normal; //normale
			Sphere *s;
			for(vector<Sphere>::iterator it = scene.begin(); it != scene.end(); it++){ //on regarde la plus proche sphère qui intersecte
				tmp = ray_sphere_intersection(&rd, &*it);
				if(!intersect){ //si on a pas encore trouvé d'intersection
					intersect = tmp.first;
					if(tmp.first){
						t = tmp.second.second;
						p_on_sphere = tmp.second.first;
						normal = *p_on_sphere - *(it->getCenter());
						s = &*it;
					}
				}
				else{
					if(tmp.first){ //si on a intersecté
						if(tmp.second.second < t){ //et qu'on est plus près
							p_on_sphere = tmp.second.first;
							normal = *p_on_sphere - *(it->getCenter());
							s = &*it;
						}
					}
				}
			}

			if(intersect){
				rd.setOrigin(p_on_sphere);
				point_cible = -2*Vector::scalar(&dir_cible, &normal) * normal + dir_cible;
				rd.setDirection(&point_cible);
				Color cs = this->phong_reflection_model(p_on_sphere, &normal, s);
				Color cr = this->compute_reflection_rec(&rd, s, &normal, 1);
				d.push_back(s->getR() * cr + (1 - s->getR()) * cs );
			}
			else{
				d.push_back(*scene.getIa());
			}
		}
		c.push_back(d);
	}

}

void Algorithm::ecrire(string nom){
	string const nomFichier("fichier/"+nom+".ppm");
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
