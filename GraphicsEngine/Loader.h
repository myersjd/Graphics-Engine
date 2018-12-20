#pragma once

#include "libs.h"

class Loader
{
public:
	Loader();
	~Loader();

	bool loadObject(const char* file_path,
		std::vector<glm::vec3>& vertices,
		std::vector<glm::vec2>& uvs,
		std::vector<glm::vec3>& normals,
		std::vector<unsigned short>& indices);


private:


};

