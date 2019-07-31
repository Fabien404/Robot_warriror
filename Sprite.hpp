#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Sprite{
	private:
	int im;
	int x,y;
	int vx,vy;

	public:
	int get_im();
	void set_im(int im_new);
	int get_x();
	void set_x(int im_new);
	int get_y();
	void set_y(int im_new);
	int get_vx();
	void set_vx(int im_new);
	int get_vy();
	void set_vy(int im_new);
};

#endif // SIMULATEUR_HPP_INCLUDED
