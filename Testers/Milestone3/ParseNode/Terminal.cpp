#include "Terminal.h"


Terminal::Terminal(Tag tag) {
	//const char* function_name = "Terminal::Terminal()";

	// Create the appropriate Token.
	if ( tag == VALUE_BOOLEAN ) {
		token = Ibtl::randomTokenBoolean();
	}
	else if ( tag == VALUE_INTEGER ) {
		token = Ibtl::randomTokenInteger();
	}
	else if ( tag == VALUE_REAL ) {
		token = Ibtl::randomTokenReal();
	}
	else if ( tag == VALUE_STRING ) {
		token = Ibtl::randomTokenString();
	}
	else {
		token = new Token(tag);
	}
}


void Terminal::print() {
	//const char* function_name = "Terminal::print()";

	std::cout << " ";
	token->writeLexeme(std::cout);
	std::cout << " ";
}
