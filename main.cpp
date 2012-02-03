/** Entry point to the Naive Language Compiler
 */

#include <iostream>

#include "Exception.h"
#include "Lexer.h"

int main( int argc, char* argv[] ) {
	// DEBUG
	Token* token;
	Lexer lex("test.ibtl");

	try {
		token = lex.scan();
		while ( token != NULL ) {
			token->print();
			std::cout << "\n";
			token = lex.scan();
		}
	}
	catch ( Exception* exception ) {
		exception->print();
	}
	catch (...) {
		std::cerr << "ffs.\n";
	}

	// Do nothing, but a dance.
	return 0;
}
