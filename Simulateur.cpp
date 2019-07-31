#include "Simulateur.hpp"
#include <string>
#include <stdarg.h>

Simulateur :: Simulateur() {
	srand(time(NULL));
	/*on place de maniere aleatoire les positions des avatars*/
	j1.set_x1();
	j2.set_x1();
	j1.set_y1();
	j2.set_y1();
	/*On charge les images correspondants aux objets*/
	obj_meca1.set_image();
	obj_meca2.set_image();
	obj_meca3.set_image();
	obj_meca4.set_image();
	obj_elec1.set_image();
	obj_elec2.set_image();
	obj_elec3.set_image();
	obj_arme1.set_image();
	obj_arme2.set_image();
	/*On charge les images correspondants aux avatars*/
	j1.set_image("src/robot_l1.bmp");
	j2.set_image("src/robot_l1.bmp");
	ma_piece.set_longueur(800);
	ma_piece.set_largeur(500);
	ma_piece.set_image("src/map3-j1.bmp");
	ma_piece.add_objet(obj_meca1);
	ma_piece.add_objet(obj_meca2);
	ma_piece.add_objet(obj_meca3);
	ma_piece.add_objet(obj_meca4);
	ma_piece.add_objet(obj_elec1);
	ma_piece.add_objet(obj_elec2);
	ma_piece.add_objet(obj_elec3);
	ma_piece.add_objet(obj_arme1);
	ma_piece.add_objet(obj_arme2);
	menu_1.set_x(24);
	menu_1.set_y(28);
	menu_1.set_image(-1);
	menu_2.set_x(463);
	menu_2.set_y(28);
	menu_2.set_image(-2);
	menu_3.set_x(565);
	menu_3.set_y(9);
	menu_3.set_image(-3);
	ma_piece.add_objet(menu_1);
	ma_piece.add_objet(menu_2);
	ma_piece.add_objet(menu_3);
}

void Simulateur :: refresh_objet(){
	srand(time(NULL));
	obj_meca1.set_image();
	obj_meca2.set_image();
	obj_meca3.set_image();
	obj_meca4.set_image();
	obj_elec1.set_image();
	obj_elec2.set_image();
	obj_elec3.set_image();
	obj_arme1.set_image();
	obj_arme2.set_image();
	ma_piece.add_objet(obj_meca1);
	ma_piece.add_objet(obj_meca2);
	ma_piece.add_objet(obj_meca3);
	ma_piece.add_objet(obj_meca4);
	ma_piece.add_objet(obj_elec1);
	ma_piece.add_objet(obj_elec2);
	ma_piece.add_objet(obj_elec3);
	ma_piece.add_objet(obj_arme1);
	ma_piece.add_objet(obj_arme2);
}

