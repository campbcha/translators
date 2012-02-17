#include "T.h"


T::T() {
	//const char* function_name = "T::T()";

	// Push grammar production onto the node.
	parseNodes.push_back(new Terminal(new Token(PARENTHESIS_OPEN)));
	parseNodes.push_back(new S());
	parseNodes.push_back(new Terminal(new Token(PARENTHESIS_CLOSE)));
}


void T::print(int depth) {
	//const char* function_name = "T::print()";
	
	// Print this node.
	for (int i = 0; i < depth; i++ ) {
		std::cout << " ";
	}
	std::cout << "T" << "\n";

	// Print each child node.
	ParseNode::print(depth);
}


void T::writeLexeme(std::ostream& ostream) {
	// Write child nodes.
	ParseNode::writeLexeme(ostream);
}

