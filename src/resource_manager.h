#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "graphics/texture.h"
#include "graphics/shader.h"
#include "graphics/sprite.h"
#include "utility/dynamic_array.h"

static std::map<std::string, Shader> shaders;
static std::map<std::string, Texture> textures;
static dynamic_array_spriteptr* sprite_array;
class Resource_manager{
public:
	static void load_sprites(unsigned int sprite_count){
		sprite_array = new dynamic_array_spriteptr(sprite_count);
		for (int i = 0; i < sprite_count; i++){
			Texture tex = load_texture("assets/sprites/gnoll.png", GL_TRUE, "gnoll");
			Sprite* spr = new Sprite(1, tex.width, tex.height, &tex,0,0);
			sprite_array->insert_element_at(i, spr);
		}
	}

	static Sprite* get_sprite(unsigned int sprite_index){
		Sprite* temp;
		temp = sprite_array->get_element(sprite_index);
		return temp;
	}
	

	static Shader load_shader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name){
		shaders[name] = load_shader_from_file(vShaderFile, fShaderFile, gShaderFile);
		return shaders[name];
	}

	static Shader get_shader(std::string name){
		return shaders[name];
	}

	static Texture load_texture(const GLchar *file, GLboolean alpha, std::string name){
		textures[name] = load_texture_from_file(file, alpha);
		return textures[name];
	}

	static Texture get_texture(std::string name){
		return textures[name];
	}

private:

	Resource_manager(){}

	static Shader load_shader_from_file(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile){
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::string geometryCode;
		try
		{
			// Open files
			std::ifstream vertexShaderFile(vShaderFile);
			std::ifstream fragmentShaderFile(fShaderFile);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vertexShaderFile.rdbuf();
			fShaderStream << fragmentShaderFile.rdbuf();
			// close file handlers
			vertexShaderFile.close();
			fragmentShaderFile.close();
			// Convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
			// If geometry shader path is present, also load a geometry shader
			if (gShaderFile != nullptr)
			{
				std::ifstream geometryShaderFile(gShaderFile);
				std::stringstream gShaderStream;
				gShaderStream << geometryShaderFile.rdbuf();
				geometryShaderFile.close();
				geometryCode = gShaderStream.str();
			}
		}
		catch (std::exception e)
		{
			std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
		}
		const GLchar *vShaderCode = vertexCode.c_str();
		const GLchar *fShaderCode = fragmentCode.c_str();
		const GLchar *gShaderCode = geometryCode.c_str();
		// 2. Now create shader object from source code
		Shader shader;
		shader.compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
		return shader;
	}

	static Texture load_texture_from_file(const GLchar *file, GLboolean alpha){
		// Create Texture object
		Texture texture;
		if (alpha)
		{
			texture.Internal_Format = GL_RGBA;
			texture.Image_Format = GL_RGBA;
		}
		// Load image
		int width, height;
		unsigned char* image = stbi_load(file, &width, &height, 0, 4);
		// Now generate texture
		texture.generate(width, height, image);
		// And finally free image data
		stbi_image_free(image);
		return texture;
	}

};

#endif