void Simulateur :: menu(SDL_Rect souris) {
	 if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        	std::cout<<"Unable to Initialisationialize SDL"<<std::endl;
		exit(0);
    	}

	SDL_Event event;//vecteur evenement
	SDL_Surface *ecran = NULL,*imageDeFond = NULL;
	SDL_Surface *bouton=NULL,*menu_gauche=NULL;
	SDL_Rect positionFond,position_bouton;

	//Positions
	positionFond.x = 0;
	positionFond.y = 0;
	int continuer=1;

	//Creation de l'ecran video
	ecran=SDL_SetVideoMode(1153,600, 32, SDL_HWSURFACE);

	imageDeFond = SDL_LoadBMP("src/menuprincipal.bmp");
	menu_gauche = SDL_LoadBMP("src/menu_gauche.bmp");

	while (continuer){
        	SDL_WaitEvent(&event);
        	switch(event.type){
			case SDL_QUIT:
				continuer = 0;
				break;

			case SDL_MOUSEMOTION:
		       		souris.x += event.motion.xrel;
		       		souris.y += event.motion.yrel;
                		break;

            		case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT){
					/*single player*/
					if (souris.x>560  && souris.x<750 && souris.y<252 && souris.y>220){
						single_player(souris);
					}

					/*multi player*/
					if (souris.x>605  && souris.x<761 && souris.y<282 && souris.y>263){
						multi_player(souris);
					}

					/*inventory*/
            				if (souris.x>600  && souris.x<740 && souris.y<325 && souris.y>307){
                    				menu_gauche=SDL_LoadBMP("src/inventory.bmp");
					}

					/*leader boards*/
            				if (souris.x>600  && souris.x<807 && souris.y<365 && souris.y>347){
                    				menu_gauche=SDL_LoadBMP("src/leaders.bmp");
					}
					/*help and options*/
            				if (souris.x>605 && souris.x<837 && souris.y<407 && souris.y>388){
                    				menu_gauche=SDL_LoadBMP("src/help.bmp");
					}
				}
				break;
        	}

		SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);

				/*Surlignage des bouttons*/
		if (souris.x>605  && souris.x<780 && souris.y<252 && souris.y>220){
			/*single player*/
			bouton=SDL_LoadBMP("src/bouton1.bmp");
			position_bouton.x=596;
			position_bouton.y=226;
			SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
		}
		if (souris.x>605  && souris.x<761 && souris.y<282 && souris.y>263){
			/*multi player*/
			bouton=SDL_LoadBMP("src/bouton2.bmp");
			position_bouton.x=599;
			position_bouton.y=258;
			SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
		}
		if (souris.x>600   && souris.x<740    && souris.y<345   && souris.y>307){
			/*inventory*/
			bouton=SDL_LoadBMP("src/bouton3.bmp");
			position_bouton.x=601;
			position_bouton.y=301;
			SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
		}
		if (souris.x>600   && souris.x<807    && souris.y<365   && souris.y>347){
			/*leader*/
			bouton=SDL_LoadBMP("src/bouton4.bmp");
			position_bouton.x=595;
			position_bouton.y=340;
			SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
		}
		if (souris.x>605   && souris.x<837    && souris.y<407   && souris.y>388){
			/*help*/
			bouton=SDL_LoadBMP("src/bouton5.bmp");
			position_bouton.x=597;
			position_bouton.y=378;
			SDL_BlitSurface(bouton,NULL,ecran,&position_bouton);
		}
		SDL_BlitSurface(menu_gauche,NULL,ecran,&positionFond);
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(imageDeFond);
	SDL_FreeSurface(bouton);
	SDL_FreeSurface(menu_gauche);
    	SDL_Quit();

}

