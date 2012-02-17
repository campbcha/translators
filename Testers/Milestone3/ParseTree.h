#ifndef ParseTree_H
#define ParseTree_H

#include <stdlib.h>
#include <time.h>

#include "../../Exception.h"
#include "ParseNodes.h"

class ParseTree {
public:
	ParseTree();

	void print();

private:
	ParseNode* rootNode;
};

#endif // ParseTree_H
