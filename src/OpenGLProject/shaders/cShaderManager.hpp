/*
 *	File name:		"cShaderManager.hpp"
 *	Source:			INFO3111
 *	Purpose:		Load the shaders and create OpenGL program
 *	Modified by:	Vo, Dinh Tue Minh
 *					C++17, refactor and clean up
 *	Date:			8/28/2020 6:15:21 PM
 */

#ifndef _C_SHADERMANAGER_HPP_
#define _C_SHADERMANAGER_HPP_

#include "../headers/globalOpenGL.hpp"

#include <string>
#include <vector>
#include <map>

class cShaderManager {
public:
	class cShader {
	public:
		cShader() : ID(0), shaderType(cShader::UNKNOWN) {};
		~cShader() = default;
		enum eShaderType {
			VERTEX_SHADER = 0,
			FRAGMENT_SHADER = 1,
			UNKNOWN = 2
		};
		eShaderType shaderType;
		std::string get_shader_type_string() const {
			static constexpr char const* name[] = { "VERTEXT_SHADER", "FRAGMENT_SHADER", "UNKNOWN_SHADER" };
			return name[shaderType];
		};

		unsigned int ID;	// or "name" from OpenGL
		std::vector<std::string> vecSource;
		std::string fileName;
	};

	cShaderManager() = default;
	~cShaderManager() = default;

	GLuint create_program_from_file(cShader &vertexShad, cShader &fragShader);

	// Clears last error
	std::string get_last_error();
private:
	// Returns an empty string if it didn't work
	bool load_source_from_file(cShader &shader);

	bool m_compileShaderFromSource(cShader &shader, std::string &error);
	// returns false if no error
	bool was_there_a_compile_error(unsigned int shaderID, std::string &errorText);
	bool was_there_a_link_error(unsigned int progID, std::string &errorText);

	std::string m_lastError;
};

#endif !_C_SHADERMANAGER_HPP_