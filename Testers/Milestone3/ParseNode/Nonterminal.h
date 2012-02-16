#ifndef Nonterminal_H
#define Nonterminal_H

#include "../ParseNode.h"

#include "../../../Exception.h"

class Nonterminal : public ParseNode {
public:
	Nonterminal();

	virtual void print() = 0;
};

#endif
