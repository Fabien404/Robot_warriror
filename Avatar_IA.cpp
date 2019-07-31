#include "Avatar_IA.hpp"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Avatar_IA :: set_x1(){
		this->position.x=(rand()%350)+350;
}
void Avatar_IA :: set_y1(){
		this->position.y=(rand()%300)+68;
	
}
