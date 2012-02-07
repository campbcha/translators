#include "Exception.h"

Exception::Exception(const std::string message) {
	// Copy the string from the specified character array into the Exception class's message attribute.
	this->message = new std::string(message);
}


Exception::~Exception() {
	// Delete the object's string.
	delete this->message;
}


void Exception::print() {
	// Print the exception header.
	std::cerr << "***** EXCEPTION! ***************\n";
	// Print the error message to stderr.
	std::cerr << "\tMessage: " << this->message->c_str() << "\n";
}


std::string* Exception::getMessage() {
	return this->message;
}
