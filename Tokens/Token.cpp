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
		case FUNCTION_COSINE:
			std::cout << "cos";
			break;
		case FUNCTION_LOGARITHM:
			std::cout << "log";
			break;
		case FUNCTION_PRINTLN:
			std::cout << "println";
			break;
		case FUNCTION_SINE:
			std::cout << "sin";
			break;
		case FUNCTION_TANGENT:
			std::cout << "tan";
			break;
		case OPERATOR_ADDITION:
			std::cout << "+";
			break;
		case OPERATOR_AND:
			std::cout << "and";
			break;
		case OPERATOR_DIVISION:
			std::cout << "/";
			break;
		case OPERATOR_EQUALITY:
			std::cout << "=";
			break;
		case OPERATOR_EXPONENTIATION:
			std::cout << "^";
			break;
		case OPERATOR_LESS_THAN:
			std::cout << "<";
			break;
		case OPERATOR_MODULUS:
			std::cout << "%";
			break;
		case OPERATOR_MULTIPLICATION:
			std::cout << "*";
			break;
		case OPERATOR_NOT:
			std::cout << "not";
			break;
		case OPERATOR_OR:
			std::cout << "or";
			break;
		case OPERATOR_SUBTRACTION:
			std::cout << "-";
			break;
		case PARENTHESIS_CLOSE:
			std::cout << ")";
			break;
		case PARENTHESIS_OPEN:
			std::cout << "(";
			break;
		case STATEMENT_ASSIGN:
			std::cout << "assign";
			break;
		case STATEMENT_IF:
			std::cout << "if";
			break;
		case STATEMENT_IFF:
			std::cout << "iff";
			break;
		case STATEMENT_LET:
			std::cout << "let";
			break;
		case STATEMENT_WHILE:
			std::cout << "while";
			break;
		case TYPE_BOOLEAN:
			std::cout << "bool";
			break;
		case TYPE_INTEGER:
			std::cout << "int";
			break;
		case TYPE_REAL:
			std::cout << "real";
			break;
		case TYPE_STRING:
			std::cout << "string";
			break;
		case VALUE_BOOLEAN:
			std::cout << "boolValue";
			break;
		case VALUE_INTEGER:
			std::cout << "intValue";
			break;
		case VALUE_REAL:
			std::cout << "realValue";
			break;
		case VALUE_STRING:
			std::cout << "stringValue";
			break;
		// Unknown
		default:
			std::cout << "ERROR: Tag type print statement not found."; 
			break;
	}
	std::cout << "\n";
}
