#include "Avatar.hpp"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Avatar :: Avatar(){
	niveau=0;
	life=0;
	nb_meca=0;
	nb_elec=0;
	nb_arme=0;
}

Avatar:: Avatar(int niv,std::string path,int x,int y){
	niveau = niv;
	life=10;
	nb_meca=0;
	nb_elec=0;
	nb_arme=0;
	position.x=x;
	position.y=y;
	image=SDL_LoadBMP(path.c_str());//on converti string en const char*
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'avatar"<<std::endl;
	}
}

Avatar:: ~Avatar(){
	SDL_FreeSurface(image);
}

		/* METHODES */

int Avatar :: get_niveau() const{
	return this->niveau;
}

void Avatar :: maj_niveau(){
	if(nb_meca>=2){
		niveau=1;
		image=SDL_LoadBMP("src/robot_l2.bmp");
	}
	if(nb_meca>=3 && nb_elec>=2){
		niveau=2;
		image=SDL_LoadBMP("src/robot_l3.bmp");
	}
	if(nb_meca>=4 && nb_elec>=3 && nb_arme>=1){
		niveau=3;
		image=SDL_LoadBMP("src/robot_l4.bmp");
	}
}

SDL_Surface* Avatar :: get_image(){
	return this->image;
}

void Avatar :: set_image(std::string path){
      	this->image=SDL_LoadBMP(path.c_str());
	if(image==NULL){
		std::cout<<"Impossible de charger l'image de l'avatar"<<std::endl;
	}
}

void Avatar :: set_x(const int x1){
	this->position.x=x1;
}

void Avatar :: set_y(const int y1){
	this->position.y=y1;
}

SDL_Rect* Avatar :: get_position(){
	return &this->position;
}

void Avatar :: touch_object(Piece &room){
	int longueur = image->h;
	int largeur = image->w;
	int longueur2 = 0;
	int largeur2 = 0;
	int pos_x_avatar=position.x,pos_y_avatar=position.y,pos_x_obj=0,pos_y_obj=0;

	for(int i=0;i<room.get_taille_tab();i++){
    		longueur2=room.get_image_obj(i)->h;
    		largeur2=room.get_image_obj(i)->w;
		//Recupere positions de l'objet i
		pos_x_obj=room.get_position_obj(i)->x;
		pos_y_obj=room.get_position_obj(i)->y;

		if( (pos_x_avatar > pos_x_obj + largeur2) || (pos_x_avatar + largeur < pos_x_obj)
    || (pos_y_avatar > pos_y_obj + longueur2 ) || (pos_y_avatar + longueur < pos_y_obj)) {
			//l'avatar ne touche aucun objet dans ce cas
		}
	   	else{
	   		if(room.get_type_obj(i)==1){
	   			nb_meca++;
	   		}
	   		if(room.get_type_obj(i)==2){
	   			nb_elec++;
	   		}
	   		if(room.get_type_obj(i)==3){
	   			nb_arme++;
	   		}
		    	room.remove_objet(i);
		}
	}
}

const int Avatar :: get_nb_meca(){
	return nb_meca;
}


const int Avatar :: get_nb_elec(){
	return nb_elec;
}

const int Avatar :: get_nb_arme(){
	return nb_arme;
}

void Avatar :: set_nb_meca(const int m){
    	this->nb_meca = m;
}

void Avatar :: set_nb_elec(const int e){
    	this->nb_elec = e;
}

void Avatar :: set_nb_arme(const int a){
    	this->nb_arme = a;
}

const int Avatar ::  get_life(){
    	return life;
}

void Avatar :: set_life(const int l){
    	this->life = l;
}

void Avatar :: move_aleatoire(const int mode_IA,Piece* room){ // easy : 2 , normal : 3 ; heroic : 4 ; legendaire : 5
	int nombre_alea;
    	srand(time(NULL));
    	nombre_alea = rand()%4;
    	if(mode_IA==3){
        	if(nombre_alea == 0 ){ // vers le haut
            	position.y -= mode_IA;
            	if(position.y<68){
                	position.y = 68;
            	}
        }
        if(nombre_alea == 1 ){ // vers la gauche
            position.x -= mode_IA;
            if(position.x<0){
                position.x = 0;
            }
        }
        if(nombre_alea == 2){ // vers la droite
            position.x += mode_IA;
            if(position.x+image->w>727){
                position.x = 727 - image->w;
            }
        }
        if(nombre_alea == 3 ){ // vers le bas
            position.y += mode_IA;
            if(position.y+image->h>499){
                position.y = 499 - image->h;
            }
        }
    
    }
}
