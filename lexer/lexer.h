#ifndef Lexer_H
#define Lexer_H

#include <fstream>
#include "token.h"

/*
Lexical analyzer. This class takes a filename in the constructor
and opens and scans the file for lexemes. Every time you call scan(),
you will get a pointer to the next Token in the file. When there are
no more tokens, you will get NULL.
*/

class Lexer {
public:
    // Send in a filename when creating the object. Does not read from stdin.
    Lexer(std::string file);

    // Get the next lexeme as a pointer to a Token.
    Token* scan();

private:
    //private functions, see .cpp file for more info
    std::string getNextLexeme();
    Token* getInt(std::string);
    Token* getReal(std::string);
    Token* getStringLiteral(std::string);
    Token* getKeyword(std::string);
    Token* getIdentifier(std::string);

    bool isWhitespace (char c);

    std::ifstream input; // input stream from file
    int line;            // current line number
};

#endif
