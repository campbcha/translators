#include <iostream>
#include <fstream>

#include "Tester.h"
#include "../../ExceptionLexer.h"

int main(int argc, char** argv) {
	std::string testFileName = "testFile.txt";

	Tester myTester;

	try {
		throw new ExceptionLexer("Testing,", 100);
	}
	catch (Exception* exception){
		exception->print();
	}

	try {
		myTester.generateTestFile(testFileName);

		Lexer* testLexer = new Lexer(testFileName);
		myTester.run(testLexer, ALL);

		
	} catch (Exception e) {
		e.print();
	}
	// Create lexer object

	// Test lexer object

	std::cin.get();
	return 0;
}

