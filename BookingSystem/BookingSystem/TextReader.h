#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include"StringFunction.h"
#include<vector>

namespace file{


	/* IO file reader able to read text documents layed out with specific line splits and separation characters.
	Provides functions to read different types of variables from the stream.
	Functions are paired with the reader object, TextReader, which holds the respective functions for reading the lines.
	The two objects is used by creating a read & write functions for each element that is parsed to a text file.
	*/
	class TextReader
	{
	private:
		char deliminator = ',';
		char BEGINVALUE = '<';
		char ENDVALUE = '>';
		char DESCRIPTIONDELIMINATOR = ':';




	protected:

		std::ifstream stream;

		/*Peeks the stream for spaces or newlines and skips them*/
		inline void skipSpacing(){
			while (stream.peek() == SPACE || stream.peek() == NEWLINE)
				stream.get();
		}

	public:
		TextReader();
		TextReader(char deliminator);
		~TextReader();

		/*Opens the file at the directory*/
		bool openFile(const std::string &directory);
		/*Returns if a stream is opened*/
		bool isOpen();

		/*Read a boolean value from the text document*/
		bool readBool();
		/*Read a character value from the text document*/
		char readChar();
		/*Read a integer value from the text document*/
		int readInt();
		/*Read a integer value from the text document
		deliminator	<<	The character read to*/
		int readInt(char deliminator);

		/*Read a float value from the text document*/
		float readFloat();
		/*Read a float value from the text document*/
		float readFloat(char deliminator);
		/*Read a double value from the text document*/
		double readDouble();
		/*Read a string from the text document*/
		std::string readString();
		/*Read a string from the text document*/
		std::string readString(char deliminator);
		/*Read the rest of the current line*/
		std::string readLine();
		/*Read a enum string from the text document*/
		int readEnum(std::string *enumNames, int arraySize);
		/*Read a description parameter in the text document*/
		void readDescription();

		/*Reads a string array from the stream*/
		void readStringArray(std::vector<std::string> &refContainer);

		template <class Element>
		void readArray(std::vector<Element> &refContainer, void(*readFunc)(TextReader &reader, std::vector<Element> &vector));
	};


	template <class Element>
	void TextReader::readArray(std::vector<Element> &refContainer, void(*readFunc)(TextReader &reader, std::vector<Element> &vector)){
		skipSpacing();
		if (stream.get() != BEGINVALUE) //Read BEGINVALUE
			throw std::exception("Reading array failed");
		skipSpacing();//Read NEWLINE + spacing
		while (stream.peek() != ENDVALUE){
			readFunc(*this, refContainer);
			skipSpacing();//We need to do this to make sure we always peek at the ENDVALUE (incase last read func did not do this!)
		}
		stream.get(); //Read the end value
	}

}
