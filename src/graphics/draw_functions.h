#ifndef DRAW_FUNCTIONS_H_
#define DRAW_FUNCTIONS_H_

#include "../graphics/sprite.h"
#include "../resource_manager.h"
#include "../game.h"
extern Sprite_renderer* renderer;

void draw_sprite(unsigned int sprite_index, int image_index, int x, int y){
	Sprite* spr = Resource_manager::get_sprite(sprite_index);
	renderer->draw_sprite(Resource_manager::get_texture("gnoll"), glm::vec2(200, 200), glm::vec2(spr->width, spr->height), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}


#endif