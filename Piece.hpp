#include "Objet.hpp"
#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED


#include <string>
#include <SDL/SDL.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <list>

class Piece{
	private:
	SDL_Rect position;
	int largeur;
	int longueur;
	SDL_Surface *fond;
	std::list<Objet>tab_objet;

	public:
	Piece();
	std::list<Objet>get_tab();
	Piece(int large,int longe,std::string path);
	~Piece();
	int get_largeur() const;
	int get_longueur() const;
	int get_taille_tab() const;
	void set_largeur(const int large1);
	void set_longueur(const int longe1);
	void add_objet(Objet &obj);
	void remove_objet(const int indice);
	SDL_Surface* get_image_obj(const int indice);
	SDL_Surface* get_image();
	SDL_Rect* get_position();
	SDL_Rect* get_position_obj(const int indice);
	const int get_type_obj(const int indice);
	void set_type_obj(const int indice,const int t);
	void set_image(std::string path);
	void add_objet2(Objet &obj);




};


#endif // PIECE_HPP_INCLUDED
