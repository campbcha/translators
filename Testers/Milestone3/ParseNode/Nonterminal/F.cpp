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


void F::print() {
	//const char* function_name = "F::print()";
	
	// Call print on each child node.
	ParseNode::print();

	// Print this node.
	std::cout << " F ";
}
