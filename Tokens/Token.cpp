#include "Token.h"

Token::Token(Tag tag) : tag(tag) {
	; //Do nothing.
}

Tag Token::getTag() {
	return this->tag;
}

void Token::print() {
	// Print the appropriate tag type to std::cout.
	switch(tag) {
		// (
		case PARENTHESIS_OPEN:
			std::cout << "(";
			break;
		// )
		case PARENTHESIS_CLOSE:
			std::cout << ")";
			break;
		// int
		case VALUE_INTEGER:
			std::cout << "int";
			break;
		// real
		case VALUE_REAL:
			std::cout << "real";
			break;
		// string
		case VALUE_STRING:
			std::cout << "string";
			break;
		// +
		case OPERATOR_ADDITION:
			std::cout << "+";
			break;
		case VALUE_BOOLEAN:
			std::cout << "bool";
			break;
		// Unknown
		default:
			std::cout << "ERROR: Tag type print statement not found."; 
			break;
	}
	std::cout << "\t";
}
