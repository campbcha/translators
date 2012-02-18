#include "Token.h"


Token::Token(Tag tag) : tag(tag) {
	; //Do nothing.
}


Tag Token::getTag() {
	return this->tag;
}


std::string Token::getTagString() {
	switch(tag) {
		case FUNCTION_COSINE:
			return "cos";
			break;
		case FUNCTION_LOGARITHM:
			return "logn";
			break;
		case FUNCTION_PRINTLN:
			return "println";
			break;
		case FUNCTION_SINE:
			return "sin";
			break;
		case FUNCTION_TANGENT:
			return "tan";
			break;
		case OPERATOR_ADDITION:
			return "+";
			break;
		case OPERATOR_AND:
			return "and";
			break;
		case OPERATOR_DIVISION:
			return "/";
			break;
		case OPERATOR_EQUALITY:
			return "=";
			break;
		case OPERATOR_EXPONENTIATION:
			return "^";
			break;
		case OPERATOR_LESS_THAN:
			return "<";
			break;
		case OPERATOR_MODULUS:
			return "%";
			break;
		case OPERATOR_MULTIPLICATION:
			return "*";
			break;
		case OPERATOR_NOT:
			return "not";
			break;
		case OPERATOR_OR:
			return "or";
			break;
		case OPERATOR_SUBTRACTION:
			return "-";
			break;
		case PARENTHESIS_CLOSE:
			return ")";
			break;
		case PARENTHESIS_OPEN:
			return "(";
			break;
		case STATEMENT_ASSIGN:
			return "assign";
			break;
		case STATEMENT_IF:
			return "if";
			break;
		case STATEMENT_IFF:
			return "iff";
			break;
		case STATEMENT_LET:
			return "let";
			break;
		case STATEMENT_WHILE:
			return "while";
			break;
		case TYPE_BOOLEAN:
			return "bool";
			break;
		case TYPE_INTEGER:
			return "int";
			break;
		case TYPE_REAL:
			return "real";
			break;
		case TYPE_STRING:
			return "string";
			break;
		case VALUE_BOOLEAN:
			return "boolValue";
			break;
		case VALUE_INTEGER:
			return "intValue";
			break;
		case VALUE_REAL:
			return "realValue";
			break;
		case VALUE_STRING:
			return "stringValue";
			break;
		// Unknown
		default:
			return "ERROR: Tag type print statement not found."; 
			break;
	}
}

void Token::print() {
	// Print the appropriate tag type to std::cout.
	switch(tag) {
		case FUNCTION_COSINE:
			std::cout << "cos";
			break;
		case FUNCTION_LOGARITHM:
			std::cout << "logn";
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


void Token::printLexeme(std::ostream& ostream) {
	//const char* function_name = "Token::printLexeme()";

	ostream << this->getTagString().c_str();
}
