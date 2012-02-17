#include "F.h"


F::F() {
	// Randomly descend into grammar productions.
	int number = (rand() % 100 ) + 1;
	if ( number < 95 ) {
		parseNodes.push_back(new T());
		parseNodes.push_back(new F());
	}
	else {
		; // Do nothing.
	}
}


void F::print(int depth) {
	//const char* function_name = "F::print()";
	
	// Print this node.
	for ( int i = 0; i < depth; i++ ) {
		std::cout << " ";
	}
	std::cout << "F" << "\n";

	// Call print on each child node.
	ParseNode::print(depth);
}


void F::writeLexeme(std::ostream& ostream) {
	// Write child nodes.
	ParseNode::writeLexeme(ostream);
}
