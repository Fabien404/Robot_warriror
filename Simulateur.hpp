#ifndef SIMULATEUR_HPP_INCLUDED
#define SIMULATEUR_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Piece.hpp"
#include "Avatar.hpp"
#include "Avatar_humain.hpp"
#include "Avatar_IA.hpp"
#include "Sprite.hpp"
#include "Objet.hpp"
#include "Objet_meca.hpp"
#include "Objet_elec.hpp"
#include "Objet_arme.hpp"
#include "Objet_menu.hpp"

class Simulateur{

	typedef struct{
	    SDL_Surface* screen;
	    SDL_Surface** images;
	    int nbimg;
	    Sprite* sprites;
	    int nb_sprite;
	    int XRES,YRES;
	} Context;

	private:
	Avatar_humain j1;
	Avatar_IA j2;
	Piece ma_piece;
	Objet_meca obj_meca1,obj_meca2,obj_meca3,obj_meca4;
	Objet_menu menu_1,menu_2,menu_3;
	Objet_elec obj_elec1,obj_elec2,obj_elec3;
	Objet_arme obj_arme1,obj_arme2;

	public:
	Simulateur();
	void menu(SDL_Rect souris);
	void menu_aide_options();
	void menu_leader();
	int single_player(SDL_Rect souris);
	void change_niveau(Avatar *j,int arme,int elec,int meca);
	void UpdateEvents(char* keys);
	int Blit(SDL_Surface* src,SDL_Surface* dst,int x,int y);
	int LoadAll(Context* C,Avatar* j1,Avatar* j2,int nb_obj);
	int InitialisationSprites(Context* C);
	int Initialisation(Context* C,int x,int y,int nb_sprite,Avatar* j1,Avatar* j2,int nb_obj);
	int Destruct(Context* C);
	void Refresh(Context* C,char* key);
	void Affiche(Context* C);
	int multi_player(SDL_Rect souris);
	void refresh_objet();
	void affiche_meca(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i);
	void affiche_elec(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i);
	void affiche_arme(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i);
	void PrintSDL(SDL_Surface* font,SDL_Surface* dest,int x,int y,char* text,...);


};



#endif // SIMULATEUR_HPP_INCLUDED
