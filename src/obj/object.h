#ifndef OBJECT_ROOT_H_
#define OBJECT_ROOT_H_

#include "../graphics/sprite_renderer.h"
#include "../graphics/draw_functions.h"

class Game_object{
public:
	int sprite_index;
	int image_index;
	int x;
	int y;
	int z;
	int xprevious;
	int yprevious;


	Game_object(){

	}

	void update(){

	}

	void draw(Sprite_renderer* renderer){
		draw_sprite(sprite_index,image_index,x,y);
	}

};

#endif