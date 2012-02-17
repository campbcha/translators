#ifndef F_H
#define F_H

#include <iostream>

#include "../../ParseNodes.h"

#include "../../../../Exception.h"

class F : public Nonterminal {
public:
	F();

	virtual void print(int depth);

	virtual void writeLexeme(std::ostream& ostream);
};

#endif // F_H
