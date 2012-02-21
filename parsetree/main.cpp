#include <iostream>
#include "../lexer/lexer.h"
#include "../lexer/token.h"
#include "syntaxtree.h"

using namespace std;

void printToken(Token* tok);

// This is an example how to use the SyntaxTree to add stuff and then
// print it out.
int main() {
    Lexer lexer("test.ibtl");
    SyntaxTree tree;

    Token* curToken;
    while(curToken = lexer.scan()) {
        if(curToken->getTag() == TAG_OPENPAREN) {
            tree.startExpression();
            tree.addTerminal(curToken);
        }
        else if(curToken->getTag() == TAG_CLOSEPAREN) {
            tree.addTerminal(curToken);
            tree.endExpression();
        }
        else {
            tree.addTerminal(curToken);
        }
    }

    TreeIterator iter(&tree);
    while(curToken = iter.getPreorder()) {
        for(int i=0; i<iter.getCurrentLevel(); i++) cout << "\t";
        printToken(curToken);
    }

    return 0;
}

void printToken(Token* tok) {
    cout << "Line " << tok->getLine() << ": " << tok->toString() << endl;
}
