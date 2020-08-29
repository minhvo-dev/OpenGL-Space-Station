/*
 *	File name:	"globalVariables.hpp"
 *	Date:		7/22/2020 11:03:55 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Contains global variables and global function declarations
 */

#pragma once

#ifndef _GLOBAL_VARIABLES_HPP_
#define _GLOBAL_VARIABLES_HPP_

#include "globalOpenGL.hpp"
#include "../light_manager/cLightManager.hpp"
#include "../shaders/cShaderManager.hpp"
#include "../mesh_object/cMeshObject.hpp"
#include "../vao_model_manager/cVAOManager.hpp"
#include "../cBasicTextureManager/cBasicTextureManager.h"
#include "../fly_camera/cFlyCamera.h"
#include "../vao_model_manager/cModelManager.hpp"

#include <glm/vec3.hpp>
#include <vector>
#include <string>

// Global Camera declaration
// ------------------------------------------------------

extern cFlyCamera *g_pFlyCamera;

// Global Light declaration
// ------------------------------------------------------
extern cLightManager *g_pLightManager;
extern std::size_t g_lightIndex;
extern cMeshObject *g_pDebugLightMeshObject;

// Global VAO declaration
// ------------------------------------------------------
extern cVAOManager *g_pVAOManager;
extern std::vector<cMeshObject*> g_vecPointerMeshObjects;
extern std::vector<cMeshObject*> g_vecPointerOpaqueMeshObjects;			// hold solid mesh object
extern std::vector<cMeshObject*> g_vecPointerTransparentMeshObjects;	// hold transparent mesh object
																		// in descending order to the camera
extern std::size_t g_meshObjectIndex;

// Global Model declaration
// ------------------------------------------------------
extern cModelManager *g_pModelManager;


// Global Shader declaration
// ------------------------------------------------------
extern cShaderManager *g_pShaderManager;

// Global Viewport declaration
// ------------------------------------------------------
extern float g_nearPlane;
extern float g_farPlane;

// Global Texture declaration
// ------------------------------------------------------
extern cBasicTextureManager *g_pTextureManager;

// Other global variables declartion
// ------------------------------------------------------
//extern char const *g_settingsFilePath;
//extern bool g_bUseHeightMap;
//extern bool g_bUseDiscardMap;
//extern bool g_bUseTransparenceMap;

#endif // !_GLOBAL_VARIABLES_HPP_
