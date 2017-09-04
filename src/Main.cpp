
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int win_w = 600;
int win_h = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
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

	//Main Loop
	while (!glfwWindowShouldClose(window))
	{
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