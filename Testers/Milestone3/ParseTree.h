#ifndef ParseTree_H
#define ParseTree_H

#include "../../Exception.h"
#include "ParseNode.h"

class ParseTree {
public:
	ParseTree();

	void print();

private:
	ParseNode* rootNode;
};

#endif // ParseTree_H
