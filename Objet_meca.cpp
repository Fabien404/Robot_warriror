#include "Objet_meca.hpp"
#include <assert.h>
#include <iostream>

Objet_meca :: Objet_meca(int x1,int y1){
	position.x=x1;
	position.y=y1;
	type = 1;
	image=SDL_LoadBMP("src/boulon.bmp");
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'objet"<<std::endl;
	}
}

Objet_meca :: Objet_meca(){
	image=SDL_LoadBMP("src/boulon.bmp");
	type = 1;
	this->position.x=rand()%700;
	this->position.y=(rand()%341)+68;
}

void Objet_meca ::set_image(){
	image=SDL_LoadBMP("src/boulon.bmp");
}