int Simulateur :: single_player(SDL_Rect souris){
	j1.set_nb_meca(0);
	j1.set_nb_elec(0);
	j1.set_nb_arme(0);
	j2.set_nb_elec(0);
	j2.set_nb_meca(0);		
	j2.set_nb_arme(0);
						
	SDL_Event event;//vecteur evenement
	SDL_Rect objets,poslaser;
	int continuer=1;
	SDL_Surface *font=NULL,*ecran = NULL,*laser = NULL;

	//Creation de l'ecran video
	ecran=SDL_SetVideoMode(728,500, 32, SDL_HWSURFACE);

	//Chargement de la police de characteres
	font=SDL_LoadBMP("src/font.bmp");
	if (!font)
		exit(0);

	//Affichage de la PIECE//
	SDL_BlitSurface(ma_piece.get_image(),NULL,ecran,ma_piece.get_position());

	/* Affichage des avatars*/
	SDL_SetColorKey(j1.get_image(), SDL_SRCCOLORKEY, SDL_MapRGB(j1.get_image()->format,0,0,0));
	SDL_BlitSurface(j1.get_image(), NULL, ecran,j1.get_position());
	SDL_SetColorKey(j2.get_image(), SDL_SRCCOLORKEY, SDL_MapRGB(j2.get_image()->format,0,0,0));
	SDL_BlitSurface(j2.get_image(), NULL, ecran,j2.get_position());

	SDL_EnableKeyRepeat(5,5);

		//ARMES//
	laser = SDL_LoadBMP("src/laser_niv3.bmp");

		//AFFICHAGE DE TOUT LES OBJETS de la piece//
	SDL_Surface* temp=NULL;
	for(int i=0;i<ma_piece.get_taille_tab();i++){
		if(ma_piece.get_type_obj(i)!=-1){
				//Recupere positions
			objets.x=ma_piece.get_position_obj(i)->x;
			objets.y=ma_piece.get_position_obj(i)->y;
				//Affichage
			temp=ma_piece.get_image_obj(i);
			SDL_SetColorKey(temp,SDL_SRCCOLORKEY,SDL_MapRGB(temp->format,0,0,0));
			SDL_BlitSurface(temp,NULL,ecran,&objets);
		}
	}
	while (continuer){
		j2.move_aleatoire(3,&ma_piece); // regler en mode normal de difficulte ia
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				continuer = 0;
				break;

			case SDL_MOUSEMOTION:
				souris.x += event.motion.xrel;
				souris.y += event.motion.yrel;
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					default:
		        			break;
				case SDLK_UP: // Flèche haut
				        j1.set_y(j1.get_position()->y-3);
				        if(j1.get_position()->y<68){
				            j1.set_y(68);
				        }
				        break;

				case SDLK_DOWN: // Flèche bas
				         j1.set_y(j1.get_position()->y+3);
				          if(j1.get_position()->y+j1.get_image()->h>499){
				            j1.set_y(499-j1.get_image()->h);
				        }
				        break;

				case SDLK_RIGHT: // Flèche droite
				         j1.set_x(j1.get_position()->x+3);
				          if(j1.get_position()->x+j1.get_image()->w>727){
				            j1.set_x(727-j1.get_image()->w);
				        }
				    break;

				case SDLK_LEFT: // Flèche gauche
				          j1.set_x(j1.get_position()->x-3);
				          if(j1.get_position()->x<0){
		                    j1.set_x(0);
				        }
				    break;

				case SDLK_KP1: // 1 : tir
					if(j1.get_niveau()==3){
					       poslaser.x = j1.get_position()->x + j1.get_image()->w/2.2;
					       poslaser.y = j1.get_position()->y + j1.get_image()->h/4;
					       SDL_BlitSurface(laser, NULL, ecran, &poslaser);
					       SDL_Flip(ecran);
					       SDL_Delay(200);
					}
				    break;
				}
		        break;

		}

		/* On recupere les objets que touche le robot et màj de son niveau */
		j1.touch_object(ma_piece);
		j2.touch_object(ma_piece);
		j1.maj_niveau();
		j2.maj_niveau();

		/*On detecte si la fin de partie est atteinte !*/
		if(j2.get_nb_meca()+j2.get_nb_elec()+j2.get_nb_arme()>=10){
			char tab2[15]={'L',' ','I','A',' ','G','A','G','N','E',' ','!','!','!','\0'};
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,0,0,0));
			PrintSDL(font,ecran,200,200,tab2);
			char tab3[16]={'V','O','U','S',' ','A','V','E','Z',' ','P','E','R','D','U','\0'};
			PrintSDL(font,ecran,200,300,tab3);
			SDL_Flip(ecran);
			SDL_Delay(2000);
			continuer=0;
		}
		if(j1.get_nb_meca()+j1.get_nb_elec()+j1.get_nb_arme()>=50){
			char tab2[13]={'J','1',' ','G','A','G','N','E',' ','!','!','!'};
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,0,0,0));
			PrintSDL(font,ecran,303,200,tab2);
			SDL_Flip(ecran);
			SDL_Delay(2000);
			continuer=0;
		}

		//Effacage de l'ecran
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(ma_piece.get_image(),NULL,ecran,ma_piece.get_position());
	    	/* Affichage des avatars*/
		SDL_SetColorKey(j1.get_image(), SDL_SRCCOLORKEY, SDL_MapRGB(j1.get_image()->format,0,0,0));
		SDL_BlitSurface(j1.get_image(), NULL, ecran,j1.get_position());

		SDL_SetColorKey(j2.get_image(), SDL_SRCCOLORKEY, SDL_MapRGB(j2.get_image()->format,0,0,0));
		SDL_BlitSurface(j2.get_image(), NULL, ecran,j2.get_position());

		/*Affichage des scores*/
		char tab[4]={':','%','d','\0'};
		PrintSDL(font,ecran,303,12,tab,j1.get_nb_meca()+j1.get_nb_elec()+j1.get_nb_arme());
		PrintSDL(font,ecran,386,12,tab,j2.get_nb_meca()+j2.get_nb_elec()+j2.get_nb_arme());
		if(ma_piece.get_taille_tab()==3){
			refresh_objet();
		}
		/*Affichage des objets et des vignettes*/
		for(int i=0;i<ma_piece.get_taille_tab();i++){
			if(ma_piece.get_type_obj(i)>0){
					//Recupere positions
				objets.x=ma_piece.get_position_obj(i)->x;
				objets.y=ma_piece.get_position_obj(i)->y;
					//Affichage
				temp=ma_piece.get_image_obj(i);
				SDL_SetColorKey(temp,SDL_SRCCOLORKEY,SDL_MapRGB(temp->format,0,0,0));
				SDL_BlitSurface(temp,NULL,ecran,&objets);
			}
			if(ma_piece.get_type_obj(i)==-1){
		    		affiche_meca(&j1,&ma_piece,ecran,i);
			}
			if(ma_piece.get_type_obj(i)==-2){
				affiche_elec(&j1,&ma_piece,ecran,i);
			}
			if(ma_piece.get_type_obj(i)==-3){
				affiche_arme(&j1,&ma_piece,ecran,i);
			}

			// tir et destruction
			if(j1.get_niveau()==3){
		        	if(( j2.get_position()->x < j1.get_position()->x + j1.get_image()->w/2.2 ||  j2.get_position()->x > 					j1.get_position()->x + j1.get_image()->w/2.2 + laser->w
		            	||  j2.get_position()->y < j1.get_position()->y + j1.get_image()->h/4 ||  j2.get_position()->y > 					j1.get_position()->y + j1.get_image()->h/4 + laser->h )){
		            // no touch
		        }
		        else{
				if(j2.get_niveau()==3){
					change_niveau(&j2,0,2,3);
		            	}
		            	if(j2.get_niveau()==2){
					change_niveau(&j2,0,0,2);
		            	}
		             	if(j2.get_niveau()==1){
					change_niveau(&j2,0,0,0);
		            	}
		            	if(j2.get_niveau()==0){
		              		j2.set_life(j2.get_life()-1);
		                 	if(j2.get_life()==0)
		                         	continuer = 2;
		            	}
		        }
		}

	}
	/* On met à jour l'affichage */
	SDL_Flip(ecran);
	}
	SDL_FreeSurface(j1.get_image());
	SDL_FreeSurface(laser);
	menu(souris);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

