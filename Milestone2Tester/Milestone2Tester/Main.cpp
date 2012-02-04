#include <iostream>

#include "Tester.h"

int main(int argc, char** argv) {
	
	Tester myTester("testFile.txt");

	try {
		myTester.run(ALL);

		
	} catch (Exception e) {
		e.print();
	}
	// Create lexer object

	// Test lexer object

	std::cin.get();
	return 0;
}
