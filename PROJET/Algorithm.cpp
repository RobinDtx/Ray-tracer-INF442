/*
 * Algorithm.cpp
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#include "Algorithm.h"
#include "Color.h"
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
    double red, green, blue;
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


		Ipr += (ksr * pow(PS2, materiau.getAlpha()) * color->getRed())*coef;
		Ipg += (ksg * pow(PS2, materiau.getAlpha()) * color->getGreen())*coef;
		Ipb += (ksb * pow(PS2, materiau.getAlpha()) * color->getBlue())*coef;

		if (debug) {cout << Ipr << "/" << Ipg << "/" << Ipb << endl << endl;}

    delete source;

	}

	return(Color(Ipr, Ipg, Ipb));
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

            Color couleurFinale;

			vector<std::pair<double, Color> > couleurs;
			int i=0;
			Sphere *s=0;
			//cout << "point";
			do
//			for (int i=0;i<2;i++)
            {


            intersect = false;

			std::pair<bool, std::pair<Vector*, double> > tmp;
			double t; //distance du point à l'oeil
			Vector* p_on_sphere; //point sur la sphère
			Vector normal; //normale

			for(vector<Sphere>::iterator it = scene.begin(); it != scene.end(); it++){ //on regarde la plus proche sphère qui intersecte

				if(s!=&*it)
				{

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
			}

			if(intersect){
//				if (debug)
//                {
//                    cout << "i : " << i << " j : " << j << endl << "Point de la sphere : ";
//                    p_on_sphere->print();
//                    cout << "Sphere : " << endl;
//                    s->print();
//                }

				//couleurFinale = this->phong_reflection_model(p_on_sphere, &normal, s);
				//col.print();

				couleurs.push_back(std::make_pair(s->getR(),phong_reflection_model(p_on_sphere,&normal,s)));

				Vector V(-1*dir_cible);
                V.normalize();
                normal.normalize();
                dir_cible = 2*Vector::scalar(&V, &normal)*normal - V;
                rd.setOrigin(p_on_sphere);
                rd.setDirection(&dir_cible);
				/*col*=1-s->getR();

				Vector point(*p_on_sphere);

				Vector N(normal);
				N.normalize();
				Vector V(*eye-point);

				V.normalize();
				Vector R = 2*Vector::scalar(&V, &N)*N - V;
				R.normalize();

				RayDataStructure reflechi(&point,&R);
				std::pair<bool, std::pair<Vector*, double> > paire;
				bool intersectionReflechi = false;
				double distance;
				Sphere *sphereReflechi;



				for(vector<Sphere>::iterator it = scene.begin(); it != scene.end(); it++){ //on regarde la plus proche sphère qui intersecte
                    if (&*it!=s)
                    {


                    paire = ray_sphere_intersection(&reflechi, &*it);
                    if(!intersectionReflechi){ //si on a pas encore trouvé d'intersection
                        intersectionReflechi = paire.first;
                        if(paire.first){
                            distance = paire.second.second;
                            point = *paire.second.first;
                            N = point - *(it->getCenter());
                            sphereReflechi = &*it;
                        }
                    }
                    else{
                        if(paire.first){ //si on a intersecté
                            if(paire.second.second < distance){ //et qu'on est plus près
                                point = *paire.second.first;
                                N = point - *(it->getCenter());
                                sphereReflechi = &*it;
                            }
                        }
                    }
                    }
                }

                if (intersectionReflechi)
                {
                    //sphereReflechi->print();
                    Color test = phong_reflection_model(&point,&N,sphereReflechi);
                    //test.print();
                    col+=s->getR()*test;
                }
                */

				//if(i==0) {d.push_back(couleurFinale);}
			}
			else{
				//if(i==0){d.push_back(*scene.getIa());}
				//couleurs.push_back(std::make_pair(0,*scene.getIa()));
			}

            i++;

			} while (intersect&&i<20);

            if (couleurs.size()==0)
            {
                //cout << "test";
                d.push_back(*scene.getIa());
            }
            else
            {
                couleurFinale=couleurs[couleurs.size()-1].second;
                for (int i=couleurs.size()-1;i>=1;i--)
                {
                    couleurFinale=couleurs[i-1].first*couleurFinale;
                    couleurFinale+=(1.0-couleurs[i-1].first)*couleurs[i-1].second;

                }
                d.push_back(couleurFinale);
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
