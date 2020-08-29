/*
 *	File name:	"cModelManager.hpp"
 *	Date:		8/27/2020 10:02:44 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Manage model paths and their friendly names
 */

#pragma once

#ifndef _C_MODEL_MANAGER_HPP_
#define _C_MODEL_MANAGER_HPP_

#include <string>
#include <map>

class cModelManager {
public:
	~cModelManager() = default;
	cModelManager() = default;

	// Add new model into model manager
	// modelPath: path of the model to be loaded
	// name: name of the model to retrieve later
	bool add_model(std::string const &modelPath, std::string const &name);

	// Find the model by its name
	std::string find_model_by_name(std::string const &name);

	// Get the manager
	std::map<std::string, std::string> const& get_manager() const { return mgr_; }

private:
	// Model Manager
	// key: model name
	// value: model file path
	std::map<std::string, std::string> mgr_;
};

#endif // !_C_MODEL_MANAGER_HPP_
