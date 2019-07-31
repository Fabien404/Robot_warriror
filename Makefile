CC = g++
CFLAGS = -Wall
EXEC_NAME = main,AvatarTest

SDLFLAGS=`sdl-config --cflags`
SDLLIBS=`sdl-config --libs`

main: main.o Objet.o Piece.o Simulateur.o Avatar.o Avatar_humain.o Avatar_IA.o Sprite.o Objet_meca.o Objet_elec.o Objet_arme.o Objet_menu.o
	g++ -o main main.o Objet.o Piece.o Simulateur.o Avatar.o Sprite.o Objet_meca.o Objet_elec.o Objet_arme.o Objet_menu.o Avatar_humain.o Avatar_IA.o $(SDLLIBS)
	
AvatarTest: AvatarTest.o Objet.o Piece.o
	g++ -o AvatarTest AvatarTest.cpp Avatar.cpp -lboost_unit_test_framework

AvatarTest.o: AvatarTest.cpp Avatar.hpp
	g++ -Wall -c -g AvatarTest.cpp

main.o: main.cpp 
	g++ -Wall -c -g main.cpp $(SDLFLAGS)

Objet.o: Objet.cpp Objet.hpp
	g++ -Wall -c -g Objet.cpp

Objet_meca.o: Objet_meca.cpp Objet_meca.hpp
	g++ -Wall -c -g Objet_meca.cpp

Objet_elec.o: Objet_elec.cpp Objet_elec.hpp
	g++ -Wall -c -g Objet_elec.cpp

Objet_arme.o: Objet_arme.cpp Objet_arme.hpp
	g++ -Wall -c -g Objet_arme.cpp

Objet_menu.o: Objet_menu.cpp Objet_menu.hpp
	g++ -Wall -c -g Objet_menu.cpp

Piece.o: Piece.cpp Piece.hpp
	g++ -Wall -c -g Piece.cpp

Simulateur.o: Simulateur.cpp Simulateur.hpp
	g++ -Wall -c -g Simulateur.cpp $(SDLFLAGS)

Avatar.o: Avatar.cpp Avatar.hpp
	g++ -Wall -c -g Avatar.cpp

Avatar_humain.o: Avatar_humain.cpp Avatar_humain.hpp
	g++ -Wall -c -g Avatar_humain.cpp

Avatar_IA.o: Avatar_IA.cpp Avatar_IA.hpp
	g++ -Wall -c -g Avatar_IA.cpp

Sprite.o: Sprite.cpp Sprite.hpp
	g++ -Wall -c -g Sprite.cpp

clean:
	rm -f *~ *.o 
	
mrproper :   clean
	rm −f main
