%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Projet_CPP : Robot_warrior %%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Au lancemenet on arrive dans le menu principal du jeu :

utilisation des interruptions souris et de differents menus sur la gauche 

*******************
Jeu  single player :
*******************

Ce mode de Jeu autorise les deplacements dans les quatres directions pour le joueur, il offre aussi la possibilite de collecter des pieces de differents types et ainsi faire evoluer son robot jusqu'au niveau qui permet de tirer sur l'IA. En haut de l'eran on voit apparaitre l'ensemble des pieces collectes jusqu'au niveau 3 par le joueur, ainsi que ceux compteurs qui comptabilisent le nombre de pieces total collecter par le joueur d'un cote et de l'autre par l'IA. En effet une IA basique a  ete implemente.
La partie s'arrete lorsque l'iA atteinds 10 pieces rammasse ou le joueur 50.
 
Details :
L'interface utilisateur utilise les interruptions souris et clavier.

Evolutions possibles:
Mode de Tir et de destruction faisant intervenir l'attribut life de nos avatars.

******************
Jeu multi player : 
******************

Ce mode de Jeu autorise les deplacements dans les quatres directions ainsi qu'en diagonales pour les  2 joueurs.Ce mode de jeu autorise les tirs par les deux joueurs.

Details :

On stocke les interruptions clavier simultannee dans un tableau contenant des 0  si la touche n'est pas enfoncee et des 1 si la touche est appuyee 


Evolutions :

Destruction de l'autre joueur.
Systeme de point de deplacement.



Leader board :

Fenetre prevu pour acceuillir le top 3 des joueurs en mode multiplayer ou single player.

Inventory :

Fenetre contenant l'ensemble des instructions necessaires pour pouvoir jouer a Robot Warrior.

********************
Ce qui ne marche pas
********************

Apres de nombreuses tentatives nous n'avons pas reussi a ressoudre le probleme des pointeurs et de liberation de memoire qui empeche l'utilisateur de rejouer une partie juste apres en avoir fini une.


*******************************
Amelioration - Evolution du jeu
*******************************

Permetttre a l'IA d'effectue de reel tir sur l'autre joueur, faire perdre de la batterie au robot quand il avance et reduire sa vitesse si celui-ci n'en a plus.
Avoir un niveau de difficulte de l'IA reglable.
Creer le LeaderBorads grace a la lecture d'un fichier texte sur lequel figurerais les noms des meilleurs joueurs et leurs scores.

Il nous a semble interessant de creer un jeu evolutif c'est a dire avec des niveaux d'avatar aussi bien en image graphgique que en possiblite de jeu (rapidite,tir,puissance).
Ces niveaux s'appliquent tout aussi bien au joueur humain que à l'IA.



