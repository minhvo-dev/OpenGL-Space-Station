/*
 *	File name:		"cLightManager.hpp"
 *	Source:			INFO3111
 *	Purpose:		Manage all light source in the program
 *	Modified by:	Vo, Dinh Tue Minh
 *					Refactor and clean up
 *	Date:			8/28/2020 8:25:45 PM
 */

#pragma once

#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <vector>
#include <string>
#include <iostream>

struct sLight {
	sLight();
	~sLight() = default;

	glm::vec4 position;
	glm::vec4 diffuse;
	glm::vec4 specular;		// rgb = highlight colour, w = power
	glm::vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	glm::vec4 direction;	// Spot, directional lights
	glm::vec4 param1;		// x = lightType, y = inner angle, z = outer angle, w = TBD
	glm::vec4 param2;		// x = 0 for off, 1 for on


	// returns true if light is "on" (param2.x = 1)
	bool is_on(void) const;

	int position_UniLoc;
	int diffuse_UniLoc;
	int specular_UniLoc;
	int atten_UniLoc;
	int direction_UniLoc;
	int param1_UniLoc;
	int param2_UniLoc;


	friend std::ostream& operator<<(std::ostream &os, sLight const &light);
	friend std::istream& operator>>(std::istream &is, sLight &light);
};

class cLightManager {
public:
	cLightManager();
	// STRONGLY suggest you make something like this... 

	//static const unsigned int NUMBEROFLIGHTS = 10;
	static const unsigned int NUMBEROFLIGHTS = 40;

	std::vector<sLight> vecLights;

	// Do all the glGetUniformLocation() calls and store them...
	void load_uniform_locations(int shaderID);

	// This would do the  nasty glUniformXf() calls
	// Start of every frame or scene
	void copy_light_calues_to_shader(void);

};


