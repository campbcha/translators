#ifndef Terminal_H
#define Terminal_H

#include <limits.h>

#include "../ParseNode.h"

#include "../../../Exception.h"
#include "../../../Tokens/Tokens.h"

class Terminal : public ParseNode {
public:
	Terminal(Token* token);

	virtual void print(int depth);

	virtual void printLatex(std::ostream& ostream);

	virtual void printLexeme(std::ostream& ostream);
private:
	Token* token;
};

#endif
