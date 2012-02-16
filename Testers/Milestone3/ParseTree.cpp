#include "ParseTree.h"


ParseTree::ParseTree() {
	this->rootNode = NULL;
	throw new Exception("Function not yet implemented.");
}


void ParseTree::print() {
	// Validate preconditions.
	if ( rootNode == NULL ) {
		throw new Exception("Root node was NULL.");
	}

	// Call print on the root node.
	rootNode->print();
}
