#include "Lexer.h"


Lexer::Lexer(std::string sourceFilePath) {
	// Open the source code file for reading.
	this->sourceFile.open(sourceFilePath.c_str());

	// Set the line number count.
	this->lineNumber = 1;
}


Lexer::~Lexer() {
	// Close the source code file.
	if ( sourceFile.is_open() ) {
		sourceFile.close();
	}
}


Token* Lexer::scan() {
	Token* token = NULL;

	// Throw exception if file is not good.
	if ( sourceFile.good() == false ) {
		throw new Exception("Source file is not 'good' for uknown reason(s). This is bad; I sure hope it never prints. Ever.\n");
	}

	// Gloss over all whitespace in the file.
	skipWhitespace();

	// Return NULL if at the end of the source code file.
	if ( sourceFile.eof() ) {
		return NULL;
	}

	// Try to match an operator.
	token = matchOperator();
	if ( token != NULL ) {
		return token;
	}

	// Try to match an integer or real number.
	token = matchIntegerOrReal();
	if ( token != NULL ) {
		return token;
	}

	// Try to match a delimited string.
	token = matchStringDelimited();
	if ( token != NULL ) {
		return token;
	}

	// Try to match a keyword or non-delimited string,
	token = matchKeywordOrStringNonDelimited();
	if ( token != NULL ) {
		return token;
	}

	// Throw no token found exception.
	throw new Exception("No token found matching the input.\n");
}


Token* Lexer::compareKeyword(std::string* stringValue) {
	// The value returned by string::compare(char*) if the two strings are equal.
	const int STRING_EQUALITY = 0;

	// Return a keyword if applicable.
	// This code is ugly, and should be isolated in its own file for being an abommination among text.
	// It is, however, in alphabetical order, and should stay that way.
	if ( stringValue->compare("and") == STRING_EQUALITY ) {
		return new Token(OPERATOR_AND);
	}
	else if ( stringValue->compare("assign") == STRING_EQUALITY ) {
		return new Token(STATEMENT_ASSIGN);
	}
	else if ( stringValue->compare("bool") == STRING_EQUALITY ) {
		return new Token(TYPE_BOOLEAN);
	}
	else if ( stringValue->compare("cos") == STRING_EQUALITY ) {
		return new Token(FUNCTION_COSINE);
	}
	else if ( stringValue->compare("false") == STRING_EQUALITY ) {
		return new TokenBoolean(false);
	}
	else if ( stringValue->compare("if") == STRING_EQUALITY ) {
		return new Token(STATEMENT_IF);
	}
	else if ( stringValue->compare("iff") == STRING_EQUALITY ) {
		return new Token(STATEMENT_IFF);
	}
	else if ( stringValue->compare("int") == STRING_EQUALITY ) {
		return new Token(TYPE_INTEGER);
	}
	else if ( stringValue->compare("let") == STRING_EQUALITY ) {
		return new Token(STATEMENT_LET);
	}
	else if ( stringValue->compare("logn") == STRING_EQUALITY ) {
		return new Token(FUNCTION_LOGARITHM);
	}
	else if ( stringValue->compare("not") == STRING_EQUALITY ) {
		return new Token(OPERATOR_NOT);
	}
	else if ( stringValue->compare("or") == STRING_EQUALITY ) {
		return new Token(OPERATOR_OR);
	}
	else if ( stringValue->compare("println") == STRING_EQUALITY ) {
		return new Token(FUNCTION_PRINTLN);
	}
	else if ( stringValue->compare("real") == STRING_EQUALITY ) {
		return new Token(TYPE_REAL);
	}
	else if ( stringValue->compare("sin") == STRING_EQUALITY ) {
		return new Token(FUNCTION_SINE);
	}
	else if ( stringValue->compare("string") == STRING_EQUALITY ) {
		return new Token(TYPE_STRING);
	}
	else if ( stringValue->compare("tan") == STRING_EQUALITY ) {
		return new Token(FUNCTION_TANGENT);
	}
	else if ( stringValue->compare("true") == STRING_EQUALITY ) {
		return new TokenBoolean(true);
	}
	else if ( stringValue->compare("while") == STRING_EQUALITY ) {
		return new Token(STATEMENT_WHILE);
	}

	// String does not match any keywords in the language.
	return NULL;
}

char Lexer::readCharacter() {
	// Move the file pointer one character over.
	sourceFile.get();

	// Return the character that the file pointer is now pointing to.
	return sourceFile.peek();
}


