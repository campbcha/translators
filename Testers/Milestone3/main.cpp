#include <iostream>

#include "ParseTree.h"
#include "ParseNodes.h"

int main( int argc, char* argv[] ) {

	try {
		// Create a new parse tree.
		ParseTree* parseTree = new ParseTree();

		// Print the parse tree.
		parseTree->printLatex(std::cout);

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
