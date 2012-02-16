#ifndef Terminal_H
#define Terminal_H

#include "../ParseNode.h"

#include "../../../Exception.h"
#include "../../../Tokens/Tokens.h"

class Terminal : public ParseNode {
public:
	Terminal(Token* token);

	void print();
private:
	Token* token;
};

#endif
