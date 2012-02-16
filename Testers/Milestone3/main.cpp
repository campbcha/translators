#include <iostream>

#include "ParseTree.h"
#include "ParseNode.h"

int main( int argc, char* argv[] ) {

	try {
		// Initialize a new parse tree.
		ParseTree* parseTree = new ParseTree();
		delete(parseTree);
	}
	catch (Exception* exception) {
		exception->print();
		delete(exception);
	}
	catch(...) {
		std::cerr << "Unknown exception occurred.\n";
	}
}
