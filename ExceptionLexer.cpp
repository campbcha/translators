#include "ExceptionLexer.h"


ExceptionLexer::ExceptionLexer(const std::string message, int lineNumber) : Exception(message),lineNumber(lineNumber) {
	; // Do nothing.
}


ExceptionLexer::~ExceptionLexer() {
	; // Do nothing.
}


int ExceptionLexer::getLineNumber() {
	return this->lineNumber;
}


void ExceptionLexer::print() {
	// Print the parent's error message.
	Exception::print();

	// Add information specific to the child.
	std::cerr << "\tLine Number: " << this->lineNumber << "\n";
}
