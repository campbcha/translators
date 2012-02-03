#ifndef Token_H
#define Token_H

#include <iostream>

/** Tokens to pass to the Lexical Analyzer
 */

/** Enumeration representing the various token types. Used by the lexical analyzer in order to determine how to retrieve data from the token.
 */
enum Tag {
	// Default functions.
	FUNCTION_COSINE,
	FUNCTION_LOGARITHM,
	FUNCTION_PRINTLN,
	FUNCTION_SINE,
	FUNCTION_TANGENT,
	// Expression operators.
	OPERATOR_ADDITION,
	OPERATOR_AND,
	OPERATOR_DIVISION,
	OPERATOR_EQUALITY,
	OPERATOR_EXPONENTIATION, 
	OPERATOR_LESS_THAN,
	OPERATOR_MODULUS,
	OPERATOR_MULTIPLICATION,
	OPERATOR_NOT,
	OPERATOR_OR,
	OPERATOR_SUBTRACTION,
	// Magical symbols.
	PARENTHESIS_CLOSE,
	PARENTHESIS_OPEN,
	// Control statements.
	STATEMENT_ASSIGN,
	STATEMENT_IF,
	STATEMENT_IFF,
	STATEMENT_LET,
	STATEMENT_WHILE,
	// Type defiitions.
	TYPE_BOOLEAN,
	TYPE_INTEGER,
	TYPE_REAL,
	TYPE_STRING,
	// Tokens containing data (which contain associated values from input code).
	VALUE_BOOLEAN,
	VALUE_INTEGER,
	VALUE_REAL,
	VALUE_STRING
};

/** Token class meant to be passed to the Parser.
 */
class Token {
public:
	Token() {}

	/** Construct a new Token object with specified Tag.
	 */
	Token(Tag tag);

	/** Returns the Tag type of the Token object.
	 *  @return	The tag attribute of the Token object.
	 */
	Tag getTag();

	/** Prints the Token data for debugging purposes.
	 */
	virtual void print();

protected:
	// Specifies the type of Token for parser reference.
	Tag tag;
};

#endif //Token_H
