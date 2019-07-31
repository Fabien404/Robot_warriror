#ifndef OBJET_ARME_HPP_INCLUDED
#define OBJET_ARME_HPP_INCLUDED


#include <string>
#include <SDL/SDL.h>
#include "Objet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Objet_arme : public Objet{
	public:
	Objet_arme(int x1,int y1);
	Objet_arme();
	void set_image();
		void set_x();
	void set_y();
};



#endif // OBJET_ARME_HPP_INCLUDED