int Lexer::readDigits() {
	const int RADIX = 10;
	char character = '\0';
	int integerValue = 0xdeadbeef;

	// Check that the next character is a digit.
	character = sourceFile.peek();
	if ( !isdigit(character) ) {
		throw new Exception("Expected digit after call to readDigits().\n");
	}

	// Initialize the integer value.
	integerValue = 0;
	
	// Read in the digit value.
	while ( isdigit(character) ) {
		// Update the integer value based off the read-in value.
		integerValue = ( integerValue * RADIX ) + ( character - '0' );

		// Read in the next character of the file.
		character = readCharacter();
	}

	// Return the read-in integer value.
	return integerValue;
}


char Lexer::matchCharacterSpecial() {
	// Read in the next character in the source code file stream.
	char character = readCharacter();

	// Try to match the read-in character to the appropriate special value.
	// Note: There should be a better way to do this...
	switch ( character ) {
	case '\\':
		return '\\';
	case '\'':
		return '\'';
	case '"':
		return '"';
	case '0':
		return '\0';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	default:
		throw new Exception("Unrecognized character escape sequence. We probably assumed it wasn't important and didn't bother to implement it. Please don't dock us points. :(\n");
	}
}


Token* Lexer::matchOperator() {
	// Peek at the next character in the source code file stream.
	char character = sourceFile.peek();

	// Try to match the read-in character to an operator.
	switch ( character ) {
	case '+':
		character = readCharacter();
		// Return a positive number (integer or real) or an addition operator.
		if ( isdigit(character) ) {
			return matchIntegerOrReal();
		}
		return new Token(OPERATOR_ADDITION);
	case '-':
		character = readCharacter();
		// Return a negative number (integer or real) or an addition operator.
		if ( isdigit(character) ) {
			return matchIntegerOrReal(false);
		}
		return new Token(OPERATOR_SUBTRACTION);
	case '*':
		readCharacter();
		return new Token(OPERATOR_MULTIPLICATION);
	case '/':
		readCharacter();
		return new Token(OPERATOR_DIVISION);
	case '%':
		readCharacter();
		return new Token(OPERATOR_MODULUS);
	case '^':
		readCharacter();
		return new Token(OPERATOR_EXPONENTIATION);
	case '=':
		readCharacter();
		return new Token(OPERATOR_EQUALITY);
	case '<':
		readCharacter();
		return new Token(OPERATOR_LESS_THAN);
	case '(':
		readCharacter();
		return new Token(PARENTHESIS_OPEN);
	case ')':
		readCharacter();
		return new Token(PARENTHESIS_CLOSE);
	default: // Next character is not an operator character.
		return NULL;
	}
}


Token* Lexer::matchIntegerOrReal(bool isPositive) {
	// Integer value to store the digit in.
	int integerValue = 0xdeadbeef;

	// Peek at the next character in the source code file stream.
	char character = sourceFile.peek();

	// Check if the next character in the source code file is a digit.
	if ( !isdigit( character ) ) {
		return NULL;
	}

	// Read in the digits of the number.
	integerValue = readDigits();

	// Set the sign of the number.
	if ( isPositive == false ) {
		integerValue *= -1;
	}

	// Peek at the next character in the source code file stream.
	character = sourceFile.peek();

	// Check for a real number decimal.
	if ( character == '.' ) {
		return matchRealDecimal(integerValue);
	}

	// Check for a real number exponent.
	if ( character == 'e' ) {
		return matchRealExponent(integerValue);
	}

	// Return the TokenIneger with the read-in integer value.
	return new TokenInteger(integerValue);
}


Token* Lexer::matchRealDecimal(int integerValue) {
	// The base of the number system.
	const int RADIX = 10;
	// The next character in the file stream.
	char character = '\0';
	double realValue = 0xdeadbeef;
	double decimalValue = 0xdeadbeef;
	int decimalLength = 0xdeadbeef;

	// Read in the next character (moving past the '.').
	character = readCharacter();

	// Initialize the decimal value and length.
	decimalLength = 0;
	decimalValue = 0;

	// Calculate the decimal value.
	while( isdigit( character ) ) {
		// Set the current decimal value.
		decimalValue = ( decimalValue * RADIX ) + ( character - '0' );

		// Increment the decimal length.
		decimalLength++;

		// Read in the next character.
		character = readCharacter();
	}

	// Calculate the real number value.
	// CHANGED pow(int, int) to pow(float, int) for compatibility w/Win
	if ( decimalLength == 0 ) {
		realValue = (double)integerValue;
	}
	else {
		realValue = integerValue + ( decimalValue / ((double)( pow(((double)RADIX), decimalLength) )) );
	}

	// Check to see if an exponent exists.
	if ( character == 'e' ) {
		return matchRealExponent(realValue);
	}

	// Return the TokenReal with the read-in real number value.
	return new TokenReal(realValue);
}


