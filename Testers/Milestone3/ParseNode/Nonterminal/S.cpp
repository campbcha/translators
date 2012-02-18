#include "S.h"


S::S() {
	//const char* functionName = "S::S()";

	// Generate a random number.
	int number = (rand() % 100);

	// Randomly apply a grammar production.
	if ( number < 5 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
	}
	else if ( number < 10 ) {
		parseNodes.push_back(new Terminal(Ibtl::randomTokenAtom()));
	}
	else if ( number < 15 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
	}
	else if ( number < 20 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
		parseNodes.push_back(new S());
	}
	else if ( number < 95 ) {
		parseNodes.push_back(new Terminal(Ibtl::randomTokenAtom()));
		parseNodes.push_back(new S());
	}
	else {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
		parseNodes.push_back(new S());
	}
}


void S::print(int depth) {
	//const char* function_name = "S::print()";
	
	// Print this node.
	for ( int i = 0; i < depth; i++ ) {
		std::cout << " ";
	}
	std::cout << "S" << "\n";

	// Print each child node.
	ParseNode::print(depth);
}


void S::printLatex(std::ostream& ostream) {
        
        // Print this node and begin its header.
	std::cout << " \\pstree{ \\TR{\\textit{S}} }{";

	// Print each child node.
	ParseNode::printLatex(ostream);

	// End this node's header.
	std::cout << "} ";
}


void S::printLexeme(std::ostream& ostream) {
	// Write child nodes.
	ParseNode::printLexeme(ostream);
}
