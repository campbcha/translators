#ifndef Terminal_H
#define Terminal_H

#include <limits.h>

#include "../ParseNode.h"

#include "../../../Exception.h"
#include "../../../Tokens/Tokens.h"

class Terminal : public ParseNode {
public:
	Terminal(Tag tag);

	void print();
private:
	Token* token;
};

#endif
