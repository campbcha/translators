#include <iostream>
#include <fstream>

#include "Tester.h"

int main(int argc, char** argv) {
	std::string testFileName = "testFile.txt";

	Tester myTester;

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

