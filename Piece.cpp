#include "Piece.hpp"

		/*CONSTRUCTEURS*/

Piece :: Piece(){
	largeur=0;
	longueur=0;
	position.x=0;
	position.y=0;
}

Piece :: Piece(int large,int longe,std::string path){
	largeur = large;
	longueur = longe;
	fond=SDL_LoadBMP(path.c_str());//on converti string en const char*
	position.x=0;
	position.y=0;
}

Piece :: ~Piece(){
	 SDL_FreeSurface(fond); /* On libère la surface */
}

		/* METHODES */

int Piece :: get_largeur() const{
	return this->largeur;
}

int Piece :: get_longueur() const{
	return this->longueur;
}

void Piece :: set_largeur(const int large1){
	this->largeur=large1;
}

void Piece :: set_longueur(const int longe1){
	this->longueur=longe1;
}

void Piece :: add_objet(Objet &obj){
	this->tab_objet.push_back(obj);
}

void Piece :: add_objet2(Objet &obj){
	std::list<Objet>::iterator it = tab_objet.end();
	this->tab_objet.insert(it,obj);
}


std::list<Objet>  Piece :: get_tab(){
	return tab_objet;
}

void Piece :: remove_objet(const int indice){
	std::list<Objet>::iterator it = tab_objet.begin();
	std::advance(it, indice);
	tab_objet.erase(it);
}

SDL_Surface* Piece :: get_image_obj(const int indice){
	std::list<Objet>::iterator it = tab_objet.begin();
	std::advance(it, indice);
	return it->get_image();
}

SDL_Surface* Piece :: get_image(){
	return this->fond;
}


SDL_Rect* Piece :: get_position(){
	return &this->position;
}

SDL_Rect* Piece :: get_position_obj(const int indice){
	std::list<Objet>::iterator it = tab_objet.begin();
	std::advance(it, indice);
	return it->get_position();
	
}

void Piece :: set_image(std::string path){
      	this->fond=SDL_LoadBMP(path.c_str());
	if(fond==NULL){
		std::cout<<"Impossible de charger l'image de l'avatar"<<std::endl;
	}
}

int Piece :: get_taille_tab() const{
	return tab_objet.size();
}


const int Piece :: get_type_obj(const int indice){
	std::list<Objet>::iterator it = tab_objet.begin();
	std::advance(it, indice);
	return it->get_type();
}

void Piece :: set_type_obj(const int indice,const int t){
	std::list<Objet>::iterator it = tab_objet.begin();
	std::advance(it, indice);
	it->set_type(t);
}
	
	
	
