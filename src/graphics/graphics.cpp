#include <GLFW/glfw3.h>
#include "sprite.h"
#include "sprite_registry.h"
#include "sprite_enum.h"

void draw_sprite(sprite_t sprite_index, int image_index, int x, int y){
	Sprite spr = sprites[sprite_index];
	glLineWidth(1);//set width
	glPointSize(1);//set pointsize

	glRasterPos2s(x,y);
	glDrawPixels(spr.width, spr.height, GL_RGBA, GL_BYTE, spr.frames[image_index].pixels);
}

void draw_self(){

}