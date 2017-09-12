#include <GLFW/glfw3.h>
#include <vector>
#include "sprite.h"

Sprite sprites[1];

void fun(){
	std::vector<Image> images;

	images.clear();
	GLbyte pixels[8] = { 1, 2, 3, 4, 1, 2, 3, 4 };
	Image temp_img(pixels);
	images.push_back(temp_img);
	Sprite temp_spr(1, 2, 1, images, 0, 0);
	sprites[0] = temp_spr;
}