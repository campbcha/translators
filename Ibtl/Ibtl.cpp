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
