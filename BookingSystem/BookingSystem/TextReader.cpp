#include "TextReader.h"
#include<stdexcept>
#include<algorithm>

namespace file{

	TextReader::TextReader()
	{
	}
	TextReader::TextReader(char deliminator){
		this->deliminator = deliminator;
	}


	TextReader::~TextReader()
	{
		stream.close();
	}


	bool TextReader::openFile(const std::string &directory){
		stream.open(directory, std::ios::in);
		return stream.is_open();

	}
	bool TextReader::isOpen(){
		return stream.is_open();
	}


	bool TextReader::readBool(){
		skipSpacing();
		std::string str;
		return str.length() == 4 && (str[0] == 'T' || str[0] == 't') &&
			(str[1] == 'R' || str[1] == 'r') &&
			(str[2] == 'U' || str[2] == 'u') &&
			(str[3] == 'E' || str[3] == 'e');
	}
	char TextReader::readChar(){
		return stream.get();
	}
	int TextReader::readInt(){
		return readInt(deliminator);
	}
	int TextReader::readInt(char deliminator){
		skipSpacing();
		std::string str;
		std::getline(stream, str, deliminator);
		return parseInt(str);
	}
	float TextReader::readFloat(){
		return readFloat(deliminator);
	}
	float TextReader::readFloat(char deliminator){
		skipSpacing();
		std::string str;
		std::getline(stream, str, deliminator);
		return parseFloat(str);
	}
	double TextReader::readDouble(){
		skipSpacing();
		std::string str;
		std::getline(stream, str, deliminator);
		return parseDouble(str);
	}

	std::string TextReader::readString(){
		return readString(deliminator);
	}
	std::string TextReader::readString(char deliminator){
		skipSpacing();
		std::string str;
		std::getline(stream, str, deliminator);
		return str;
	}
	std::string TextReader::readLine(){
		std::string str;
		std::getline(stream, str);
		return str;
	}
	int TextReader::readEnum(std::string *enumNames, int arraySize){
		skipSpacing();
		std::string str;
		std::getline(stream, str, deliminator);
		//std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		for (int i = 0; i < arraySize; i++){
			int comp = str.compare(enumNames[i]);
			if (str == enumNames[i])
				return i;
		}
		return 0;
	}
	void TextReader::readDescription(){
		skipSpacing();
		std::string str;
		std::getline(stream, str, DESCRIPTIONDELIMINATOR);
	}

	void TextReader::readStringArray(std::vector<std::string> &refContainer){
		skipSpacing();
		if (stream.get() != BEGINVALUE) //Read BEGINVALUE
			throw std::exception("Reading array failed");
		skipSpacing();//Read NEWLINE + spacing
		while (stream.peek() != ENDVALUE){
			std::string str;
			std::getline(stream, str, deliminator);
			refContainer.push_back(str);
			skipSpacing();//Clears spacing after each string and makes sure we always peek at the ENDVALUE!
		}
		stream.get(); //Read the end value
	}
}