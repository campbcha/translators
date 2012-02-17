#ifndef Nonterminal_H
#define Nonterminal_H

#include <iostream>

#include "../ParseNode.h"

#include "../../../Exception.h"

class Nonterminal : public ParseNode {
public:
	Nonterminal();

	virtual void print(int depth) = 0;
};

#endif
