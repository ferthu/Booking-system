#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>


namespace file{

	/* IO file writer able to write text documents layed out with specific line splits and separation characters.
	Provides functions to write different types of variables to the stream.
	Functions are paired with the reader object, TextReader, which holds the respective functions for reading the lines.
	The two objects is used by creating a read & write functions for each element that is parsed to a text file.
	*/
	class TextWriter
	{
	private:
		std::ofstream stream;
		char deliminator = ',';
		char BEGINVALUE = '<';
		char ENDVALUE = '>';
		char DESCRIPTIONDELIMINATOR = ':';

	public:
		TextWriter();
		TextWriter(char deliminator);
		~TextWriter();

		/* Opens a file directory. Truncates existing file or creates a new file if it does not exist.
		return	>>	If a stream was succesfully opened
		*/
		bool openFile(const std::string &directory);
		/* Verify that a stream is open
		return	>>	If a stream is succesfully opened
		*/
		bool isOpen();
		/* Close the current opened stream. Ending writing to the stream.
		*/
		void close();

		/*Writes a end line character to the stream*/
		void endLine();

		/*Write a boolean and a deliminator + space to the stream*/
		void writeBool(const bool value);
		/*Write a boolean + a newline to the stream*/
		void writeBoolE(const bool value);

		/*Write a character value  and a deliminator + space to the stream*/
		void writeChar(const char value);
		/*Write a character + a newline to the stream*/
		void writeCharE(const char value);

		/*Write a integer value  and a deliminator + space to the stream*/
		void writeInt(const int value);
		/*Write a integer + a newline to the stream*/
		void writeIntE(const int value);
		/*Writes two integers to the stream*/
		void writePoint(const int X, const int Y);

		/*Write a float value and a deliminator + space to the stream*/
		void writeFloat(const float value);
		/*Write a float + a newline to the stream*/
		void writeFloatE(const float value);

		/*Write a double value and a deliminator + space to the stream*/
		void writeDouble(const double value);
		/*Write a double + a newline to the stream*/
		void writeDoubleE(const double value);


		/*Write a string value and a deliminator + space to the stream*/
		void writeString(const std::string &str);
		/*Write a string + a newline to the stream*/
		void writeStringE(const std::string &str);
		/*Writes a enum to the stream*/
		void writeEnum(const int value, std::string *enumNames);

		/*Writes a variable description to the stream*/
		void writeDescription(const std::string &str);
		/*Writes the string array to the stream*/
		void writeStringArray(std::string *arrayPtr, int size);

		/*Writes an array*/
		template <class Element, class Iterator>
		void writeArray(Iterator begin, Iterator end, void(*writeFunc)(TextWriter &writer, Element &value));
	};


	template <class Element, class Iterator>
	void TextWriter::writeArray(Iterator begin, Iterator end, void(*writeFunc)(TextWriter &writer, Element &value)){

		stream << BEGINVALUE;
		for (Iterator it = begin; it != end; it++)
			writeFunc(*this, *it);
		stream << ENDVALUE;
	}
}

