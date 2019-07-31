#ifndef AVATAR_HPP_INCLUDED
#define AVATAR_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include "Objet.hpp"
#include "Piece.hpp"

class Avatar{
	protected:
	int niveau;
	int life;
	int nb_meca;
	int nb_elec;
	int nb_arme;
	SDL_Surface *image;
	SDL_Rect position;

	public:
	Avatar();
	Avatar(int niveau,std::string path,int x,int y);
	~Avatar();
	int get_niveau() const;
	SDL_Surface* get_image();
	void maj_niveau();
	void set_image(std::string path);
	void touch_object(Piece &room);
	//methode pour mettre l'avatar a une position fixe
	void set_x(const int x1);
	void set_y(const int y1);
	//methode pour mettre l'avatar a une position aleatoire differente entre IA et humain
	virtual void set_x1()=0;
	virtual void set_y1()=0;
	SDL_Rect* get_position();
	const int get_nb_meca();
	const int get_nb_elec();
	const int get_nb_arme();
	void set_nb_meca(const int m);
	void set_nb_elec(const int e);
	void set_nb_arme(const int a);
	const int get_life();
	void set_life(const int l);
	void move_aleatoire(const int mode_IA,Piece *room);


};


#endif // AVATAR_HPP_INCLUDED
