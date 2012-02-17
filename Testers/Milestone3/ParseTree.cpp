#include "ParseTree.h"


ParseTree::ParseTree() {
	// Initialize the random number generator.
	srand( time(NULL) );

	// Initialize the root node.
	this->rootNode = new F();
}


void ParseTree::print() {
	const char* function_name = "ParseTree::print()";

	// Validate preconditions.
	if ( rootNode == NULL ) {
		throw new Exception("Root node was NULL.", function_name);
	}

	// Print the parse tree recursively.
	rootNode->print();
	std::cout << "\n";
}


void ParseTree::writeLexeme(std::ostream& ostream) {
	const char* function_name = "ParseTree::writeLexemes()";

	// Validate preconditions.
	if ( rootNode == NULL ) {
		throw new Exception("Root node was NULL.", function_name);
	}
	
	// Write the parse tree recursively.
	rootNode->writeLexeme(ostream);
	ostream << "\n";
}
