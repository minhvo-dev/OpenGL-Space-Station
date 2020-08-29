/*
 *	File name:	"globalUtilities.hpp"
 *	Date:		7/22/2020 12:59:26 PM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Defines utilities that will be used in the project
 */

#pragma once

#ifndef _GLOBAL_UTILITIES_HPP_
#define _GLOBAL_UTILITIES_HPP_

#include "globalOpenGL.hpp"
#include "../vao_model_manager/cVAOManager.hpp"
#include "../mesh_object/cMeshObject.hpp"

#include <string>

// load models into program
void load_models_into_VAO(GLuint program);
void set_up_light_manager(GLuint program);
void set_up_mesh_objects();
void set_up_texture_manager();

// keyboard + mouse control
void error_callback(int error, const char* description);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void cursor_enter_callback(GLFWwindow* window, int entered);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

void ProcessAsyncMouse(GLFWwindow* window);
void ProcessAsyncKeys(GLFWwindow* window);


cMeshObject* find_mesh_object_by_name(std::string const &name);

// utilities for debugging
void print_selected_mesh_object_information();
void print_selected_light_information();
void print_camera_position();

// sort the transparent mesh object in the descending order
void sort_transparent_objects();

void draw_mesh_object(GLuint const program,
					  cMeshObject *const pObj,
					  glm::mat4 const &matView,
					  glm::mat4 const &matProjection);

#endif // !_GLOBAL_UTILITIES_HPP_
