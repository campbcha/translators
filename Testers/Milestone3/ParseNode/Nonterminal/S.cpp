#include "S.h"


S::S() {
	const char* functionName = "S::S()";

	// Generate a random number.
	int number = (rand() % 6);

	// Randomly apply a grammar production.
	if ( number == 0 ) {
		parseNodes.push_back(new Terminal(PARENTHESIS_OPEN));
		parseNodes.push_back(new Terminal(PARENTHESIS_CLOSE));
	}
	else if ( number == 1 ) {
		parseNodes.push_back(new Terminal(STATEMENT_IF));
	}
	else if ( number == 2 ) {
		parseNodes.push_back(new Terminal(PARENTHESIS_OPEN));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(PARENTHESIS_CLOSE));
	}
	else if ( number == 3 ) {
		parseNodes.push_back(new Terminal(PARENTHESIS_OPEN));
		parseNodes.push_back(new Terminal(PARENTHESIS_CLOSE));
		parseNodes.push_back(new S());
	}
	else if ( number == 4 ) {
		parseNodes.push_back(new Terminal(STATEMENT_IF));
		parseNodes.push_back(new S());
	}
	else if ( number == 5 ) {
		parseNodes.push_back(new Terminal(PARENTHESIS_OPEN));
		parseNodes.push_back(new S());
		parseNodes.push_back(new Terminal(PARENTHESIS_CLOSE));
		parseNodes.push_back(new S());
	}
	else {
		throw new Exception("Unexpected grammar production.", functionName);
	}
}


void S::print() {
	//const char* function_name = "S::print()";
	
	// Print each child node.
	ParseNode::print();

	// Print this node.
	std::cout << " S ";
}
