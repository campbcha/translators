#include "Exception.h"

Exception::Exception(const std::string message) {
	// Copy the string from the specified character array into the Exception class's message attribute.
	this->message = new std::string(message);

	// Set function to NULL.
	this->function = NULL;
}


Exception::Exception(const std::string message, const std::string function) {
	// Copy the message parameter.
	this->message = new std::string(message);

	// Copy the function parameter.
	this->function = new std::string(function);
}


Exception::~Exception() {
	// Delete the object's message.
	delete this->message;

	// Delete the object's function if applicable.
	if ( this->function != NULL ) {
		delete this->function;
	}
}


void Exception::print() {
	// Print the exception header.
	std::cerr << "***** EXCEPTION! ***************\n";

	// Print the error message to stderr.
	std::cerr << "\tMessage: " << this->message->c_str() << "\n";

	// Print the function to stderr if applicable.
	if ( function != NULL ) {
		std::cerr << "\tFunction Name: " << this->function->c_str() << "\n";
	}
}


std::string* Exception::getMessage() {
	return this->message;
}
