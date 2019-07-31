#ifndef OBJET_MENU_HPP_INCLUDED
#define OBJET_MENU_HPP_INCLUDED


#include <string>
#include <SDL/SDL.h>
#include "Objet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Objet_menu : public Objet{
	public:
	Objet_menu(int x1,int y1);
	Objet_menu();
	void set_image(int num);
};



#endif // OBJET_MENU_HPP_INCLUDED
