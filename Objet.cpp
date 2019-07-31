#include "Objet.hpp"
#include <assert.h>
#include <iostream>


		/*CONSTRUCTEURS*/
Objet :: Objet(){
	position.x=0;
	position.y=0;
}

Objet :: Objet(int x1,int y1,std::string path,int ty){
	position.x=x1;
	position.y=y1;
	type = ty;
	image=SDL_LoadBMP(path.c_str());//on converti string en const char*
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'objet"<<std::endl;
	}
}

Objet :: Objet(const Objet& ob){
	position.x=ob.position.x;
	position.y=ob.position.y;
	image=ob.image;
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'objet"<<std::endl;
	}
	type=ob.type;
}

Objet :: ~Objet(){
	SDL_FreeSurface(image); /* On libère la surface */
}

		/* METHODES */

int Objet :: get_x() const{
	return this->position.x;
}

int Objet :: get_y() const{
	return this->position.y;
}

void Objet :: set_type(const int t){
	type=t;
}


int Objet :: get_type() const{
	return this->type;
}

void Objet :: set_x(const int x1){
	this->position.x=x1;
}

void Objet :: set_y(const int y1){
	this->position.y=y1;
}

SDL_Surface* Objet :: get_image(){
	return this->image;
}

SDL_Rect* Objet:: get_position(){
	return &this->position;
}

void Objet :: set_image(std::string path){
	this->image=SDL_LoadBMP(path.c_str());
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'avatar"<<std::endl;
	}
}

int Objet:: collision (const Objet& ob) const{
	int longueur = image->h;
    	int largeur = image->w;
    	int longueur2 = ob.image->h;
    	int largeur2 = ob.image->w;

	if( (position.x > ob.position.x + largeur2 )|| (position.x + largeur < ob.position.x)
    	|| ( position.y > ob.position.y + longueur2 ) || (position.y + longueur < ob.position.y)) {
	    	return 1;
	}
   	else{
	    	return 0;
	}
}

void Objet :: set_x(){
	this->position.x=rand()%700;
}

void Objet :: set_y(){
	this->position.y=(rand()%431)+68;
}

