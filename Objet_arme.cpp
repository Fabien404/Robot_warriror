#include "Objet_arme.hpp"
#include <assert.h>
#include <iostream>

Objet_arme :: Objet_arme(int x1,int y1){
	position.x=x1;
	position.y=y1;
	type = 3;
	image=SDL_LoadBMP("src/missile.bmp");
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'objet"<<std::endl;
	}
}

Objet_arme :: Objet_arme(){
	image=SDL_LoadBMP("src/missile.bmp");
	type = 3;
	this->position.x=rand()%700;
	this->position.y=(rand()%341)+68;
}

void Objet_arme ::set_image(){
	image=SDL_LoadBMP("src/missile.bmp");
}

