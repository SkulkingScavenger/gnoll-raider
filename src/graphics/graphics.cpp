#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include "sprite.h"

#define PNG_DEBUG 3
#include <libpng/png.h>

void load_sprite_from_png(std::string file_name){

	
	std::ifstream myfile(file_name);
	float R, G, B;
	if (myfile.is_open()){
		const int w = 512;
		const int h = 512;
		GLubyte pmi[w][h][3];
		int i = 0;
		while (myfile >> R && myfile >> G && myfile >> B){
			pmi[i % 512][i / 512][0] = R;
			pmi[i % 512][i / 512][1] = G;
			pmi[i % 512][i / 512][2] = B;
			i += 1;
		}
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		myfile.close();

	}
	else{
		//show error if file not found
		return;
	}
	for (int i = 0; i < 512; i += 1){
		for (int j = 0; j < 512; i += 1){
			//cout << pmi[i][j][0] << pmi[i][j][1] << pmi[i][j][2] << endl;
		}
	}

}


void draw_sprite(Sprite spr, int x, int y){
	
	//glDrawPixels(w, h, format, GL_UNSIGNED_SHORT, data);
}