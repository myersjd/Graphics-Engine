#pragma once
#include "libs.h"
#include "Loader.h"
#include "Model.h"
#include "Mesh.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool initWindow(const int WIDTH, const int HEIGHT, const char* TITLE);
	void initAssets();
	void run();

private:
	GLFWwindow* window;
};
