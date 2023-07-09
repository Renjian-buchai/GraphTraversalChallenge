#pragma once

#include <string>
#include <vector>

//converts between:
//-string ("a, bz")
//-vector of strings ("a", "bz")
//-vector of ints (0, 79)

//this assumes 0-index for ints, but not for textual names.


std::vector<std::string>	convert_path_STR_TO_STRVEC	(std::string			path);
std::vector<int>		convert_path_STR_TO_INTVEC	(std::string			path);

std::string			convert_path_STRVEC_TO_STR	(std::vector<std::string>	path);
std::vector<int>		convert_path_STRVEC_TO_INTVEC	(std::vector<std::string>	path);

std::string			convert_path_INTVEC_TO_STR	(std::vector<int>		path);
std::vector<std::string>	convert_path_INTVEC_TO_STRVEC	(std::vector<int>		path);