Token* Lexer::matchRealExponent(int integerValue) {
	// Convert the int to a double and call an overloaded function.
	return matchRealExponent((double)integerValue);
}

Token* Lexer::matchRealExponent(double baseValue) {
	// The base of the number system.
	const int RADIX = 10;
	// The next character in the file stream.
	char character = '\0';
	double exponentValue = 0xdeadbeef;
	bool isPositive = true;

	// Read in the next character (moving past the 'e').
	character = readCharacter();

	// Check for an exponent sign.
	if ( character == '+' ) {
		isPositive = true;
		character = readCharacter();
	}
	else if ( character == '-' ) {
		isPositive = false;
		character = readCharacter();
	}

	// Check that the next character is a digit.
	if ( !isdigit( character ) ) {
		throw new Exception("Expected number after 'e[+-]?'.\n");
	}

	// Initialize the exponent value.
	exponentValue = readDigits();

	// Set the sign of the exponent value.
	if ( isPositive == false ) {
		exponentValue *= -1;
	}

	// Multiply the real number by the exponent.
	baseValue *= pow(RADIX, exponentValue);

	// Return the TokenReal with the complete real number value.
	return new TokenReal(baseValue);
}


Token* Lexer::matchKeywordOrStringNonDelimited() {
	// Temporary token to allow code branching.
	Token* token = NULL;
	// String object to append read-in values to and assign to the Token.
	std::string* stringValue = NULL;
	// The next character in the source code file stream.
	char character = '\0';

	// Peek at the next character in the source code file.
	character = sourceFile.peek();

	// Check if the next character begins a keyword or string.
	if ( !isalpha( character ) && character != '_' ) {
		return NULL;
	}

	// Initialize the temporary string.
	stringValue = new std::string();

	// Read the string in from the source code file.
	while ( isalnum( character ) || character == '_' ) {
		// Append the newly read-in value to the string.
		stringValue->append(&character, 1);

		// Read in the next character.
		character = readCharacter();
	}

	// Set the token to be a keyword or a string.
	token = compareKeyword(stringValue);
	if ( token == NULL ) { // Not a keyword; must be a regular string object.
		token = new TokenString(stringValue);
	}
	else { // Is a keyword; the string object can be deleted.
		delete stringValue;
	}

	// Return the token.
	return token;
}


Token* Lexer::matchStringDelimited() {
	// String object to append read-in values to and assign to the Token.
	std::string* stringValue = NULL;
	// Delimiter of the string.
	char delimiter = '\0';
	// The next character in the source code file stream.
	char character = '\0';

	// Peek at the next character in the source code file.
	character = sourceFile.peek();

	// Check that the next character matches a possible string delimiter.
	if ( character != '\'' && character != '"' ) {
		return NULL;
	}

	// Initialize the return string.
	stringValue = new std::string();

	// Set the string delimiter.
	delimiter = character;

	// Read in the next character in the file.
	character = readCharacter();

	// Read in all input from the file until the delimiter is met again.
	while ( character != delimiter ) {
		// Check for a special character.
		if ( character == '\\' ) {
			character = matchCharacterSpecial();
		}

		// Append the read-in value to the string.
		stringValue->append(&character, 1);

		// Read in the next character in the file.
		character = readCharacter();

		// Check for the end of the file.
		if ( sourceFile.eof() == true ) {
			delete stringValue;
			throw new Exception("End of file reached before end of string.\n");
		}
	}

	// Read in the end string delimiter.
	readCharacter();

	// Return the token.
	return new TokenString(stringValue);
}


void Lexer::skipWhitespace() {
	// Peek at the next character in the source code file stream.
	char character = sourceFile.peek();

	// Continuously read-in the file until a non-whitespace character is found.
	while ( character == ' ' || character == '\n' || character == '\t' ) {
		// Increment the line number if applicable.
		if ( character == '\n' ) {
			this->lineNumber++;
		}

		// Read in the next character.
		character = readCharacter();
	}
}


void Lexer::throwException(const std::string message) {
	// Throw the exception.
	throw new ExceptionLexer(message, this->lineNumber);
}
