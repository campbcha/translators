/* For testing the symbol table only */

#include <iostream>
#include <string>
#include "SymbolTable.h"
#include "../../Exception.h"

int testSymbolToken();
int testSymbolTokenInteger();
int testSymbolTokenReal();
int testSymbolTokenBoolean();
int testSymbolTokenString();

int main(int argc, char** argv) {
	SymbolTable* one = new SymbolTable(NULL);
	SymbolTable* two = new SymbolTable(one);

	// Fill ONE
	std::cout << "MAP 1" << std::endl;
	one->declareIdentifier("testInt5", TOKEN_INTEGER);
	one->setIntegerValue("testInt5", 5);
	std::cout << "testInt5 (" << one->getIdentifierType("testInt5") << ") => " << one->getIntegerValue("testInt5") << std::endl;

	one->declareIdentifier("testReal3.5", TOKEN_REAL);
	one->setRealValue("testReal3.5", 3.5);
	std::cout << "testReal3.5 (" << one->getIdentifierType("testReal3.5") << ") => " << one->getRealValue("testReal3.5") << std::endl;
	
	one->declareIdentifier("testBooltrue", TOKEN_BOOLEAN);
	one->setBooleanValue("testBooltrue", true);
	std::cout << "testBooltrue (" << one->getIdentifierType("testBooltrue") << ") => " << one->getBooleanValue("testBooltrue") << std::endl;
	
	one->declareIdentifier("testStringTEST", TOKEN_STRING);
	one->setStringValue("testStringTEST", "TEST");
	std::cout << "testStringTEST (" << one->getIdentifierType("testStringTEST") << ") => " << one->getStringValue("testStringTEST") << std::endl;

	std::cout << "---------------------------" << std::endl;

	// Fill TWO
	std::cout << "MAP 2" << std::endl;
	two->declareIdentifier("testInt45", TOKEN_INTEGER);
	two->setIntegerValue("testInt45", 45);
	std::cout << "testInt45 (" << two->getIdentifierType("testInt45") << ") => " << two->getIntegerValue("testInt45") << std::endl;
	std::cout << "testInt5 (" << two->getIdentifierType("testInt5") << ") => " << two->getIntegerValue("testInt5") << std::endl;

	two->setIntegerValue("testInt5", 55);
	std::cout << "testInt5 (" << two->getIdentifierType("testInt5") << ") => " << two->getIntegerValue("testInt5") << std::endl;

	two->declareIdentifier("testReal31.5", TOKEN_REAL);
	two->setRealValue("testReal31.5", 31.5);
	std::cout << "testReal31.5 (" << two->getIdentifierType("testReal31.5") << ") => " << two->getRealValue("testReal31.5") << std::endl;
	std::cout << "testReal3.5 (" << two->getIdentifierType("testReal3.5") << ") => " << two->getRealValue("testReal3.5") << std::endl;
	
	two->declareIdentifier("testBoolfalse", TOKEN_BOOLEAN);
	two->setBooleanValue("testBoolfalse", false);
	std::cout << "testBoolfalse (" << two->getIdentifierType("testBoolfalse") << ") => " << two->getBooleanValue("testBoolfalse") << std::endl;
	std::cout << "testBooltrue (" << two->getIdentifierType("testBooltrue") << ") => " << two->getBooleanValue("testBooltrue") << std::endl;
	
	two->declareIdentifier("testStringBLARGH", TOKEN_STRING);
	two->setStringValue("testStringBLARGH", "BLARGH");
	std::cout << "testStringBLARGH (" << two->getIdentifierType("testStringBLARGH") << ") => " << two->getStringValue("testStringBLARGH") << std::endl;
	std::cout << "testStringTEST (" << two->getIdentifierType("testStringTEST") << ") => " << two->getStringValue("testStringTEST") << std::endl;

	std::cout << "---------------------------" << std::endl;

	// Print Maps
	two->printMap();

	std::cout << "---------------------------" << std::endl;
}

int testSymbolToken() {
	int failCount = 0;
	Symbol* testSymbol = NULL;

	// Test TOKEN
	std::cout << "Test TOKEN" << std::endl;

	// Make symbol
	testSymbol = new Symbol(TOKEN);

	// Get type
	if (TOKEN != testSymbol->getType()) {
		failCount++;
		std::cout << "Type should be " << TOKEN << ". Actual: " << testSymbol->getType() << std::endl;
	} else {
		std::cout << "PASS" << std::endl;
	}

	// Try to set boolean
	try {
		testSymbol->setBooleanValue(true);
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	// Try to set integer
	try {
		testSymbol->setIntegerValue(2);
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	// Try to set real
	try {
		testSymbol->setRealValue(3.14);
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	// Try to set string
	try {
		testSymbol->setStringValue("TestString");
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	delete testSymbol;
	testSymbol = NULL;
	std::cout << "Test TOKEN Done" << std::endl;

	return failCount;
}

int testSymbolTokenInteger() {
	int failCount = 0;
	Symbol* testSymbol = NULL;

	// Test TOKEN_INTEGER
	std::cout << "Test TOKEN_INTEGER" << std::endl;

	// Make symbol
	testSymbol = new Symbol(TOKEN_INTEGER);

	// Get type
	if (TOKEN_INTEGER != testSymbol->getType()) {
		failCount++;
		std::cout << "Type should be " << TOKEN_INTEGER << ". Actual: " << testSymbol->getType() << std::endl;
	} else {
		std::cout << "PASS" << std::endl;
	}

	// Try to set boolean
	try {
		testSymbol->setBooleanValue(true);
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	// Try to set integer
	try {
		testSymbol->setIntegerValue(2);
		std::cout << "PASS" << std::endl;
	} catch (Exception* e) {
		e->print();
		failCount++;
		std::cout << "FAIL" << std::endl;
	}

	// Try to set real
	try {
		testSymbol->setRealValue(3.14);
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	// Try to set string
	try {
		testSymbol->setStringValue("TestString");
		failCount++;
		std::cout << "FAIL" << std::endl;
	} catch (Exception* e) {
		std::cout << "PASS" << std::endl;
	}

	delete testSymbol;
	testSymbol = NULL;
	std::cout << "Test TOKEN_INTEGER Done" << std::endl;

	return failCount;
}

int testSymbolTokenReal() {
	return 0;
}

int testSymbolTokenBoolean() {
	return 0;
}

int testSymbolTokenString() {
	return 0;
}