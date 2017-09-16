#ifndef GAME_H_
#define GAME_H_
#include <GLFW/glfw3.h>
#include "game_state_registry.h"

class Game {
	public:
		GLboolean keys[1024];
		GLuint width, height;
		Game_state state;

		
		Game(GLuint width, GLuint height){}
		~Game(){}

		void init(){}

		void process_input(GLfloat delta_time){}

		void update(GLfloat delta_time){}

		void draw(){}
};

#endif