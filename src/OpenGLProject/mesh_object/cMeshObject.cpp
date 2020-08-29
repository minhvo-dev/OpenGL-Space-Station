/*
 *	File name:	"cMeshObject.cpp"
 *	Date:		7/10/2020 4:23:03 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Implement the cMeshObject header file
 */

#include "cMeshObject.hpp"
#include <sstream>

cMeshObject::cMeshObject()
	: pos(0.0f, 0.0f, 0.0f),
	//colourRGBA(1.0f, 1.0f, 1.0f, 1.0f),
	diffuseRGBA(1.0f, 1.0f, 1.0f, 1.0f),
	specularRGB_Power(1.0f, 1.0f, 1.0f, 1.0f),
	orientation(0.0f, 0.0f, 0.0f),
	scale(1.0f),
	isWireframe(false),
	isVisible(true), // true = draw it, false = does not draw it
	friendlyName("UNASSIGNED"){
	for (unsigned int i = 0; i < NUMBEROFTEXTURES; ++i) {
		textureRatios[i] = 0.0f;
	}

}
//
//std::istream& operator>>(std::istream &is, cMeshObject &cMeshObj) {
//	//std::string meshName;
//	//glm::vec3 pos;			// 0,0,0 (origin)
//	//glm::vec4 colourRGBA;	// 0,0,0,1 (black)
//	//glm::vec3 orientation;	// rotation xyz
//	//float scale;			// 1.0f
//	//bool isWireframe;		// false
//
//	//bool isVisible;
//	//std::string friendlyName;
//	cMeshObject obj;
//	std::getline(is, obj.meshName);
//	std::getline(is, obj.friendlyName);
//
//	int isWireFrame = 0; // false
//	int isVisible = 0; // false
//	is >> obj.pos.x >> obj.pos.y >> obj.pos.z // read the position x,y,z
//		>> obj.diffuseRGBA.r >> obj.diffuseRGBA.g >> obj.diffuseRGBA.b >> obj.diffuseRGBA.a // read the diffuse colour RGBA
//		>> obj.specularRGB_Power.r >> obj.specularRGB_Power.g >> obj.specularRGB_Power.b >> obj.specularRGB_Power.w // read the specular color + power
//		>> obj.orientation.x >> obj.orientation.y >> obj.orientation.z // read the orientation x,y,z
//		>> obj.scale // read the scale
//		>> isWireFrame
//		>> isVisible >> std::ws;
//	obj.isWireframe = (isWireFrame != 0);
//	obj.isVisible = (isVisible != 0);
//	
//	if (obj.meshName == cMeshObj.meshName) {
//		cMeshObj = obj;
//	}
//	else {
//		std::cout << "Mismatch: " << obj.meshName << '\n';
//	}
//	return is;
//}

std::ostream& operator<<(std::ostream &os, cMeshObject const &obj) {
	return os << obj.meshName << '\n' // write the name
		<< obj.friendlyName << '\n'
		<< obj.pos.x << ' ' << obj.pos.y << ' ' << obj.pos.z << ' ' // write the position x,y,z
		<< obj.diffuseRGBA.r << ' ' << obj.diffuseRGBA.g << ' ' << obj.diffuseRGBA.b << ' ' << obj.diffuseRGBA.a << ' ' // write the diffuse colour RGBA
		<< obj.specularRGB_Power.r << ' ' << obj.specularRGB_Power.g << ' ' << obj.specularRGB_Power.b << ' ' << obj.specularRGB_Power.a << ' ' // write the specular colour + power
		<< obj.orientation.x << ' ' << obj.orientation.y << ' ' << obj.orientation.z << ' ' // write the orientation x,y,z
		<< obj.scale << ' ' // write the scale
		<< (obj.isWireframe ? 1 : 0) << ' '
		<< (obj.isVisible ? 1 : 0) << '\n';
}