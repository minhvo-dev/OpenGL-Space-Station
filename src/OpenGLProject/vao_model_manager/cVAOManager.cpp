/*
 *	File name:		"cVAOManager.hpp"
 *	Source:			INFO3111
 *	Purpose:		Implements the cVAOManager ADT
 *	Modified by:	Vo, Dinh Tue Minh
 *					Use C++17 and avoid memory lead
 *	Date:			8/28/2020 3:01:24 PM
 */

#include "../headers/globalOpenGL.hpp"
#include "cVAOManager.hpp"

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/vec2.hpp>

#include <fstream>
#include <vector>
#include <sstream>

sVert::sVert()
	: x(0.0f), y(0.0f), z(0.0f), w(1.0f),		// default pos at origin
	nx(0.0f), ny(0.0f), nz(0.0f), nw(1.0f),		// norm
	r(1.0f), g(1.0f), b(1.0f), a(1.0f),			// default color is white
	u1(0.0f), v1(0.0f), u2(0.0f), v2(0.0f) {}	// texture indexes

sModelDrawInfo::sModelDrawInfo()
	: VAO_ID(0), vertexBufferID(0), vertexBufferStartIndex(0), numberOfVertices(0),
	indexBufferID(0), indexBufferStartIndex(0), numberOfIndices(0), numberOfTriangles(0),
	pVertices(nullptr), pIndices(nullptr) {}

sModelDrawInfo::~sModelDrawInfo() {
	delete[] pVertices;
	delete[] pIndices;
}

cVAOManager::~cVAOManager() {
	// clean up
	for (auto p : modelNameToMDI_) {
		delete p.second;
	}
}

// Load the model from file
bool cVAOManager::load_model_into_VAO(std::string fileName, GLuint shaderProgramID) {
	sModelDrawInfo *pInfo = nullptr;
	if (!(pInfo = this->load_the_model_(fileName))) {
		return false;
	}
	sModelDrawInfo &drawInfo = *pInfo; // for convinient

	// Create a VAO (Vertex Array Object), which will 
	//	keep track of all the 'state' needed to draw 
	//	from this buffer...

	// Ask OpenGL for a new buffer ID...
	glGenVertexArrays(1, &(drawInfo.VAO_ID));
	// "Bind" this buffer:
	// - aka "make this the 'current' VAO buffer
	glBindVertexArray(drawInfo.VAO_ID);

	// Now ANY state that is related to vertex or index buffer
	//	and vertex attribute layout, is stored in the 'state' 
	//	of the VAO... 


	// NOTE: OpenGL error checks have been omitted for brevity
//	glGenBuffers(1, &vertex_buffer);
	glGenBuffers(1, &(drawInfo.vertexBufferID));

	//	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, drawInfo.vertexBufferID);
	// sVert vertices[3]
	glBufferData(GL_ARRAY_BUFFER,
				 sizeof(sVert) * drawInfo.numberOfVertices,	// ::g_NumberOfVertsToDraw,	// sizeof(vertices), 
				 (GLvoid*)drawInfo.pVertices,							// pVertices,			//vertices, 
				 GL_STATIC_DRAW);


	// Copy the index buffer into the video card, too
	// Create an index buffer.
	glGenBuffers(1, &(drawInfo.indexBufferID));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawInfo.indexBufferID);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER,			// Type: Index element array
				 sizeof(unsigned int) * drawInfo.numberOfIndices,
				 (GLvoid*)drawInfo.pIndices,
				 GL_STATIC_DRAW);

	// Set the vertex attributes.

	// Must match the name in the vertex shader
	GLint vpos_location = glGetAttribLocation(shaderProgramID, "vPos");
	GLint vcol_location = glGetAttribLocation(shaderProgramID, "vCol");
	GLint vnorm_location = glGetAttribLocation(shaderProgramID, "vNorm");
	GLint vUVx2_location = glGetAttribLocation(shaderProgramID, "vUVx2");


	// Set the vertex attributes for this shader
	glEnableVertexAttribArray(vpos_location);
	glVertexAttribPointer(vpos_location, 4,
						  GL_FLOAT, GL_FALSE,
						  sizeof(sVert),					// stride (size of the data type)
						  (void*)(offsetof(sVert, x)));

	glEnableVertexAttribArray(vcol_location);
	glVertexAttribPointer(vcol_location, 4,
						  GL_FLOAT, GL_FALSE,
						  sizeof(sVert),
						  (void*)(offsetof(sVert, r)));

	glEnableVertexAttribArray(vnorm_location);
	glVertexAttribPointer(vnorm_location, 4,
						  GL_FLOAT, GL_FALSE,
						  sizeof(sVert),
						  (void*)(offsetof(sVert, nx)));

	glEnableVertexAttribArray(vUVx2_location);
	glVertexAttribPointer(vUVx2_location, 4,
						  GL_FLOAT, GL_FALSE,
						  sizeof(sVert),
						  (void*)(offsetof(sVert, u1)));

	// Now that all the parts are set up, set the VAO to zero
	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(vpos_location);
	glDisableVertexAttribArray(vcol_location);
	glDisableVertexAttribArray(vnorm_location);
	glDisableVertexAttribArray(vUVx2_location);

	// Store the draw information into the map
	this->modelNameToMDI_[drawInfo.meshName] = pInfo;

	return true;
}

