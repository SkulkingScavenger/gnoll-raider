#ifndef GAME_H_
#define GAME_H_
#include <GLFW/glfw3.h>
#include "game_state_registry.h"
#include "resource_manager.h"
#include "input_manager.h"
#include "graphics/sprite_renderer.h"
#include <glm/glm.hpp>
#include <vector>
#include "obj/object.h"

Sprite_renderer* renderer;

class Game {
	std::vector<Game_object*> object_registry;
	public:
		GLboolean keys[1024];
		GLuint width, height;
		Game_state state;

		
		Game(GLuint w, GLuint h) : state(GAME_ACTIVE), keys(), width(w), height(h){

		}
		~Game(){
			delete renderer;
		}

		void init(){
			// Load shaders
			Resource_manager::load_shader("shaders/sprite.vs", "shaders/sprite.fs", nullptr, "sprite");
			// Configure shaders
			glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->width), static_cast<GLfloat>(this->height), 0.0f, -1.0f, 1.0f);
			Resource_manager::get_shader("sprite").use().setInt("image", 0);
			Resource_manager::get_shader("sprite").SetMatrix4("projection", projection);
			// Set render-specific controls
			renderer = new Sprite_renderer(Resource_manager::get_shader("sprite"));
			// Load textures
			Resource_manager::load_texture("assets/sprites/gnoll.png", GL_TRUE, "gnoll");
			
		}

		void process_input(GLfloat delta_time){}

		void update(GLfloat delta_time){
			Input_manager::update();
		}

		void draw(){
			unsigned int l = object_registry.size();
			for (int i = 0; i < l; i++){
				Game_object* obj = object_registry[i];
				obj->draw(renderer);
			}
			
		}
};

#endif