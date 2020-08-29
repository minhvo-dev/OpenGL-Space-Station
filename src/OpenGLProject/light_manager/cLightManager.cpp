/*
 *	File name:		"cLightManager.cpp"
 *	Source:			INFO3111
 *	Purpose:		Manage all light source in the program
 *	Modified by:	Vo, Dinh Tue Minh
 *					Refactor and clean up
 *	Date:			8/28/2020 8:25:45 PM
 */

#include "../headers/globalOpenGL.hpp"	// GLFW and glad calls
#include "../headers/globalVariables.hpp"
#include "cLightManager.hpp"

#include <sstream>			// String Stream
#include <string>

sLight::sLight()
	: position(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), // default is origin
	diffuse(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)), // default is white
	specular(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)), // default is white
	atten(glm::vec4(0.0f, 0.0f, 0.0f, 10.0f)),
	direction(glm::vec4(0.0f, -1.0f, 0.0f, 10.0f)), // down the Y-axis
	param1(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), // default is point light
	param2(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), // default is off
	position_UniLoc(-1),
	diffuse_UniLoc(-1),
	specular_UniLoc(-1),
	atten_UniLoc(-1),
	direction_UniLoc(-1),
	param1_UniLoc(-1),
	param2_UniLoc(-1) {}

// returns true if light is "on" (param2.x = 1)
bool sLight::is_on(void) const {
	return this->param2.x == 1.0f;
}


cLightManager::cLightManager() {
	for (int count = 0; count != NUMBEROFLIGHTS; count++) {
		this->vecLights.push_back(sLight());
	}
	return;
}

void cLightManager::load_uniform_locations(int shaderID) {
	
	// Go through all the lights and set the uniform locations...
	for (unsigned int lightIndex = 0; lightIndex != NUMBEROFLIGHTS; lightIndex++) {
		std::stringstream ssLightUniformName;

		//"theLights[0].position"
		ssLightUniformName << "theLights[" << lightIndex << "]."; // must match the fragment shader
		std::string lightBaseName = ssLightUniformName.str();

		// Get position location
		std::string strPosition = lightBaseName + "position";
		this->vecLights[lightIndex].position_UniLoc = glGetUniformLocation(shaderID, strPosition.c_str());

		// Diffuse...
		std::string strDiffuse = lightBaseName + "diffuse";
		this->vecLights[lightIndex].diffuse_UniLoc = glGetUniformLocation(shaderID, strDiffuse.c_str());

		// Specular...
		std::string strSpecular = lightBaseName + "specular";		// rgb = highlight colour, w = power
		this->vecLights[lightIndex].specular_UniLoc = glGetUniformLocation(shaderID, strSpecular.c_str());

		// Attenuation
		std::string strAtten = lightBaseName + "atten";		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
		this->vecLights[lightIndex].atten_UniLoc = glGetUniformLocation(shaderID, strAtten.c_str());

		// Direction
		std::string strDirection = lightBaseName + "direction";	// Spot, directional lights
		this->vecLights[lightIndex].direction_UniLoc = glGetUniformLocation(shaderID, strDirection.c_str());

		// Param1
		std::string strParam1 = lightBaseName + "param1";		// x = lightType, y = inner angle, z = outer angle, w = TBD
		this->vecLights[lightIndex].param1_UniLoc = glGetUniformLocation(shaderID, strParam1.c_str());

		// Param2
		std::string strParam2 = lightBaseName + "param2";		// x = 0 for off, 1 for on
		this->vecLights[lightIndex].param2_UniLoc = glGetUniformLocation(shaderID, strParam2.c_str());
	}

	return;
}


