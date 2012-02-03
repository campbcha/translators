#include "TokenBoolean.h"

TokenBoolean::TokenBoolean(bool value) : Token(VALUE_BOOLEAN),value(value) {
	; //Do nothing.
}

bool TokenBoolean::getValue() {
	return this->value;
}

void TokenBoolean::print() {
	// Call the parent's print function.
	Token::print();

	// Print the boolean value of the token.
	std::cout << this->value;
}

