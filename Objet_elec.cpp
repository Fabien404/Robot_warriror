#include "Objet_elec.hpp"
#include <assert.h>
#include <iostream>

Objet_elec :: Objet_elec(int x1,int y1){
	position.x=x1;
	position.y=y1;
	type = 2;
	image=SDL_LoadBMP("src/batterie.bmp");
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'objet"<<std::endl;
	}
}

Objet_elec :: Objet_elec(){
	image=SDL_LoadBMP("src/batterie.bmp");
	type = 2;
	this->position.x=rand()%700;
	this->position.y=(rand()%341)+68;
}

void Objet_elec :: set_image(){
	image=SDL_LoadBMP("src/batterie.bmp");
}

