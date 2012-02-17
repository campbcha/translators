#ifndef S_H
#define S_H

#include "../Nonterminals.h"

#include "../../../../Exception.h"
#include "../../../../Tokens/Tokens.h"

class S : public Nonterminal {
public:
	S();

	virtual void print(int depth);

	virtual void writeLexeme(std::ostream& ostream);
};

#endif // S_H
