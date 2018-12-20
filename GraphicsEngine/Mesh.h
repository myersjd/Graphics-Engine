#pragma once

#include "libs.h"
#include <list>
#include "Shader.h"
class Mesh
{
public:
	Mesh(
		Vertex* vertexArray, const unsigned& vertexCount,
		GLuint* indexArray, const unsigned& indexCount,
		glm::vec3 position = glm::vec3(0.f),
		glm::vec3 rotation = glm::vec3(0.f),
		glm::vec3 scale = glm::vec3(1.f)
	);
	~Mesh();

	void render(Shader& shader);

private:

	unsigned int numVertices;
	unsigned int numIndices;

	GLuint vao;
	GLuint vbo;
	GLuint veo;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;


};

