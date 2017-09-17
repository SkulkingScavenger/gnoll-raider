#ifndef SHADER_H_
#define SHADER_H_

#include <string>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class Shader{
public:
	GLuint ID;

	void compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource){
		GLuint sVertex, sFragment, gShader;
		// Vertex Shader
		sVertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(sVertex, 1, &vertexSource, NULL);
		glCompileShader(sVertex);
		checkCompileErrors(sVertex, "VERTEX");
		// Fragment Shader
		sFragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(sFragment, 1, &fragmentSource, NULL);
		glCompileShader(sFragment);
		checkCompileErrors(sFragment, "FRAGMENT");
		// If geometry shader source code is given, also compile geometry shader
		if (geometrySource != nullptr)
		{
			gShader = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(gShader, 1, &geometrySource, NULL);
			glCompileShader(gShader);
			checkCompileErrors(gShader, "GEOMETRY");
		}
		// Shader Program
		this->ID = glCreateProgram();
		glAttachShader(this->ID, sVertex);
		glAttachShader(this->ID, sFragment);
		if (geometrySource != nullptr)
			glAttachShader(this->ID, gShader);
		glLinkProgram(this->ID);
		checkCompileErrors(this->ID, "PROGRAM");
		// Delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(sVertex);
		glDeleteShader(sFragment);
		if (geometrySource != nullptr)
			glDeleteShader(gShader);
	}

	// activate the shader
	// ------------------------------------------------------------------------
	Shader &use(){
		glUseProgram(this->ID);
		return *this;
	}
	// utility uniform functions
	// ------------------------------------------------------------------------
	void setBool(const std::string &name, bool value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	// ------------------------------------------------------------------------
	void setInt(const std::string &name, int value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setFloat(const std::string &name, float value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

	void SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform2f(glGetUniformLocation(this->ID, name), x, y);
	}
	void SetVector2f(const GLchar *name, const glm::vec2 &value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
	}

	void SetVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
	}
	void SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
	}

	void SetVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
	}
	void SetVector4f(const GLchar *name, const glm::vec4 &value, GLboolean use_shader = false)
	{
		if (use_shader){ this->use(); }
		glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
	}

	void SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false)
	{
		if (useShader)
			this->use();
		glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
	}
	
private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(GLuint shader, std::string type)
	{
		GLint success;
		GLchar infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}

};


#endif