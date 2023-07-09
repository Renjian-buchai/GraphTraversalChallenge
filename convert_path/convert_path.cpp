#include "convert_path.hpp"

//converts between:
//-string ("a, bz")
//-vector of strings ("a", "bz")
//-vector of ints (0, 79)

//this assumes 0-index for ints, but not for textual names.


std::vector<std::string> convert_path_STR_TO_STRVEC(std::string path) {
	for(int i = 0; i < path.size(); i++) {path[i] = tolower(path[i]);}

	std::vector<std::string> toReturn = {};
	std::string toAdd = "";
	while(!path.empty()) {
		if(path[0] >= 'a' && path[0] <= 'z') {
			toAdd += path[0];
		} else if(!toAdd.empty()) {
			toReturn.push_back(toAdd); toAdd.clear();
		}
	}
	return toReturn;
}


std::vector<int> convert_path_STR_TO_INTVEC(std::string path) {
	return convert_path_STRVEC_TO_INTVEC(convert_path_STR_TO_STRVEC(path));
}


std::string convert_path_STRVEC_TO_STR(std::vector<std::string> path) {
	std::string toReturn = "";

	for(int i = 0; i < path.size(); i++) {
		toReturn += path[i];
		toReturn += ", ";
	}
	if(toReturn.size() >= 2) {toReturn.pop_back(); toReturn.pop_back();}
	return toReturn;
}

std::vector<int> convert_path_STRVEC_TO_INTVEC(std::vector<std::string> path) {
	std::vector<int> toReturn = {};

	for(int i = 0; i < path.size(); i++) {
		int result = 0;
		for(int j = 0; j < path[i].size(); j++) {
			result = result * 26 + (tolower(path[i][j]) - 'a' + 1);
		}
		result--; //0-indexing
		toReturn.push_back(result);
	}
	return toReturn;
}

std::string convert_path_INTVEC_TO_STR(std::vector<int> path) {
	std::string toReturn = "";

	for(int i = 0; i < path.size(); i++) {
		std::string result = "";
		while(path[i] > 0) {
			result = char('a' + (path[i]-1) % 26) + result;
			path[i] = (path[i]-1) / 26;
		}
		toReturn += result;
		toReturn += ", ";
	}
	if(toReturn.size() >= 2) {toReturn.pop_back(); toReturn.pop_back();}
	return toReturn;
}

std::vector<std::string> convert_path_INTVEC_TO_STRVEC(std::vector<int> path) {
	std::vector<std::string> toReturn = {};

	for(int i = 0; i < path.size(); i++) {
		std::string toAdd = "";
		while(path[i] > 0) {
			toAdd = char('a' + (path[i]-1) %26) + toAdd;
			path[i] = (path[i]-1) / 26;
		}
		toReturn.push_back(toAdd);
	}
	return toReturn;
}

