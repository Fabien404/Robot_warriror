#ifndef OBJET_ELEC_HPP_INCLUDED
#define OBJET_ELEC_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include "Objet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Objet_elec : public Objet{
	public:
	Objet_elec(int x1,int y1);
	Objet_elec();
	void set_image();
};



#endif // OBJET_ELEC_HPP_INCLUDED
