#include "TextWriter.h"
#include"StringFunction.h"

namespace file{

	TextWriter::TextWriter()
	{
	}
	TextWriter::TextWriter(char deliminator)
	{
		this->deliminator = deliminator;
	}


	TextWriter::~TextWriter()
	{
		stream.close();
	}

	bool TextWriter::openFile(const std::string &directory){
		stream.open(directory, std::ios::out | std::ios::trunc);
		return stream.is_open();
	}
	bool TextWriter::isOpen(){
		return stream.is_open();
	}


	void TextWriter::endLine(){
		stream << NEWLINE;
	}

	void TextWriter::writeBool(const bool value){
		std::string str = value ? "True" : "False";
		stream << str;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeBoolE(const bool value){
		std::string str = value ? "True" : "False";
		stream << str;
		stream << deliminator << NEWLINE;
	}

	void TextWriter::writeChar(const char value){
		stream << value;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeCharE(const char value){
		stream << value;
		stream << deliminator << NEWLINE;
	}

	void TextWriter::writeInt(const int value){
		stream << value;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeIntE(const int value){
		stream << value;
		stream << deliminator << NEWLINE;
	}
	void TextWriter::writePoint(const int X, const int Y){
		stream << BEGINVALUE << X << deliminator << SPACE << Y << ENDVALUE;
	}

	void TextWriter::writeFloat(const float value){
		stream << value;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeFloatE(const float value){
		stream << value;
		stream << deliminator << NEWLINE;
	}

	void TextWriter::writeDouble(const double value){
		stream << value;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeDoubleE(const double value){
		stream << value;
		stream << deliminator << NEWLINE;
	}

	void TextWriter::writeString(const std::string &value){
		stream << value;
		stream << deliminator << SPACE;
	}
	void TextWriter::writeStringE(const std::string &value){
		stream << value;
		stream << deliminator << NEWLINE;
	}
	void TextWriter::writeEnum(const int value, std::string *enumNames){
		stream << enumNames[value];
		stream << deliminator << SPACE;
	}

	void TextWriter::writeDescription(const std::string &str){
		stream << str;
		stream << DESCRIPTIONDELIMINATOR << SPACE;
	}

	/*Writes the string array to the stream*/
	void TextWriter::writeStringArray(std::string *arrayPtr, int size){
		stream << BEGINVALUE;
		for (int i = 0; i < size; i++)
			stream << arrayPtr[i] << deliminator << SPACE;
		stream << ENDVALUE;
	}
}