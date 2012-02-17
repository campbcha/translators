#ifndef T_H
#define T_H

#include "../Nonterminals.h"

#include "../../../../Exception.h"
#include "../../../../Tokens/Tokens.h"

class T : public Nonterminal {
public:
	T();

	virtual void print(int depth);

	virtual void writeLexeme(std::ostream& ostream);
};

#endif // T_H