void cLightManager::copy_light_calues_to_shader(void) {
	// Call glUniformX() a million times...
	for (unsigned int index = 0; index != NUMBEROFLIGHTS; index++) {


		glUniform4f(
			this->vecLights[index].position_UniLoc,
			this->vecLights[index].position.x,
			this->vecLights[index].position.y,
			this->vecLights[index].position.z,
			1.0f);		// set 4th value to 1.0f if unsure

		glUniform4f(
			this->vecLights[index].diffuse_UniLoc,
			this->vecLights[index].diffuse.r,
			this->vecLights[index].diffuse.g,
			this->vecLights[index].diffuse.b,
			1.0f);		// set 4th value to 1.0f if unsure

		glUniform4f(
			this->vecLights[index].specular_UniLoc,
			this->vecLights[index].specular.r,
			this->vecLights[index].specular.g,
			this->vecLights[index].specular.b,
			this->vecLights[index].specular.w);		// set 4th value to 1.0f if unsure


		glUniform4f(
			this->vecLights[index].atten_UniLoc,
			this->vecLights[index].atten.x,			// Constant
			this->vecLights[index].atten.y,			// Linear
			this->vecLights[index].atten.z,			// Quadratic
			this->vecLights[index].atten.w);

		glUniform4f(
			this->vecLights[index].direction_UniLoc,
			this->vecLights[index].direction.x,
			this->vecLights[index].direction.y,
			this->vecLights[index].direction.z,
			1.0f);		

		//vec4 param1;	// x = lightType, y = inner angle, z = outer angle, w = TBD
						// 0 = pointlight
						// 1 = spot light
						// 2 = directional light
		glUniform4f(
			this->vecLights[index].param1_UniLoc,
			this->vecLights[index].param1.x,		// x = lightType
			this->vecLights[index].param1.y,		// y = inner angle
			this->vecLights[index].param1.z,		// z = outer angle, w = TBD
			this->vecLights[index].param1.w);		// set 4th value to 1.0f if unsure

		//vec4 param2;	// x = 0 for off, 1 for on
		glUniform4f(
			this->vecLights[index].param2_UniLoc,
			this->vecLights[index].param2.x,		// x = 0 for off, 1 for on
			this->vecLights[index].param2.y,
			this->vecLights[index].param2.z,
			this->vecLights[index].param2.w);		// set 4th value to 1.0f if unsure

	}
}

std::ostream& operator<<(std::ostream &os, sLight const &light) {
	//glm::vec4 position;
	//glm::vec4 diffuse;
	//glm::vec4 specular;		// rgb = highlight colour, w = power
	//glm::vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	//glm::vec4 direction;	// Spot, directional lights
	//glm::vec4 param1;		// x = lightType, y = inner angle, z = outer angle, w = TBD
	//glm::vec4 param2;		// x = 0 for off, 1 for on
	return os << light.position.x << ' ' << light.position.y << ' ' << light.position.z << ' ' << light.position.w << ' '
		<< light.diffuse.r << ' ' << light.diffuse.g << ' ' << light.diffuse.b << ' ' << light.diffuse.a << ' '
		<< light.specular.r << ' ' << light.specular.g << ' ' << light.specular.b << ' ' << light.specular.a << ' '
		<< light.atten.x << ' ' << light.atten.y << ' ' << light.atten.z << ' ' << light.atten.w << ' '
		<< light.direction.x << ' ' << light.direction.y << ' ' << light.direction.z << ' ' << light.direction.w << ' '
		<< light.param1.x << ' ' << light.param1.y << ' ' << light.param1.z << ' ' << light.param1.w << ' '
		<< light.param2.x << ' ' << light.param2.y << ' ' << light.param2.z << ' ' << light.param2.w << '\n';
}
std::istream& operator>>(std::istream &is, sLight &light) {
	//glm::vec4 position;
	//glm::vec4 diffuse;
	//glm::vec4 specular;		// rgb = highlight colour, w = power
	//glm::vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	//glm::vec4 direction;	// Spot, directional lights
	//glm::vec4 param1;		// x = lightType, y = inner angle, z = outer angle, w = TBD
	//glm::vec4 param2;		// x = 0 for off, 1 for on
	return is >> light.position.x >> light.position.y >> light.position.z >> light.position.w
		>> light.diffuse.r >> light.diffuse.g >> light.diffuse.b >> light.diffuse.a
		>> light.specular.r >> light.specular.g >> light.specular.b >> light.specular.a
		>> light.atten.x >> light.atten.y >> light.atten.z >> light.atten.w
		>> light.direction.x >> light.direction.y >> light.direction.z >> light.direction.w
		>> light.param1.x >> light.param1.y >> light.param1.z >> light.param1.w
		>> light.param2.x >> light.param2.y >> light.param2.z >> light.param2.w >> std::ws;
}
