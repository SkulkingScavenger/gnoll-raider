#ifndef SPRITE_RENDERER_H_
#define SPRITE_RENDERER_H_

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"

class Sprite_renderer{
public:
	Sprite_renderer(Shader &shader){
		this->shader = shader;
		this->init_render_data();
	}

	void draw_sprite(Texture &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color){
		// Prepare transformations
		this->shader.use();
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(position, 0.0f));  // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)

		model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // Move origin of rotation to center of quad
		model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate
		model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // Move origin back

		model = glm::scale(model, glm::vec3(size, 1.0f)); // Last scale

		this->shader.SetMatrix4("model", model);

		// Render textured quad
		this->shader.SetVector3f("spriteColor", color);

		glActiveTexture(GL_TEXTURE0);
		texture.bind();

		glBindVertexArray(this->quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}

private:
	Shader shader;
	GLuint quadVAO;

	void init_render_data(){
		// Configure VAO/VBO
		GLuint VBO;
		GLfloat vertices[] = {
			// Pos      // Tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		glGenVertexArrays(1, &this->quadVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(this->quadVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

};

#endif