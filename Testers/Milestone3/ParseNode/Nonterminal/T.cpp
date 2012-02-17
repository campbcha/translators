#include "T.h"


T::T() {
	//const char* function_name = "T::T()";

	// Push grammar production onto the node.
	parseNodes.push_back(new Terminal(PARENTHESIS_OPEN));
	parseNodes.push_back(new S());
	parseNodes.push_back(new Terminal(PARENTHESIS_CLOSE));
}


void T::print() {
	//const char* function_name = "T::print()";
	
	// Print each child node.
	ParseNode::print();

	// Print this node.
	std::cout << " T ";
}
