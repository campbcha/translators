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
	// Print the error message to stderr.
	std::cerr << this->message->c_str();
}


std::string* Exception::getMessage() {
	return this->message;
}
