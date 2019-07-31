#ifndef OBJETMECA_HPP_INCLUDED
#define OBJETMECA_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include "Objet.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Objet_meca : public Objet{
	public:
	Objet_meca(int x1,int y1);
	Objet_meca();
	void set_image();
	
};



#endif // OBJETMECA_HPP_INCLUDED
