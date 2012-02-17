#include "Ibtl.h"

const char Ibtl::stringAlphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

bool Ibtl::randomBoolean() {
	int number;

	// Return random boolean.
	number = rand() % 2;
	if ( number == 1 ) {
		return true;
	}
	return false;
}


double Ibtl::randomReal() {
	double number;
	bool isNegative;

	// Generate random double.
	// This is a garbage implementation.
	number = ((double)rand()) / ((double)rand());

	// Generate random sign.
	isNegative = Ibtl::randomBoolean();

	// Assign random sign to the random double.
	if ( isNegative == true ) {
		number *= -1;
	}

	// Return the random double.
	return number;
}


int Ibtl::randomInteger() {
	int number;
	bool isNegative;

	// Generate random integer.
	number = rand() % INT_MAX;

	// Generate random sign.
	isNegative = Ibtl::randomBoolean();

	// Assign random sign to the random integer.
	if ( isNegative == true ) {
		number *= -1;
	}

	// Return the random integer.
	return number;
}


std::string* Ibtl::randomString() {
	const int MAX_STRING_LENGTH = 25;
	std::string* output;
	int i;

	// Initialize the variables.
	output = new std::string();
	i = 0;

	// Append first letter for non-delimited string.
	output->append(1, Ibtl::stringAlphabet[rand() % sizeof(Ibtl::stringAlphabet - 1 - 10)]);

	// Randomly append additional letters and numbers.
	while ( i < MAX_STRING_LENGTH && ((rand() % 10) != 0) ) {
		output->append(1, Ibtl::stringAlphabet[rand() % sizeof(Ibtl::stringAlphabet - 1)]);
	}

	// Return the string.
	return output;
}


Token* Ibtl::randomTokenAtom() {
	const char* functionName = "Ibtl::randomTokenAtom()";

	int number = rand() % 5;
	// Random value token.
	if ( number == 0 ) {
		return randomTokenBoolean();
	}
	if ( number == 1 ) {
		return randomTokenReal();
	}
	if ( number == 2 ) {
		return randomTokenInteger();
	}
	if ( number == 3 ) {
		return randomTokenString();
	}
	
	// Random other token.
	number = rand() % 25;
	switch (number) {
	case(0):
		return new Token(FUNCTION_COSINE);
	case(1):
		return new Token(FUNCTION_LOGARITHM);
	case(2):
		return new Token(FUNCTION_PRINTLN);
	case(3):
		return new Token(FUNCTION_SINE);
	case(4):
		return new Token(FUNCTION_TANGENT);
	case(5):
		return new Token(OPERATOR_ADDITION);
	case(6):
		return new Token(OPERATOR_AND);
	case(7):
		return new Token(OPERATOR_DIVISION);
	case(8):
		return new Token(OPERATOR_EQUALITY);
	case(9):
		return new Token(OPERATOR_EXPONENTIATION);
	case(10):
		return new Token(OPERATOR_LESS_THAN);
	case(11):
		return new Token(OPERATOR_MODULUS);
	case(12):
		return new Token(OPERATOR_MULTIPLICATION);
	case(13):
		return new Token(OPERATOR_NOT);
	case(14):
		return new Token(OPERATOR_OR);
	case(15):
		return new Token(OPERATOR_SUBTRACTION);
	case(16):
		return new Token(STATEMENT_ASSIGN);
	case(17):
		return new Token(STATEMENT_IF);
	case(18):
		return new Token(STATEMENT_IFF);
	case(19):
		return new Token(STATEMENT_LET);
	case(20):
		return new Token(STATEMENT_WHILE);
	case(21):
		return new Token(TYPE_BOOLEAN);
	case(22):
		return new Token(TYPE_INTEGER);
	case(23):
		return new Token(TYPE_REAL);
	case(24):
		return new Token(TYPE_STRING);
	default:
		break;
	}

	throw new Exception("Unable to generate random Token.", functionName);
}

TokenBoolean* Ibtl::randomTokenBoolean() {
	return new TokenBoolean(Ibtl::randomBoolean());
}


TokenReal* Ibtl::randomTokenReal() {
	return new TokenReal(Ibtl::randomReal());
}


TokenInteger* Ibtl::randomTokenInteger() {
	return new TokenInteger(Ibtl::randomInteger());
}


TokenString* Ibtl::randomTokenString() {
	return new TokenString(Ibtl::randomString());
}
