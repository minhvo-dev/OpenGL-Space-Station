/*
 *	File name:	"cMeshObject.hpp"
 *	Date:		7/10/2020 4:11:47 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Class that stores information of an object
 *              that we want to draw in the window.
 */

#pragma once

#ifndef _C_MESHOBJECT_HPP_
#define _C_MESHOBJECT_HPP_

#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

#include <iostream>

class cMeshObject {
public:
	~cMeshObject() = default;
	cMeshObject();

	std::string meshName;
	glm::vec3 pos;			// 0,0,0 (origin)
	//glm::vec4 colourRGBA;	// 0,0,0,1 (black)
	glm::vec4 diffuseRGBA;			// RGB color of the object
									// A for alpha transparency from 0.0 (completely transparent) to 1.0 (solid)
	glm::vec4 specularRGB_Power;	// RGB highlight color
									// Power (4th value): how shiny something is
									// Power STARTS at 1.0 and can go up to 1000s (1.0 is no shiny)
	glm::vec3 orientation;	// rotation xyz
	float scale;			// 1.0f
	bool isWireframe;		// false

	bool isVisible;
	std::string friendlyName;

	// These are the textures of this object
	static const unsigned int NUMBEROFTEXTURES = 4;
	std::string  textureNames[NUMBEROFTEXTURES];	// four texture names
	float textureRatios[NUMBEROFTEXTURES];			// four texture "ratios"
	
	std::string discardTexture;

	std::string transparenceTexture;

	//friend std::istream& operator>>(std::istream &is, cMeshObject &obj);
	friend std::ostream& operator<<(std::ostream &os, cMeshObject const &obj);
};

#endif // !_C_MESHOBJECT_HPP_
