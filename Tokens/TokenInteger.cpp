#include "TokenInteger.h"

TokenInteger::TokenInteger(int value) : Token(VALUE_INTEGER),value(value) {
	; //Do nothing.
}

int TokenInteger::getValue() {
	return this->value;
}

void TokenInteger::print() {
	// Call the parent print function.
	Token::print();

	// Print this token's integer value.
	std::cout << this->value;
}

