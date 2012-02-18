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

	virtual void print(int depth = 0) = 0;

	virtual void printLexeme(std::ostream& ostream) = 0;

	virtual void printLatex(std::ostream& ostream) = 0;
protected:
	std::list<ParseNode*> parseNodes;
};

#endif
