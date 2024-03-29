#include "ParseNode.h"


ParseNode::ParseNode() {
	//const char* function_name = "ParseNode::ParseNode()";

	//std::cerr << function_name << "\n";
}


void ParseNode::print(int depth) {
	std::list<ParseNode*>::iterator parseNodeIterator;

	// Initialize the iterator.
	parseNodeIterator = parseNodes.begin();

	// Print each ParseNode recursively.
	while ( parseNodeIterator != parseNodes.end() ) {
		// Call print function.
		(*parseNodeIterator)->print(depth);

		// Increment the iterator.
		parseNodeIterator++;
	}
}


void ParseNode::printLatex(std::ostream& ostream) {
	std::list<ParseNode*>::iterator parseNodeIterator;

	// Initialize the iterator.
	parseNodeIterator = parseNodes.begin();

	// Print each ParseNode recursively.
	while ( parseNodeIterator != parseNodes.end() ) {
		// Call print function.
		(*parseNodeIterator)->printLatex(ostream);

		// Increment the iterator.
		parseNodeIterator++;
	}
}


void ParseNode::printLexeme(std::ostream& ostream) {
	std::list<ParseNode*>::iterator parseNodeIterator;

	// Initialize the iterator.
	parseNodeIterator = parseNodes.begin();

	// Print each ParseNode recursively.
	while ( parseNodeIterator != parseNodes.end() ) {
		// Call print function.
		(*parseNodeIterator)->printLexeme(ostream);

		// Increment the iterator.
		parseNodeIterator++;
	}
}