void Simulateur :: change_niveau(Avatar *j,int arme,int elec,int meca){
	j->set_nb_arme(arme);
	j->set_nb_elec(elec);
 	j->set_nb_meca(meca);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void Simulateur :: UpdateEvents(char* keys){
	SDL_Event event;
    	while(SDL_PollEvent(&event)){
        	switch (event.type){
        		case SDL_KEYDOWN:
            			keys[event.key.keysym.sym]=1;
            			break;
        		case SDL_KEYUP:
            			keys[event.key.keysym.sym]=0;
            			break;
        	}
    	}
}

int Simulateur :: Blit(SDL_Surface* src,SDL_Surface* dst,int x,int y){
	SDL_Rect R;
	R.x = x;
	R.y = y;
	return SDL_BlitSurface(src,NULL,dst,&R);
}


int Simulateur :: LoadAll(Context* C,Avatar* j1,Avatar* j2,int nb_obj){
	int i;
	C->nbimg = 2+nb_obj;//Pour 2 joueurs en meme temps + les objets supplemnetaire si besoin
	C->images = (SDL_Surface**)malloc(C->nbimg*sizeof(SDL_Surface*));
	C->images[0] = j1->get_image();
	C->images[1] = j2->get_image();
	for(i=0;i<C->nbimg;i++){
		SDL_SetColorKey(C->images[i],SDL_SRCCOLORKEY ,SDL_MapRGBA(C->images[i]->format,0,0,0,0));
    	}
    return 0;
}

int Simulateur :: InitialisationSprites(Context* C){
    	int i;
    	C->sprites =(Sprite*)malloc(C->nb_sprite*sizeof(Sprite));
    	C->sprites[0].set_im(0);
	C->sprites[0].set_x(j1.get_position()->x);
        C->sprites[0].set_y(j1.get_position()->y);//operations pour eviter la parte du menu en haut
	C->sprites[1].set_im(1);
        C->sprites[1].set_x(j1.get_position()->x);
        C->sprites[1].set_y(j1.get_position()->y);//operations pour eviter la parte du menu en haut
	for(i=2;i<C->nb_sprite;i++){
		C->sprites[i].set_im(i);
		C->sprites[i].set_x(rand()%(C->XRES-10));
		C->sprites[i].set_y( (rand()%(C->YRES-341))+68);//operations pour eviter la parte du menu en haut
    	}
    	return 0;
}

int Simulateur :: Initialisation(Context* C,int x,int y,int nb_sprite,Avatar* j1,Avatar* j2,int nb_obj){
    	if (C==NULL)
		return -1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
        	std::cout<<"Unable to Initialisationialize SDL"<<std::endl;
        	return -1;
	}
	C->XRES = x;
	C->YRES = y;
	C->screen = SDL_SetVideoMode(C->XRES,C->YRES,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (C->screen==NULL)
		return -1;
	if (LoadAll(C,j1,j2,nb_obj)!=0)
        	return -1;
    	C->nb_sprite = nb_sprite;
    	if (InitialisationSprites(C)!=0)
        	return -1;
    	return 0;
}

int Simulateur :: Destruct(Context* C){
	int i;
    	for(i=0;i<C->nbimg;i++)
    	SDL_FreeSurface(C->images[i]);
    	free(C->images);
    	free(C->sprites);
    	SDL_Quit();
    	return 0;
}

void Simulateur :: Refresh(Context* C,char* key){
    	SDLKey tabkey[2][5] = {{SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_KP1},{SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_y}};
    	SDL_Surface *laser = NULL;
    	int i;
	C->images[0] = j1.get_image();
	C->images[1] = j2.get_image();
	for(i=0;i<C->nbimg;i++){
		SDL_SetColorKey(C->images[i],SDL_SRCCOLORKEY ,SDL_MapRGBA(C->images[i]->format,0,0,0,0));
    	}
    	for(i=0;i<2;i++){  // gestion  manuelles (2 players)
        	if (key[tabkey[i][0]]){// haut
            		C->sprites[i].set_y( C->sprites[i].get_y()-4);
            		if(C->sprites[i].get_y()<68){
              			C->sprites[i].set_y(68);
            		}
			if(i==0){
				j1.set_y(C->sprites[i].get_y());
			}
			if(i==1){
				j2.set_y(C->sprites[i].get_y());
			}
        	}
        	if (key[tabkey[i][1]]){ // bas
			C->sprites[i].set_y(C->sprites[i].get_y()+4);
		     	if(C->sprites[i].get_y()+j1.get_image()->h>410){
		        	C->sprites[i].set_y(410-j1.get_image()->h);
		    	}
			if(i==0){
				j1.set_y(C->sprites[i].get_y());
			}
			if(i==1){
				j2.set_y(C->sprites[i].get_y());
			}
		}
		if (key[tabkey[i][2]]){  // gauche
		    	C->sprites[i].set_x(C->sprites[i].get_x()-4);
		      	if(C->sprites[i].get_x()<0){
		            	C->sprites[i].set_x(0);
		   	 }
			if(i==0){
				j1.set_x(C->sprites[i].get_x());
			}
			if(i==1){
				j2.set_x(C->sprites[i].get_x());
			}
		}
		if (key[tabkey[i][3]]){ // droite
		    	C->sprites[i].set_x(C->sprites[i].get_x()+4);
		      	if(C->sprites[i].get_x()+j1.get_image()->w>727){
		        	C->sprites[i].set_x(727-j1.get_image()->w);
		        }
			if(i==0){
				j1.set_x(C->sprites[i].get_x());
			}
			if(i==1){
				j2.set_x(C->sprites[i].get_x());
			}
	      	}
		if (key[tabkey[i][4]]){  // tir
			laser = SDL_LoadBMP("src/laser_niv3.bmp");
		    	Blit(laser,C->screen,C->sprites[i].get_x()+100/2.2,C->sprites[i].get_y()+105/4);
		    	SDL_Flip(C->screen);
		    	SDL_Delay(200);
		}
	}
}

void Simulateur :: Affiche(Context* C){
	SDL_Surface *imageDeFond2 = NULL,*font=NULL;
	SDL_Rect objets;
    	SDL_Surface* temp=NULL;
	imageDeFond2 = SDL_LoadBMP("src/map3-j2.bmp");
	int i;
	//Chargement de la police de characteres
	font=SDL_LoadBMP("src/font.bmp");
	if (!font)
		exit(0);
	char tab[4]={':','%','d','\0'};
	Blit(imageDeFond2,C->screen,0,0);
	//On affiche l'ensemble des images d'indice i charge precedemment
	for(i=0;i<C->nb_sprite;i++){
		Blit(C->images[C->sprites[i].get_im()],C->screen,C->sprites[i].get_x(),C->sprites[i].get_y());
	}
	for(i=0;i<ma_piece.get_taille_tab();i++){
		if(ma_piece.get_type_obj(i)>0){
				//Recupere positions
			objets.x=ma_piece.get_position_obj(i)->x;
			objets.y=ma_piece.get_position_obj(i)->y;
				//Affichage
			temp=ma_piece.get_image_obj(i);
			SDL_SetColorKey(temp,SDL_SRCCOLORKEY,SDL_MapRGB(temp->format,0,0,0));
			SDL_BlitSurface(temp,NULL,C->screen,&objets);
		}
	}
	PrintSDL(font,C->screen,303,12,tab,j2.get_nb_meca()+j2.get_nb_elec()+j2.get_nb_arme());
	PrintSDL(font,C->screen,386,12,tab,j1.get_nb_meca()+j1.get_nb_elec()+j1.get_nb_arme());
    	SDL_FreeSurface(imageDeFond2);
}

int Simulateur :: multi_player(SDL_Rect souris){
	int nb_obj=0;
	Context C;
	SDL_Surface *font=NULL;
	souris.x=0;
	souris.y=0;
	int continuer=1;
	font=SDL_LoadBMP("src/font.bmp");
	char key[SDLK_LAST] = {0};
	srand((unsigned int)time(NULL));
	if (Initialisation(&C,728,409,2+nb_obj,&j1,&j2,nb_obj)!=0)
		return -1;
	while(continuer){
		if(key[SDLK_ESCAPE]==1){
			continuer=0;
		}
		if(j1.get_nb_meca()+j1.get_nb_elec()+j1.get_nb_arme()>=50){
			char tab2[13]={'J','1',' ','G','A','G','N','E',' ','!','!','!','\0'};
			SDL_FillRect(C.screen, NULL, SDL_MapRGB(C.screen->format,0,0,0));
			PrintSDL(font,C.screen,303,200,tab2);
			SDL_Flip(C.screen);
			SDL_Delay(2000);
			continuer=0;
		}
		if(j2.get_nb_meca()+j2.get_nb_elec()+j2.get_nb_arme()>=50){
			char tab2[13]={'J','2',' ','G','A','G','N','E',' ','!','!','!','\0'};
			SDL_FillRect(C.screen, NULL, SDL_MapRGB(C.screen->format,0,0,0));
			PrintSDL(font,C.screen,303,200,tab2);
			SDL_Flip(C.screen);
			SDL_Delay(2000);
			continuer=0;
		}
		unsigned int elapsed;
		unsigned int lasttime = SDL_GetTicks();
		UpdateEvents(key);
		Refresh(&C,key);
		if(ma_piece.get_taille_tab()==3){
			refresh_objet();
		}
		Affiche(&C);
		j1.touch_object(ma_piece);
		j2.touch_object(ma_piece);
		j1.maj_niveau();
		j2.maj_niveau();	
		while(SDL_Flip(C.screen)!=0)
		    SDL_Delay(1);
		elapsed = SDL_GetTicks()-lasttime;
		if (elapsed<20)
		    SDL_Delay(20-elapsed);
	}
	Destruct(&C);
	menu(souris);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////// OUTILS AFFICHAGES MENU DE JEU //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void Simulateur :: affiche_meca(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i){
    SDL_Rect objets;
    SDL_Surface* temp=NULL;
    switch(j1->get_nb_meca()){
                case 1:
                    objets.x=ma_piece->get_position_obj(i)->x;
                    objets.y=ma_piece->get_position_obj(i)->y;
                    temp=ma_piece->get_image_obj(i);
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    break;

                case 2:
                    objets.x=ma_piece->get_position_obj(i)->x;
                    objets.y=ma_piece->get_position_obj(i)->y;
                    temp=ma_piece->get_image_obj(i);
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    break;

                case 3:
                    objets.x=ma_piece->get_position_obj(i)->x;
                    objets.y=ma_piece->get_position_obj(i)->y;
                    temp=ma_piece->get_image_obj(i);
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    break;

                case 4:
                    objets.x=ma_piece->get_position_obj(i)->x;
                    objets.y=ma_piece->get_position_obj(i)->y;
                    temp=ma_piece->get_image_obj(i);
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    objets.x+=35;
                    SDL_BlitSurface(temp,NULL,ecran,&objets);
                    break;
            }
	if(j1->get_nb_meca()>=5){
		objets.x=ma_piece->get_position_obj(i)->x;
		objets.y=ma_piece->get_position_obj(i)->y;
		temp=ma_piece->get_image_obj(i);
		SDL_BlitSurface(temp,NULL,ecran,&objets);
		objets.x+=35;
		SDL_BlitSurface(temp,NULL,ecran,&objets);
		objets.x+=35;
		SDL_BlitSurface(temp,NULL,ecran,&objets);
	  	objets.x+=35;
		SDL_BlitSurface(temp,NULL,ecran,&objets);
		objets.x+=35;
                SDL_BlitSurface(temp,NULL,ecran,&objets);
	}
}

void Simulateur :: affiche_elec(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i){
	SDL_Rect objets;
	SDL_Surface* temp=NULL;
	switch(j1->get_nb_elec()){
		case 1:
			objets.x=ma_piece->get_position_obj(i)->x;
			objets.y=ma_piece->get_position_obj(i)->y;
			temp=ma_piece->get_image_obj(i);
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			break;

		case 2:
			objets.x=ma_piece->get_position_obj(i)->x;
			objets.y=ma_piece->get_position_obj(i)->y;
			temp=ma_piece->get_image_obj(i);
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.x+=35;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			break;

		case 3:
			objets.x=ma_piece->get_position_obj(i)->x;
			objets.y=ma_piece->get_position_obj(i)->y;
			temp=ma_piece->get_image_obj(i);
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.x+=35;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.y+=17;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			break;
	}
	if(j1->get_nb_meca()>=4){
			objets.x=ma_piece->get_position_obj(i)->x;
			objets.y=ma_piece->get_position_obj(i)->y;
			temp=ma_piece->get_image_obj(i);
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.x+=35;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.y+=17;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
			objets.x-=35;
			SDL_BlitSurface(temp,NULL,ecran,&objets);
	}
}

void Simulateur :: affiche_arme(Avatar* j1,Piece* ma_piece,SDL_Surface* ecran,int i){
	SDL_Rect objets;
	SDL_Surface* temp=NULL;
	if(j1->get_nb_arme()==1){
		objets.x=ma_piece->get_position_obj(i)->x;
		objets.y=ma_piece->get_position_obj(i)->y;
		//Affichage
		temp=ma_piece->get_image_obj(i);
		SDL_BlitSurface(temp,NULL,ecran,&objets);
	}
	if(j1->get_nb_arme()>1){
		objets.x=ma_piece->get_position_obj(i)->x;
		objets.y=ma_piece->get_position_obj(i)->y;
		//Affichage
		temp=ma_piece->get_image_obj(i);
		SDL_BlitSurface(temp,NULL,ecran,&objets);
		objets.x+=65;
		SDL_BlitSurface(temp,NULL,ecran,&objets);
	}
}


void Simulateur :: PrintSDL(SDL_Surface* font,SDL_Surface* dest,int x,int y,char* text,...){
	char buf[500];
	int i,len;
	SDL_Rect Rsrc,Rdst;
	va_list args;
	va_start(args,text);
	vsprintf(buf,text,args);
	va_end(args);
	Rsrc.w = font->w/16;
	Rsrc.h = font->h/14;
	len = (int)strlen(buf);
	for(i=0;i<len;i++)
	{
		Rsrc.x = Rsrc.w*((unsigned char)(buf[i])%16);
		Rsrc.y = Rsrc.h*((unsigned char)(buf[i])/16-2);  // on saute les 31 premiers codes ASCII
		Rdst.x = x;
		Rdst.y = y;
		SDL_BlitSurface(font,&Rsrc,dest,&Rdst);
		x+=Rsrc.w;
	}
}

