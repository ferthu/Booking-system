#pragma once

#include<string>
#include<vector>


namespace file{


	const char SPACE = ' ';
	const char STRINGEND = '\0';
	const char NEWLINE = '\n';
	const char FORWARDSLASH = '/';
	const char BACKSLASH = '\\';

	/*Splits a string into parts where each sequences is sepparated by the deliminator
	s		<<	string that will be split
	delim	<<	deliminator that sepparates each sequence
	elems	>>	string vector each sequence will be pushed into, deliminators will be excluded*/
	void string_split(const std::string &s, char delim, std::vector<std::string> &elems);
	/* Splits a full filepath string into a directory path and a filename
	s			<<	The full filepath string
	directory	>>	A reference that will be assigned the directory string
	fileName	>>	A reference that will be assigned the file name string
	*/
	void directory_split(const std::string &s, std::string &directory, std::string &fileName);
	/*Tries to read a integer value from the string, failure will return 0*/
	int parseInt(std::string &str);
	/*Tries to read a float value from the string, failure will return 0.0f*/
	float parseFloat(std::string &str);
	/*Tries to read a double value from the string, failure will return 0.0*/
	double parseDouble(std::string &str);


	/*	Convert a vector of strings to a single string
	string_vector	<<	String vector that will be converted
	return			>>	String containing all the strings from the vector with a endline after each string.
	*/
	std::string convertToString(std::vector<std::string> &string_vector);


}