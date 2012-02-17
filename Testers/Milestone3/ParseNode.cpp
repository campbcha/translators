#include "ParseNode.h"


ParseNode::ParseNode() {
	//const char* function_name = "ParseNode::ParseNode()";

	//std::cerr << function_name << "\n";
}


void ParseNode::print() {
	std::list<ParseNode*>::iterator parseNodeIterator;

	// Initialize the iterator.
	parseNodeIterator = parseNodes.begin();

	// Print each ParseNode recursively.
	while ( parseNodeIterator != parseNodes.end() ) {
		// Call print function.
		(*parseNodeIterator)->print();

		// Increment the iterator.
		parseNodeIterator++;
	}
}
