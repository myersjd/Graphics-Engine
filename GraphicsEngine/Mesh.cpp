#include "Mesh.h"



Mesh::Mesh(
	Vertex* vertexArray, const unsigned& vertexCount,
	GLuint* indexArray, const unsigned& indexCount,
	glm::vec3 position,
	glm::vec3 rotation,
	glm::vec3 scale
)
{
	numVertices = vertexCount;
	numIndices = indexCount;

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;


	//Init VAO

	//Generate VAO and bind
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Generate VBO, bind, and set data
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*numVertices, vertexArray, GL_STATIC_DRAW);

	//Generate VEO, bind, and set data
	glGenBuffers(1, &veo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, veo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*numIndices, indexArray, GL_STATIC_DRAW);


	//Set Attributes

	//Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));

	//Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));

	//Texture
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));

	//Normal
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//Unbind VAO
	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	//Delete VAO, VBO, VEO
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &veo);
}

void Mesh::render(Shader& shader)
{
	//Use Program
	shader.use();

	//Bind VAO
	glBindVertexArray(vao);
	//DRAW
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);

	//Clean up
	glBindVertexArray(0);
	glUseProgram(0);

}


