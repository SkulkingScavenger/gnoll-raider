#include <array>

class Image {
	int width;
	int height;
};

class Sprite {
public:
	int width;
	int height;
	int frame_count;
	Image** frames;

	Sprite(Image** image_array){
		frames = image_array;

	}
};