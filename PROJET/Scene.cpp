#include "Scene.h"

Scene::Scene()
{
	ia = 0;
    //ctor
}

Scene::Scene(double ia){
	if(ia <0){
		this-> ia = 0;
	}
	else{
		this->ia = ia;
	}
}

Scene::~Scene()
{
    //dtor
}

