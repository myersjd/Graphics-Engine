#include "Engine.h"

int main() {

	const int WIDTH = 920;
	const int HEIGHT = 650;
	const char* TITLE = "GRAPHICS ENGINE";

	Engine engine;
	if (!engine.initWindow(WIDTH, HEIGHT, TITLE)) {
		fprintf(stderr, "Failed to initialize Engine\n");
		getchar();
		return -1;
	}
	engine.initAssets();

	engine.run();



	return 0;
}