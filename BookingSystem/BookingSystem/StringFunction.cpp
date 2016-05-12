#include"StringFunction.h"
#include<sstream>

namespace file{

	void string_split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
	}
	/* Splits a full filepath string into a directory path and a filename
	s			<<	The full filepath string
	directory	>>	A reference that will be assigned the directory string
	fileName	>>	A reference that will be assigned the file name string
	*/
	void directory_split(const std::string &s, std::string &directory, std::string &fileName) {

		int filenameIndex = 0;
		for (int i = s.size() - 1; i >= 0; i--){
			if (s[i] == FORWARDSLASH || s[i] == BACKSLASH){
				//We found the first path splitter. Set the index to the first char of the filename (+ 1 since directory should have the filename splitter)
				filenameIndex = i + 1;
				break;
			}
		}
		//If the string ends with a path separator fileName will be empty (and crash the program!)
		if (filenameIndex == s.size()){
			directory = s;
			return;
		}

		//We split the string with directory keeping
		directory = std::string(&s[0], filenameIndex);
		fileName = std::string(&s[filenameIndex], s.size() - filenameIndex);
	}

	/*	Convert a vector of strings to a single string
	string_vector	<<	String vector that will be converted
	return			>>	String containing all the strings from the vector with a endline after each string.
	*/
	std::string convertToString(std::vector<std::string> &string_vector){
		std::string value;
		for (unsigned int i = 0; i < string_vector.size(); i++){
			value += string_vector[i];
			value += i < string_vector.size() - 1 ? ", " : "\n";
		}
		return value;
	}

	int parseInt(std::string &str){
		try{
			return std::stoi(str.c_str());
		}
		catch (int i){
			(void)i;
			return 0;
		}
	}
	float parseFloat(std::string &str){
		try{
			return std::stof(str.c_str());
		}
		catch (int i){
			(void)i;
			return 0.0f;
		}
	}
	double parseDouble(std::string &str){
		try{
			return std::stod(str.c_str());
		}
		catch (int i){
			(void)i;
			return 0.0;
		}
	}

}