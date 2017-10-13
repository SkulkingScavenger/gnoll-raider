#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

//buttons
bool confirm_btn = false;
bool cancel_btn = false;
bool start_btn = false;
bool toggle_btn = false;
bool atk_btn = false;
bool interact_btn = false;
bool arrow_right = false;
bool arrow_up = false;
bool arrow_left = false;
bool arrow_down = false;
bool item_btn[4] = { false, false, false, false };
bool skill_btn[4] = { false, false, false, false };

//keys
int confirm_key = GLFW_KEY_SPACE;
int cancel_key = GLFW_KEY_RIGHT_ALT;
int start_key = GLFW_KEY_ENTER;
int toggle_key = GLFW_KEY_LEFT_SHIFT;
int atk_key = GLFW_KEY_SPACE;
int interact_key = GLFW_KEY_RIGHT_ALT;
int right_key = GLFW_KEY_D;
int up_key = GLFW_KEY_W;
int left_key = GLFW_KEY_A;
int down_key = GLFW_KEY_S;
int slot_key[4] = { GLFW_KEY_O, GLFW_KEY_P, GLFW_KEY_LEFT_BRACKET, GLFW_KEY_RIGHT_BRACKET };

static class Input_manager{
	static std::vector<int> input_list;
	static std::string input_string;
	static void update(GLFWwindow* window){
		confirm_btn = false;
		cancel_btn = false;
		start_btn = false;
		toggle_btn = false;
		atk_btn = false;
		interact_btn = false;
		arrow_right = false;
		arrow_up = false;
		arrow_left = false;
		arrow_down = false;
		for (int i = 0; i < 4; i++){
			item_btn[i] = false;
			skill_btn[i] = false;
		}
		
		confirm_btn = glfwGetMouseButton(window, confirm_key);
		cancel_btn = glfwGetMouseButton(window, cancel_key);
		start_btn = glfwGetMouseButton(window, start_key);
		toggle_btn = glfwGetMouseButton(window, toggle_key);
		atk_btn = glfwGetMouseButton(window, atk_key);
		interact_btn = glfwGetMouseButton(window, interact_key);
		right_key = glfwGetMouseButton(window, confirm_key);
		up_key = glfwGetMouseButton(window, confirm_key);
		left_key = glfwGetMouseButton(window, confirm_key);
		down_key = glfwGetMouseButton(window, confirm_key);
		for (int i = 0; i < 4; i++){
			if (toggle_key){
				item_btn[i] = glfwGetMouseButton(window, slot_key[i]);
			}else{
				skill_btn[i] = glfwGetMouseButton(window, slot_key[i]);
			}
		}

		if (confirm_btn){ std::cout << "confirm" << std::endl; }
		if (cancel_btn){ std::cout << "confirm" << std::endl; }

	}

	static void init(){
		std::fstream file;
		file.open("keyboard_config.txt");
		if (file.is_open()){
			char is[256]; 
			char** buf;
			file.getline(is, 256);
			confirm_key = strtol(is,buf,10);
			file.getline(is, 256);
			cancel_key = strtol(is, buf, 10);
			file.getline(is, 256);
			start_key = strtol(is, buf, 10);
			file.getline(is, 256);
			toggle_key = strtol(is, buf, 10);
			file.getline(is, 256);
			atk_key = strtol(is, buf, 10);
			file.getline(is, 256);
			interact_key = strtol(is, buf, 10);
			file.getline(is, 256);
			right_key = strtol(is, buf, 10);
			file.getline(is, 256);
			up_key = strtol(is, buf, 10);
			file.getline(is, 256);
			left_key = strtol(is, buf, 10);
			file.getline(is, 256);
			down_key = strtol(is, buf, 10);
			file.getline(is, 256);
			slot_key[0] = strtol(is, buf, 10);
			file.getline(is, 256);
			slot_key[1] = strtol(is, buf, 10);
			file.getline(is, 256);
			slot_key[2] = strtol(is, buf, 10);
			file.getline(is, 256);
			slot_key[3] = strtol(is, buf, 10);
			file.close;
		};

		if (confirm_key == 0){

		}
	}

	static void init_default(){
		confirm_key = GLFW_KEY_SPACE;
		cancel_key = GLFW_KEY_RIGHT_ALT;
		start_key = GLFW_KEY_ENTER;
		toggle_key = GLFW_KEY_LEFT_SHIFT;
		atk_key = GLFW_KEY_SPACE;
		interact_key = GLFW_KEY_RIGHT_ALT;
		right_key = GLFW_KEY_D;
		up_key = GLFW_KEY_W;
		left_key = GLFW_KEY_A;
		down_key = GLFW_KEY_S;
		slot_key[0] = GLFW_KEY_O;
		slot_key[1] = GLFW_KEY_P;
		slot_key[2] = GLFW_KEY_LEFT_BRACKET;
		slot_key[3] = GLFW_KEY_RIGHT_BRACKET;
	}

	static void push_to_input_string(int key, int scancode){
		if (key == GLFW_KEY_UNKNOWN){
			//temp_key = scancode;
		}else if (key == 32){
			input_string = input_string + " ";
		}
		else if (key == 32){
			input_string = input_string + " ";
		}
		else if (key == 32){
			input_string = input_string + " ";
		}
	}



};

#endif