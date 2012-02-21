#include "Symbol.h"

Symbol::Symbol(TokenType type) : symbolType(type), symbolToken(NULL) {
	; // Do nothing
}

Symbol::~Symbol() {
	; // Do nothing
}

TokenType Symbol::getType() {
	return this->symbolType;
}


void Symbol::setIntegerValue(int val) {
	if (symbolType != TOKEN_INTEGER) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken != NULL) {
		delete symbolToken;
	}
	
	symbolToken = new TokenInteger(val);
}

void Symbol::setRealValue(double val) {
	if (symbolType != TOKEN_REAL) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken != NULL) {
		delete symbolToken;
	}
	
	symbolToken = new TokenReal(val);
}

void Symbol::setBooleanValue(bool val) {
	if (symbolType != TOKEN_BOOLEAN) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken != NULL) {
		delete symbolToken;
	}
	
	symbolToken = new TokenBoolean(val);
}

void Symbol::setStringValue(std::string val) {
	if (symbolType != TOKEN_STRING) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken != NULL) {
		delete symbolToken;
	}
	
	symbolToken = new TokenString(new std::string(val));
}

int Symbol::getIntegerValue() {
	if (symbolType != TOKEN_INTEGER) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken == NULL) {
		throw new Exception("Value unassigned");
	}

	TokenInteger* tempToken = (TokenInteger*) symbolToken;
	return tempToken->getValue();
}

double Symbol::getRealValue() {
	if (symbolType != TOKEN_REAL) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken == NULL) {
		throw new Exception("Value unassigned");
	}

	TokenReal* tempToken = (TokenReal*) symbolToken;
	return tempToken->getValue();
}

bool Symbol::getBooleanValue() {
	if (symbolType != TOKEN_BOOLEAN) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken == NULL) {
		throw new Exception("Value unassigned");
	}

	TokenBoolean* tempToken = (TokenBoolean*) symbolToken;
	return tempToken->getValue();
}

std::string Symbol::getStringValue() {
	if (symbolType != TOKEN_STRING) {
		throw new Exception("Invalid Type");
	}

	if (symbolToken == NULL) {
		throw new Exception("Value unassigned");
	}

	TokenString* tempToken = (TokenString*) symbolToken;
	const std::string* tempString = tempToken->getValue();
	return *tempString;
}


