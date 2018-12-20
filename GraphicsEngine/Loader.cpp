#include "Loader.h"

//Temporary
#include "objloader.hpp"
#include "vboindexer.hpp"

#include <fstream>
#include <algorithm>
#include <sstream>



Loader::Loader()
{
}


Loader::~Loader()
{

}

bool Loader::loadObject(const char* file_path,
	std::vector<glm::vec3>& vertices,
	std::vector<glm::vec2>& uvs,
	std::vector<glm::vec3>& normals,
	std::vector<unsigned short>& indices) {


	std::vector<glm::vec3> verts;
	std::vector<glm::vec2> uv;
	std::vector<glm::vec3> norm;
	bool success = loadOBJ("suzanne.obj", verts, uv, norm);

	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	indexVBO(verts, uv, norm, indices, vertices, uvs, normals);

	return success;
}