sModelDrawInfo* cVAOManager::find_MDI_by_model_name(std::string filename) {
	auto it = this->modelNameToMDI_.find(filename);
	if (it == this->modelNameToMDI_.end()) {
		return nullptr;
	}
	return it->second;
}


sModelDrawInfo* cVAOManager::load_the_model_(std::string fileName) {
	// Open the file. 
	std::ifstream thePlyFile(fileName);
	if (!thePlyFile) {
		return nullptr; // cannot open the file
	}

	sModelDrawInfo *pInfo = new sModelDrawInfo();
	sModelDrawInfo &drawInfo = *pInfo; // for convinient
	drawInfo.meshName = fileName;
	// Read until we hit the word "vertex"
	std::string temp;
	while (thePlyFile >> temp) {
		if (temp == "vertex") {
			break;
		}
	};
	// read the number of vertices...
	thePlyFile >> drawInfo.numberOfVertices;

	// Read until we hit the word "face"
	while (thePlyFile >> temp) {
		if (temp == "face") {
			break;
		}
	};
	// read the number of triangles...
	thePlyFile >> drawInfo.numberOfTriangles;

	// Read until we hit the word "end_header"
	// end of the header
	while (thePlyFile >> temp) {
		if (temp == "end_header") {
			break;
		}
	};

	// This is set up to match the ply (3d model) file 
	struct sVertPly {
		glm::vec4 pos;
		glm::vec4 norm;
		glm::vec4 colour;
		glm::vec2 texture;
	};

	std::vector<sVertPly> vecTempPlyVerts;
	vecTempPlyVerts.reserve(drawInfo.numberOfVertices);
	sVertPly tempVert;
	// Load the vertices...
	for (unsigned int index = 0; index != drawInfo.numberOfVertices; index++) {
		thePlyFile >> tempVert.pos.x >> tempVert.pos.y >> tempVert.pos.z;
		tempVert.pos.w = 1.0f; // arbitrarily set to 1

		thePlyFile >> tempVert.norm.x >> tempVert.norm.y >> tempVert.norm.z;
		tempVert.norm.w = 1.0f; // arbitrarily set to 1

		thePlyFile >> tempVert.colour.r >> tempVert.colour.g
			>> tempVert.colour.b >> tempVert.colour.a;

		thePlyFile >> tempVert.texture.x /* texture u */ >> tempVert.texture.y /* texture v */;
		// Scale the colour from 0 to 1, instead of 0 to 255
		tempVert.colour.r /= 255.0f;
		tempVert.colour.g /= 255.0f;
		tempVert.colour.b /= 255.0f;
		tempVert.colour.a /= 255.0f;

		vecTempPlyVerts.push_back(tempVert);
	}

	// Note: The format the file (ply) is DIFFERENT from this array:
	// - sVertPly was made to match the file format
	// - sVert was made to match the shader vertex attrib format
	drawInfo.pVertices = new sVert[drawInfo.numberOfVertices];

	// copy the data from the sVertPly to sVert
	for (unsigned int index = 0; index != drawInfo.numberOfVertices; ++index) {
		// pos
		drawInfo.pVertices[index].x = vecTempPlyVerts[index].pos.x;
		drawInfo.pVertices[index].y = vecTempPlyVerts[index].pos.y;
		drawInfo.pVertices[index].z = vecTempPlyVerts[index].pos.z;
		drawInfo.pVertices[index].w = vecTempPlyVerts[index].pos.w;

		// norm
		drawInfo.pVertices[index].nx = vecTempPlyVerts[index].norm.x;
		drawInfo.pVertices[index].ny = vecTempPlyVerts[index].norm.y;
		drawInfo.pVertices[index].nz = vecTempPlyVerts[index].norm.z;
		drawInfo.pVertices[index].nw = vecTempPlyVerts[index].norm.w;

		// color
		drawInfo.pVertices[index].r = vecTempPlyVerts[index].colour.r;
		drawInfo.pVertices[index].g = vecTempPlyVerts[index].colour.g;
		drawInfo.pVertices[index].b = vecTempPlyVerts[index].colour.b;
		drawInfo.pVertices[index].a = vecTempPlyVerts[index].colour.a;

		// texture
		drawInfo.pVertices[index].u1 = vecTempPlyVerts[index].texture.x;
		drawInfo.pVertices[index].v1 = vecTempPlyVerts[index].texture.y;
		drawInfo.pVertices[index].u2 = vecTempPlyVerts[index].texture.x;
		drawInfo.pVertices[index].v2 = vecTempPlyVerts[index].texture.y;
	}


	//struct sTriPly {
	//	unsigned int vindex[3];		// the 3 indices
	//	sVertPly verts[3];			// The actual vertices
	//};

	// read the vertex indexes from the Ply file
	// and copy to the vertex array buffer
	drawInfo.numberOfIndices = drawInfo.numberOfTriangles * 3;
	drawInfo.pIndices = new unsigned int[drawInfo.numberOfIndices];
	for (unsigned int index = 0, data = 3; index != drawInfo.numberOfTriangles; ++index) {
		// 3 5622 5601 5640
		thePlyFile >> data;						// the "3" at the start
		thePlyFile >> data;	drawInfo.pIndices[index * 3 + 0] = data;
		thePlyFile >> data;	drawInfo.pIndices[index * 3 + 1] = data;
		thePlyFile >> data;	drawInfo.pIndices[index * 3 + 2] = data;

	}
	thePlyFile.close();
	return pInfo;
}
