
#include <stdlib.h>
#include <stdio.h> // perror
#include <SDL/SDL.h>
#include <string.h>
#include "Objet.hpp"
#include "Piece.hpp"
#include "Avatar.hpp"
#include "Simulateur.hpp"



int main(int argc,char** argv)
{
	//Creation d'un simulateur
    	Simulateur sim;
	//Initialisation de la souris
    	SDL_Rect souris;
    	souris.x=0;
	souris.y=0;
	//Lancement du menu principal
 	sim.menu(souris);
	return 0;
}





