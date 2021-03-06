#ifndef SPRITE_H_
#define SPRITE_H_

#include <GLFW/glfw3.h>
#include <vector>

class Image {
public:
	GLbyte* pixels;
	Image(GLbyte* p){
		pixels = p;
	}
};


class Sprite {
public:
	int frame_count;
	int width;
	int height;
	int origin_x = 0;
	int origin_y = 0;
	std::vector<Image, std::allocator<Image>> frames;

	Sprite(){
		frame_count = 0;
		width = 0;
		height = 0;
		origin_x = 0;
		origin_y = 0;
	}

	Sprite(int frame_count, int w, int h, std::vector<Image> images, int x, int y){
		width = w;
		height = h;
		origin_x = x;
		origin_y = y;
		frames = images;
	}
};
#endif