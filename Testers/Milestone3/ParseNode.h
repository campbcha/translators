#ifndef ParseNode_H
#define ParseNode_H

#include <stdlib.h>

#include <iostream>
#include <list>

#include "../../Exception.h"
#include "../../Ibtl/Ibtl.h"

class ParseNode {
public: 
	ParseNode();

	virtual void print() = 0;
protected:
	std::list<ParseNode*> parseNodes;
};

#endif
