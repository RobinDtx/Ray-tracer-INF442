#include "Scene.h"

Scene::Scene()
{

}

Scene::Scene(Color* ia){
	this->ia = Color(ia->getRed(), ia->getGreen(), ia->getBlue());
}

Scene::~Scene()
{
    //dtor
}

const Color* Scene::getIa() const{
	return(&ia);
}

void Scene::setIa(Color* ia){
	this->ia.setRed(ia->getRed());
	this->ia.setGreen(ia->getGreen());
	this->ia.setBlue(ia->getBlue());
}

