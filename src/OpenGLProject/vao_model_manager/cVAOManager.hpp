/*
 *	File name:		"cVAOManager.hpp"
 *	Source:			INFO3111
 *	Purpose:		ADT to manage models after loading from files into GPU
 *					Will load the models and place them into the vertex and index buffers to be drawn
 *	Modified by:	Vo, Dinh Tue Minh
 *					Use C++17 and avoid memory lead
 *	Date:			8/28/2020 3:01:24 PM
 */


#ifndef _C_VAOMANAGER_HPP_
#define _C_VAOMANAGER_HPP_

#include "../headers/globalOpenGL.hpp"
#include <string>
#include <map>

 // The vertex structure 
 // that's ON THE GPU (eventually) 
 // So dictated from THE SHADER:
 //		in vec4 vCol;
 //		in vec4 vNorm;
 //		in vec4 vPos;
 //		in vec4 vUVx2;
struct sVert {
	sVert();
	float x, y, z, w;
	float nx, ny, nz, nw; // ignore the 4th element
	float r, g, b, a;
	float u1, v1, u2, v2; // 2 sets of textture ("UV") coordinates
};


struct sModelDrawInfo {
	~sModelDrawInfo();
	sModelDrawInfo();

	std::string meshName;

	unsigned int VAO_ID;

	unsigned int vertexBufferID;
	unsigned int vertexBufferStartIndex;
	unsigned int numberOfVertices;

	unsigned int indexBufferID;
	unsigned int indexBufferStartIndex;
	unsigned int numberOfIndices;
	unsigned int numberOfTriangles;

	// The "local" CPU side data
	sVert* pVertices;
	unsigned int* pIndices;
};


class cVAOManager {
public:
	~cVAOManager();
	cVAOManager() = default;

	bool load_model_into_VAO(std::string fileName, GLuint shaderProgramID);
	// We don't want to return an int, likely
	sModelDrawInfo* find_MDI_by_model_name(std::string filename);

private:
	/* model name to ModelDrawInfo */
	std::map<std::string, sModelDrawInfo*> modelNameToMDI_;

	// Loads the ply model file into RAM
	sModelDrawInfo* load_the_model_(std::string fileName);
};

#endif	// _C_VAOMANAGER_HPP_
