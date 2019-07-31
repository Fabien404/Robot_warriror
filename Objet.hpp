#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>

class Objet{
	protected:
	SDL_Rect position;
	SDL_Surface *image;
	int type;

	public:
	Objet();
	Objet(const Objet& ob);
	Objet(int x1,int y1,std::string path,int ty);
	~Objet();
	int get_x() const;
	int get_y() const;
	int get_type() const;
	void set_type(const int t);
	void set_x(const int x1);
	void set_y(const int y1);
	void set_x();
	void set_y();
	void set_image();//Methode virtuel
	SDL_Surface* get_image();
	SDL_Rect* get_position();
	void set_image(std::string path);
    int collision (const Objet& ob) const;


};



#endif // OBJET_HPP_INCLUDED
