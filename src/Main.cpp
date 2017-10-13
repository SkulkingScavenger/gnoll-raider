
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"
#include "resource_manager.h"
#include "input_manager.h"


int win_w = 512;
int win_h = 480;

Game game(win_w, win_h);


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window){
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			game.keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			game.keys[key] = GL_FALSE;
	}
}



int main(int argc, char** argv){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MAC OSX specific settings
	#endif

	//Initialize GLFW window
	GLFWwindow* window = glfwCreateWindow(win_w, win_h, "Gnoll Raider", NULL, NULL);
	if (window == NULL){
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Load all openGL function pointers via GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	// OpenGL configuration
	glViewport(0, 0, win_w, win_h);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Initialize Game
	game.init();
	game.state = GAME_ACTIVE;

	// DeltaTime variables
	GLfloat delta_time = 0.0f;
	GLfloat frame_previous = 0.0f;
	GLfloat frame_current = 0.0f;

	//Main Loop
	while (!glfwWindowShouldClose(window))
	{
		//get delta time
		frame_current = glfwGetTime();
		delta_time = frame_current - frame_previous;
		frame_previous = frame_current;

		//input
		//game.process_input(delta_time);

		//update
		//game.update(delta_time);

		//draw
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		game.draw();

		//manage buffers and call events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

//Windows Specific entry point
#ifdef _WIN32
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
		char** args = {};
		return main(0, args);
	}
#endif