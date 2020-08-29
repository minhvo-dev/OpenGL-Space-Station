/*
 *	File name:	"myUtilities.cpp"
 *	Date:		7/22/2020 1:02:31 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Implement the globalUtilities.hpp header
 */

#include "../headers/globalUtilities.hpp"

#include "../headers/globalOpenGL.hpp"
#include "../headers/globalVariables.hpp"
#include "../mesh_object/cMeshObject.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>

void print_selected_mesh_object_information() {
	cMeshObject *cur = g_vecPointerMeshObjects[g_meshObjectIndex];
	std::cout << "Mesh Object [" << g_meshObjectIndex << "]: " << cur->friendlyName << '\n'
		<< "- pos:\t\t" << cur->pos.x << '\t' << cur->pos.y << '\t' << cur->pos.z << '\n'
		<< "- orient:\t" << cur->orientation.x << '\t' << cur->orientation.y << '\t' << cur->orientation.z << '\n'
		<< "- scale:\t" << cur->scale << '\n';
}

void print_selected_light_information() {
	//glm::vec4 position;
	//glm::vec4 diffuse;
	//glm::vec4 specular;		// rgb = highlight colour, w = power
	//glm::vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	//glm::vec4 direction;	// Spot, directional lights
	//glm::vec4 param1;		// x = lightType, y = inner angle, z = outer angle, w = TBD
	//glm::vec4 param2;		// x = 0 for off, 1 for on
	sLight &cur = g_pLightManager->vecLights[g_lightIndex];
	std::cout << "Light [" << g_lightIndex << "]\n"
		<< "- pos:\t\t" << cur.position.x << '\t' << cur.position.y << '\t' << cur.position.z << '\n'
		<< "- diffuse:\t" << cur.diffuse.r << '\t' << cur.diffuse.g << '\t' << cur.diffuse.b << '\n'
		<< "- atten:\t" << cur.atten.x << '\t' << cur.atten.y << '\t' << cur.atten.z << '\t' << cur.atten.w << '\n'
		<< "- type:\t\t" << cur.param1.x << '\n'
		<< "- isOn:\t\t" << (cur.is_on() ? "true" : "false") << '\n';
}

void print_camera_position() {
	// Print out camera position:
	std::cout << "Camera:\n"
		<< "\tPos:\t"
		<< ::g_pFlyCamera->getEye().x << '\t'
		<< ::g_pFlyCamera->getEye().y << '\t'
		<< ::g_pFlyCamera->getEye().z << '\n'
		<< "\tAt:\t"
		<< ::g_pFlyCamera->getAt().x << '\t'
		<< ::g_pFlyCamera->getAt().y << '\t'
		<< ::g_pFlyCamera->getAt().z << '\n';
}

void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}


//bool save_settings_to_file(std::string const &fileName) {
//	std::ofstream outFile(fileName);
//	if (outFile) {
//		// save the mesh object settings
//		outFile << g_vecPointerMeshObjects.size() << '\n';
//		for (cMeshObject const *ptr : g_vecPointerMeshObjects) {
//			outFile << *ptr;
//		}
//		// save the light
//		outFile << g_pLightManager->NUMBEROFLIGHTS << '\n';
//		for (std::size_t i = 0; i != g_pLightManager->NUMBEROFLIGHTS; ++i) {
//			outFile << g_pLightManager->vecLights[i];
//		}
//		outFile.close();
//		return true;
//	}
//	return false;
//}
//
//bool load_settings_from_file(std::string const &fileName) {
//	std::ifstream inFile(fileName);
//	if (inFile) {
//		// load mesh objects
//		std::size_t nObjects = 0;
//		inFile >> nObjects >> std::ws;
//		for(std::size_t i = 0; i < nObjects; ++i) {
//			inFile >> *g_vecPointerMeshObjects[i];
//		}
//
//		// load lights
//		std::size_t nLights = 0;
//		inFile >> nLights;
//		for (std::size_t i = 0; i < nLights; ++i) {
//			inFile >> g_pLightManager->vecLights[i];
//		}
//
//		inFile.close();
//		return true;
//	}
//	return false;
//}


// Find a mesh object by friendly name
// return nullptr if cannot found
cMeshObject* find_mesh_object_by_name(std::string const &name) {
	for (cMeshObject * const pObj : ::g_vecPointerMeshObjects) {
		if (pObj->friendlyName == name) {
			return pObj;
		}
	}
	return nullptr;
}

void sort_transparent_objects() {
	using pfc = std::pair<float, cMeshObject*>;
	const std::size_t N_OBJS = ::g_vecPointerTransparentMeshObjects.size();
	std::vector<pfc> order;
	order.reserve(::g_vecPointerTransparentMeshObjects.size());
	
	for (cMeshObject *cur : ::g_vecPointerTransparentMeshObjects) {
		float distance = glm::distance(cur->pos, ::g_pFlyCamera->getEye());
		order.push_back(std::make_pair(distance, cur));
	}

	// sort in descending order
	std::sort(order.begin(), order.end(), [](pfc const &a, pfc const &b) {
		return a.first > b.first;
	});
	std::vector<cMeshObject *> tmp;
	tmp.reserve(::g_vecPointerTransparentMeshObjects.size());
	for (pfc const &p : order) {
		tmp.push_back(p.second);
	}

	::g_vecPointerTransparentMeshObjects = tmp;
}