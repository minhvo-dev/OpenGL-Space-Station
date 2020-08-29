/*
 *	File name:	"main.cpp"
 *	Date:		6/29/2020 3:23:24 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Driver to open the OpenGL window
 */

 //#include <glad/glad.h>
 //#include <GLFW/glfw3.h>

#include "headers/globalOpenGL.hpp"
#include "headers/globalVariables.hpp"

//#include "cShaderManager.h"
#include "shaders/cShaderManager.hpp"
#include "vao_model_manager/cVAOManager.hpp"
#include "mesh_object/cMeshObject.hpp"
#include "light_manager/cLightManager.hpp"

#include "vao_model_manager/cModelManager.hpp"

#include "headers/globalUtilities.hpp"

#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <iostream>
#include <string>
#include <vector>
#include <map>

/* Camera settings */
cFlyCamera *g_pFlyCamera = nullptr;

/* Lights settings */

cLightManager *g_pLightManager = nullptr;
cMeshObject *g_pDebugLightMeshObject = nullptr;
std::size_t g_lightIndex = 0;

/* Global variables */
cShaderManager *g_pShaderManager = nullptr;
cVAOManager *g_pVAOManager = nullptr;
cModelManager *g_pModelManager = nullptr;

/* Models */
std::vector<cMeshObject*> g_vecPointerMeshObjects;
std::vector<cMeshObject*> g_vecPointerOpaqueMeshObjects; // hold solid mesh object
std::vector<cMeshObject*> g_vecPointerTransparentMeshObjects;	// hold transparent mess object
																// in descending order to the camera
std::size_t g_meshObjectIndex = 0;

/* Texture */
cBasicTextureManager *g_pTextureManager = nullptr;

// Window settings
constexpr unsigned int WINDOW_WIDTH = 1080;
constexpr unsigned int WINDOW_HEIGHT = 720;
constexpr char PROGRAM_TITLE[] = "Minh Space Station";

// View port setting
float g_nearPlane = 0.1f;
float g_farPlane = 1000.0f;


