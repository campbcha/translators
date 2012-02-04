#include <iostream>
#include <fstream>

#include "Tester.h"

int main(int argc, char** argv) {
	std::string testFileName = "testFile.txt";
	std::ifstream testFileIn;

	Tester myTester;

	try {
		myTester.generateTestFile(testFileName);

		testFileIn.open(testFileName.c_str());
		Lexer testLexer = Lexer(&testFileIn);
		myTester.run(testLexer, ALL);

		
	} catch (Exception e) {
		e.print();
	}
	// Create lexer object

	// Test lexer object

	std::cin.get();
	return 0;
}

