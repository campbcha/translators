#include "S.h"


S::S() {
	const char* functionName = "S::S()";

	// Generate a random number.
	int number = (rand() % 6);

	// Randomly apply a grammar production.
	if ( number == 0 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
	}
	else if ( number == 1 ) {
		parseNodes.push_back(new Terminal(Ibtl::randomTokenAtom()));
	}
	else if ( number == 2 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
	}
	else if ( number == 3 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
		parseNodes.push_back(new S());
	}
	else if ( number == 4 ) {
		parseNodes.push_back(new Terminal(Ibtl::randomTokenAtom()));
		parseNodes.push_back(new S());
	}
	else if ( number == 5 ) {
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
		parseNodes.push_back(new S());
	}
	else {
		throw new Exception("Unexpected grammar production.", functionName);
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


void S::writeLexeme(std::ostream& ostream) {
	// Write child nodes.
	ParseNode::writeLexeme(ostream);
}
