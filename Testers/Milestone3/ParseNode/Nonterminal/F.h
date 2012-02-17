#ifndef F_H
#define F_H

#include <iostream>

#include "../../ParseNodes.h"

#include "../../../../Exception.h"

class F : public Nonterminal {
public:
	F();

	virtual void print();
};

#endif // F_H
