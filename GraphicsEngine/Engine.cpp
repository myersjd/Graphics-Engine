#include "Engine.h"

#define MAJOR 4
#define MINOR 4

Engine::Engine()
{
}


Engine::~Engine()
{
	glfwTerminate();
}

bool Engine::initWindow(const int WIDTH, const int HEIGHT, const char* TITLE) {

	//Initialize GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}

	//Set Hints
	glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MAJOR); //Opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MINOR);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For Mac
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Set Profile

	//Create Window
	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW Window\n");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	//Initialize GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return false;
	}

	return true;
}

void Engine::initAssets()
{


}

void Engine::run(){

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	//Clear Color
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);


	//Temporary mesh thing
	Vertex vertices[] = {
		//Position							//Color								//Tex Coord					//Normals		
		glm::vec3(-0.5f, 0.5f, 0.f),		glm::vec3(0.1f, 0.3f, 1.0f),		glm::vec2(0.0f, 0.0f),		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(-0.5f, -0.5f, 0.f),		glm::vec3(0.7f, 0.0f, 0.4f),		glm::vec2(0.0f, 0.0f),		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.5f, -0.5f, 0.f),		glm::vec3(0.1f, 0.7f, 0.2f),		glm::vec2(0.0f, 0.0f),		glm::vec3(0.0f, 0.0f, -1.0f),
		glm::vec3(0.5f, 0.5f, 0.f),			glm::vec3(0.6f, 0.4f, 1.3f),		glm::vec2(0.0f, 0.0f),		glm::vec3(0.0f, 0.0f, -1.0f)
	};

	GLuint indices[] = {
		0, 1, 2, 0, 2, 3
	};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(Vertex), indices, sizeof(indices)/sizeof(GLuint));
	char vertex[] = "SimpleVertexShader.vertexshader";
	char fragment[] = "SimpleFragmentShader.fragmentshader";
	Shader shader(vertex, fragment);
	

	

	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0) {
		//Clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Input

		//Update

		//Render
		mesh.render(shader);


		//End
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	


}
