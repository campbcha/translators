#include "TokenReal.h"


TokenReal::TokenReal(double value) : Token(VALUE_REAL),value(value) {
	; // Do nothing.
}


double TokenReal::getValue() {
	return this->value;
}


void TokenReal::print() {
	// Call the parent's print function.
	Token::print();

	// Print this object's real number value to cout.
	std::cout << value;
}


void TokenReal::printLexeme(std::ostream& ostream) {
	ostream << this->value;
}
