#ifndef OBJECT_ROOT_H_
#define OBJECT_ROOT_H_

#include "../graphics/sprite_renderer.h"

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

	void draw_sprite(unsigned int sprite_index, int image_index, int x, int y){
		renderer->draw_sprite(Resource_manager::get_texture("gnoll"), glm::vec2(200, 200), glm::vec2(64, 64), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	}

};

#endif