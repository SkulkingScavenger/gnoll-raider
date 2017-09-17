#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>

class Texture{
public:
	GLuint ID;
	GLuint width, height;
	// Texture Format
	GLuint Internal_Format; // Format of texture object
	GLuint Image_Format; // Format of loaded image
	// Texture configuration
	GLuint Wrap_S; // Wrapping mode on S axis
	GLuint Wrap_T; // Wrapping mode on T axis
	GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
	GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels

	Texture()
		: width(0), height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR){
		glGenTextures(1, &this->ID);
	}

	void generate(GLuint w, GLuint h, unsigned char* data){
		this->width = w;
		this->height = h;
		// Create Texture
		glBindTexture(GL_TEXTURE_2D, this->ID);
		glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
		// Set Texture wrap and filter modes
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void bind(){
		glBindTexture(GL_TEXTURE_2D, this->ID);
	}

};

#endif