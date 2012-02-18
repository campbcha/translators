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


void ParseTree::printLexeme(std::ostream& ostream) {
	const char* function_name = "ParseTree::printLexeme()";

	// Validate preconditions.
	if ( rootNode == NULL ) {
		throw new Exception("Root node was NULL.", function_name);
	}
	
	// Write the parse tree recursively.
	rootNode->printLexeme(ostream);
	ostream << "\n";
}


void ParseTree::printLatex(std::ostream& ostream) {
	//const char* functionName = "ParseTree::printLatex()";

	// Print beginning header data and the head node.
	std::cout << "\\begin{figure}[h] \\center \\pstree[nodesep=2pt,levelsep=25px]{\\TR{Begin}} {";

	// Print to the ostream recursively.
	rootNode->printLatex(ostream);

	// End the head node and header data.
	std::cout << "} \\end{figure}";
}
