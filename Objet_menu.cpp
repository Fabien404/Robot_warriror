#include "Objet_menu.hpp"
#include <assert.h>
#include <iostream>

Objet_menu :: Objet_menu(){
	type = -1;
	image=NULL;
	this->position.x=0;
	this->position.y=0;
}

void Objet_menu ::set_image(int num){
	type=num;
	/*On charge l'image coreespondant dans l'objet en fonction de son numero de type*/
	if(num==-1){
		image=SDL_LoadBMP("src/engrenage_menu.bmp");
	}
	else{
		if(num==-2){
			image=SDL_LoadBMP("src/batterie_menu.bmp");
		}
		else{
			image=SDL_LoadBMP("src/missile-menu.bmp");
		}
	}
}