int main(void) {
	
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, PROGRAM_TITLE, NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorEnterCallback(window, cursor_enter_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

	g_pShaderManager = new cShaderManager();

	cShaderManager::cShader vertexShader;
	cShaderManager::cShader fragmentShader;

	vertexShader.fileName = "./shaders/simpleVertexShader.glsl";
	fragmentShader.fileName = "./shaders/simpleFragmentShader.glsl";
	GLuint program = g_pShaderManager->create_program_from_file(vertexShader, fragmentShader);

	if (program == 0) {
		// there were problems
		std::cout << "ERROR: " << g_pShaderManager->get_last_error() << '\n';

		// clean up and exit
		delete g_pShaderManager;
		exit(EXIT_FAILURE);
	}

	// ***************************************************
	// STARTOF: Set up the Fly Camera
	// ***************************************************

	::g_pFlyCamera = new cFlyCamera();
	::g_pFlyCamera->setEye(glm::vec3(-2.5f, 2.5f, -15.0f));
	::g_pFlyCamera->movementSpeed = 0.25f;

	// ***************************************************
	// ENDOF: Set up the Fly Camera
	// ***************************************************

	// ***************************************************
	// STARTOF: Loading the models/lightball
	// ***************************************************
	
	load_models_into_VAO(program);

	// ***************************************************
	// ENDOF: Loading the models
	// ***************************************************

	// ***************************************************
	// STARTOF: Set the light manager
	// ***************************************************
	
	set_up_light_manager(program);

	// ***************************************************
	// ENDOF: Set the light manager
	// ***************************************************
	
	// ***************************************************
	// STARTOF: Set up texture manager
	// ***************************************************
	
	set_up_texture_manager();
	
	// ***************************************************
	// ENDOF: Set the texture manager
	// ***************************************************

	// ***************************************************
	// STARTOF: Set up mesh objects
	// ***************************************************
	
	set_up_mesh_objects();

	// categorize transparent vs opaque objects
	for (cMeshObject *pObj : ::g_vecPointerMeshObjects) {
		if (pObj->diffuseRGBA.a < 1.0f) {
			::g_vecPointerTransparentMeshObjects.push_back(pObj);
		}
		else {
			::g_vecPointerOpaqueMeshObjects.push_back(pObj);
		}
	}

	// sort the transparent objects for the first time
	sort_transparent_objects();

	// ***************************************************
	// ENDOF: Set up mesh objects
	// ***************************************************

	// Get eyeLocation from the fragment shader
	GLint eyeLocation_UniLoc = glGetUniformLocation(program, "eyeLocation");

	while (!glfwWindowShouldClose(window)) {
		float ratio;
		int width, height;

		glm::mat4 matView; // used to be 'v'
		glm::mat4 matProjection; // used to be 'p'
		// glm::mat4 mvp; // most valuable player (model view projection)


		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);

		// view frustum
		matProjection = glm::perspective(0.6f,
										 ratio,
										 ::g_nearPlane, // near plane
										 ::g_farPlane); // far plane

		matView = glm::mat4(1.0f);

		matView = glm::lookAt(::g_pFlyCamera->getEye(),
							  ::g_pFlyCamera->getAt(),
							  ::g_pFlyCamera->getUp());

		// copy the eye to the shader
		glUniform4f(eyeLocation_UniLoc,
					::g_pFlyCamera->getEye().x,
					::g_pFlyCamera->getEye().y,
					::g_pFlyCamera->getEye().z,
					1.0f);

		// ***************************************************
		// STARTOF: Draws the entire screne 
		// ***************************************************		

		// Draw NON-TRANSPARENT objects first
		for (cMeshObject* const pSolidObj : ::g_vecPointerOpaqueMeshObjects) {
			draw_mesh_object(program, pSolidObj, matView, matProjection);
		}

		// Draw TRANSPARENT objects from farest to nearest to the camera
		
		for (cMeshObject* const pTransparentObj : ::g_vecPointerTransparentMeshObjects) {
			draw_mesh_object(program, pTransparentObj, matView, matProjection);
		}

		// ***************************************************
		// ENDOF: Draws scene
		// ***************************************************

		// ***************************************************
		// STARTOF: Set the lighting for the "scene" 
		// ***************************************************

		::g_pLightManager->copy_light_calues_to_shader();
		// Flick the engine lights on the X-Wing
		for (unsigned i = 0; i < 4; ++i) {
			::g_pLightManager->vecLights[i].atten.x = 0.0f;			// Constant
			::g_pLightManager->vecLights[i].atten.y = 0.01f;		// Linear
			::g_pLightManager->vecLights[i].atten.z = 0.003f;		// Quadratic
			float r = (static_cast<float>(rand()) / RAND_MAX);
			r /= 10.0f;
			
			g_pLightManager->vecLights[i].atten.y += r;
		}

		// Draw the debug light
		if (g_pDebugLightMeshObject->isVisible) {
			for (std::size_t i = 0; i < ::g_pLightManager->NUMBEROFLIGHTS; ++i) {
				sLight const &curLight = ::g_pLightManager->vecLights[i];
				if (curLight.is_on()) {
					g_pDebugLightMeshObject->pos = curLight.position;
					draw_mesh_object(program, g_pDebugLightMeshObject, matView, matProjection);
				}
			}
		}

		// ***************************************************
		// ENDOF: Set the lighting for the "scene" 
		// ***************************************************

		ProcessAsyncKeys(window);
		ProcessAsyncMouse(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// clean up
	delete g_pFlyCamera;
	delete g_pLightManager;
	delete g_pDebugLightMeshObject;
	delete g_pVAOManager;
	for (cMeshObject *pCurMesh : ::g_vecPointerMeshObjects) {
		delete pCurMesh;
	}
	delete g_pModelManager;
	delete g_pShaderManager;
	delete g_pTextureManager;

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
