#include "TokenString.h"

TokenString::TokenString(std::string* value) : Token(VALUE_STRING),value(value) {
	; // Do nothing.
}

const std::string* TokenString::getValue() {
	return this->value;
}

void TokenString::print() {
	// Call the parent's print function.
	Token::print();

	// Print this object's value attribute.
	std::cout << this->value->c_str();
}

