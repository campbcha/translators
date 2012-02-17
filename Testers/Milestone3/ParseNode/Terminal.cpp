#include "Terminal.h"


Terminal::Terminal(Token* token) {
	//const char* function_name = "Terminal::Terminal()";

	// Assign the token.
	this->token = token;
}


void Terminal::print(int depth) {
	//const char* function_name = "Terminal::print()";

	for (int i = 0; i < depth; i++) {
		std::cout << " ";
	}

	token->writeLexeme(std::cout);

	std::cout << "\n";
}


void Terminal::writeLexeme(std::ostream& ostream) {
	ostream << " ";
	token->writeLexeme(ostream);
	ostream << " ";
}
