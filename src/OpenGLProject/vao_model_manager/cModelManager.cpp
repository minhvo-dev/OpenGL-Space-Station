/*
 *	File name:	"cModelManager.cpp"
 *	Date:		8/27/2020 10:09:07 AM
 *	Author:		Vo, Dinh Tue Minh
 *	Purpose:	Implement the cModelManager class
 */

#include "cModelManager.hpp"

#include <string>

bool cModelManager::add_model(std::string const &modelPath, std::string const &name) {
	if (mgr_.find(name) == mgr_.end()) { // model does not already exist in the manager
		mgr_[name] = modelPath;
		return true;
	}
	return false; // model already exists in the manager
}

std::string cModelManager::find_model_by_name(std::string const &name) {
	if (auto it = mgr_.find(name); it == mgr_.end()) {
		return "";
	}
	else {
		return mgr_[name];
	}
}