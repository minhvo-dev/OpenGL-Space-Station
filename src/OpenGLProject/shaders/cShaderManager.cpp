/*
 *	File name:		"cShaderManager.cpp"
 *	Source:			INFO3111
 *	Purpose:		Implements the cShaderManager ADT
 *	Modified by:	Vo, Dinh Tue Minh
 *					C++17, refactor and clean up
 *	Date:			8/28/2020 6:15:21 PM
 */

#include "cShaderManager.hpp"

//#include <glad/glad.h>	// For all the OpenGL calls, etc.
#include "../headers/globalOpenGL.hpp"

#include <fstream>
#include <vector>
#include <string>
#include <string.h> // memcpy

// return true if load successfully, false otherwise
bool cShaderManager::load_source_from_file(cShader &shader) {
	std::ifstream file(shader.fileName);
	if (!file) {
		return false;
	}

	shader.vecSource.clear();
	std::string line;
	while (std::getline(file, line)) {
		line += "\n\0";	// match the requirement of a c-style string that later will be compiled by OpenGL
		shader.vecSource.push_back(line);
	}

	file.close();
	return true;		// Return the string (from the sstream)
}

// Returns empty string if no error
// returns false if no error
bool cShaderManager::was_there_a_compile_error(unsigned int shaderID, std::string &errorText) {
	GLint success = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength); // get error log length from OpenGL
		char* pLogText = new char[maxLength];
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, pLogText); // get the actual error log
		errorText = pLogText;
		this->m_lastError += "\n" + errorText;

		delete[] pLogText;
	}
	return success == GL_FALSE;
}

bool cShaderManager::was_there_a_link_error(unsigned int programID, std::string &errorText) {
	GLint success = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (success == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength); // get error log length from OpenGL
		char* pLogText = new char[maxLength];
		glGetProgramInfoLog(programID, maxLength, &maxLength, pLogText); // get the actual error log
		errorText = pLogText;
		this->m_lastError += "\n" + errorText;

		// clean up
		delete[] pLogText;
	}

	return success == GL_FALSE;
}


std::string cShaderManager::get_last_error() {
	std::string lastErrorTemp = this->m_lastError;
	this->m_lastError = "";
	return lastErrorTemp;
}

#include <iostream>

bool cShaderManager::m_compileShaderFromSource(cShaderManager::cShader &shader, std::string &error) {
	// copy data from shader to array of char * to match the requirement of OpenGL
	unsigned int numberOfLines = static_cast<unsigned int>(shader.vecSource.size());
	char const** arraySource = new char const*[numberOfLines];

	for (unsigned int indexLine = 0; indexLine != numberOfLines; ++indexLine) {
		// use source from shader instead of allocating new memory
		arraySource[indexLine] = shader.vecSource[indexLine].c_str();
	}

	glShaderSource(shader.ID, numberOfLines, arraySource, NULL);
	glCompileShader(shader.ID);

	delete[] arraySource;

	// Did it work? 
	std::string errorText = "";
	if (this->was_there_a_compile_error(shader.ID, errorText)) {
		error = shader.get_shader_type_string() + " compile error: " + errorText;
		return false;
	}

	return true;
}


GLuint cShaderManager::create_program_from_file(cShader &vertexShad, cShader &fragShader) {
	std::string errorText;

	// Shader loading happening before vertex buffer array
	vertexShad.ID = glCreateShader(GL_VERTEX_SHADER);
	vertexShad.shaderType = cShader::VERTEX_SHADER;
	if (!this->load_source_from_file(vertexShad)) {
		return 0;
	}

	errorText = "";
	if (!this->m_compileShaderFromSource(vertexShad, errorText)) {
		this->m_lastError = errorText;
		return 0;
	}

	fragShader.ID = glCreateShader(GL_FRAGMENT_SHADER);
	fragShader.shaderType = cShader::FRAGMENT_SHADER;
	if (!this->load_source_from_file(fragShader)) {
		return 0;
	}

	if (!this->m_compileShaderFromSource(fragShader, errorText)) {
		this->m_lastError = errorText;
		return 0;
	}

	GLuint programID = glCreateProgram(); // ask OpenGL to create a program

	glAttachShader(programID, vertexShad.ID);
	glAttachShader(programID, fragShader.ID);
	glLinkProgram(programID);

	// Was there a link error? 
	errorText = "";
	if (this->was_there_a_link_error(programID, errorText)) {
		this->m_lastError = "Shader program link error: " + errorText;
		return 0;
	}

	// return the program ID that OpenGL gave
	return programID;
}
