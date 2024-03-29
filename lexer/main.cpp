#include <iostream>
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#endif

#include "token.h"
#include "lexer.h"

using namespace std;

int main() {
    Lexer lexer("test.ibtl");
    Token* curToken;
    while(curToken = lexer.scan()) {
        cout << "Line " << curToken->getLine() << ": " << curToken->toString() << endl;
    }
    return 0;
}

/*int main(int argc, char** argv) {
	VerboseType vType = ALL;
	int numRuns = 10;
	std::string rootTestFileName = "testFile";
	Lexer* testLexer = NULL;

	std::cout << "------------ Lexer Tester -------------" << std::endl;
	std::cout << "CS480: campbcha, wadec, zoonb, piorkowd" << std::endl << std::endl;
	std::cout << "Running " << numRuns << " tests" << std::endl;
	if ( vType == ALL ) {
		std::cout << "PRINTING ALL MESSAGES";
	} else if ( vType == ERRORS ) {
		std::cout << "PRINTING ONLY ERRORS";
	} else if ( vType == NONE ) {
		std::cout << "PRINTING NO MESSAGES";
	} else {
		std::cout << "VERBOSE ERROR";
	}
	std::cout << std::endl << std::endl;

	for ( int i = 1 ; i <= numRuns; i++ ) {
		Tester myTester;
		std::stringstream out;

		std::cout << "--------------------------------" << std::endl;
		std::cout << "Start test " << i << std::endl;

		out << rootTestFileName << i << ".txt";
		std::string testFileName = out.str();
		try {
			myTester.generateTestFile(testFileName);
			testLexer = new Lexer(testFileName.c_str());
			myTester.run(testLexer, vType);
		} catch (Exception e) {
			e.print();
		}

		if ( testLexer != NULL ) {
			delete testLexer;
			testLexer = NULL;
		}
		std::cout << "Test " << i << " done" << std::endl;
		std::cout << "--------------------------------" << std::endl;
#ifdef _WIN32
		Sleep(1000);
#else
		sleep(1);
#endif
	}
	return 0;
}*/


