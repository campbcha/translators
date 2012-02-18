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

	token->printLexeme(std::cout);

	std::cout << "\n";
}


void Terminal::printLatex(std::ostream& ostream) {
	// Print this node.
	ostream << " \\TR{";
	token->printLexeme(ostream);
	ostream << "} ";
}


void Terminal::printLexeme(std::ostream& ostream) {
	ostream << " ";
	token->printLexeme(ostream);
	ostream << " ";
}

