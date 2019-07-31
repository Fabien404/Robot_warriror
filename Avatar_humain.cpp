#include "Avatar_humain.hpp"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Avatar_humain :: set_x1(){
		this->position.x=rand()%350;
}
void Avatar_humain :: set_y1(){
		this->position.y=(rand()%300)+68;
	
}

