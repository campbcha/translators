#ifndef ParseTree_H
#define ParseTree_H

#include <stdlib.h>
#include <time.h>

#include "../../Exception.h"
#include "ParseNodes.h"

class ParseTree {
public:
	/** Create a new randomly-generated parse tree.
	 */
	ParseTree();

	/** Print the tree to std::cout for debugging purposes.
	 */
	void print();

	/** Write the lexemes to the specified ostream.
	 */
	void writeLexeme(std::ostream& ostream);
private:
	// The root node of the parse tree.
	ParseNode* rootNode;
};

#endif // ParseTree_H
