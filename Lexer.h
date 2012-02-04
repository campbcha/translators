/** A lexical analyzer for the Itty Bitty Teaching Language (IBTL).
 */

#ifndef Lexer_H
#define Lexer_H

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

#include "Exception.h"
#include "Tokens/Tokens.h"

/** Lexer class that scans an input file and produces output tokens for the parser.
 */
class Lexer {
public:
	/** Instantiate a new Lexer object that opens and reads input from the specified filepath.
	 */
	Lexer(std::ifstream* sourceFile);

	/** Closes the file object associated with the Lexer.
	 */
	~Lexer();

	/** Scan the source code file and return an object of type Token or its derived classes, or return NULL if no Tokens are left in the file.
	 *  @throw	Exception object if an I/O or syntax error occurrs.
	 *  @return	An object of type Token representing the next lexeme in the source code file, or NULL if no lexems are left.
	 */
	Token* scan();

private:
	// The source code file from which input is read and tokens are produced from.
	std::ifstream* sourceFile;

	/** Compare the specified string object to a keyword within the IBTL. If the strings match, return the Token associated with that keyword; if the strings do not match, return NULL.
	 *  @return	The Token associated with the keyword and the specified string, or NULL if no keyword matches the string.
	 */
	Token* compareKeyword(std::string* stringValue);

	/** Read a character in from the source code file and return the character after the character just read-in.
	 *  @return	The character after the last read-in character in the source code file.
	 */
	char readCharacter();

	/** Try to match the next special (in this case backslash-escaped) character (ex: '\n'). If the special character is found, return the special character as itself (as contrasted to the multiple character read-in from input) and increment the source code file stream appropriately. If no corresponding special character is found, throw an Exception object.
 	 *  @return	The special character associated with the backslash-escape sequence.
 	 */
	char matchCharacterSpecial();

	/** Try to match the next non-whitespace characters in the file to an expression. If an expression is found, read-in the file stream appropriately and return the Token associated with the read-in expression; if an expression is not found, return NULL.
	 *  @return	The Token associated with the expression, or NULL if an expression was not found.
	 */
	Token* matchExpression();

	/** Try to match the next non-whitespace characters in the file to an integer or real number by reading in the file stream. If an integer or real number is found, return the appropriate token type; if an integer or real number if not found, return NULL and throw an exception is a partial match was made.
	 *  @return	The Token associated with the integer or real number, or NULL if an integer or real number was not found.
	 */
	Token* matchIntegerOrReal();

	/** Try to match the decimal portion of a real number given the specified integer value of the real number; may call matchRealExponent() if an exponent portion of the code is found. If a real number is read-in, the source code stream is incremented appropriately. If a valid real number is not found, an Exception is thrown.
	 *  @return	The Token associated with the real number. (Note that a NULL return is not possible, but an Exception may be thrown.)
	 */
	Token* matchRealDecimal(int integerValue);

	/** Try to match the exponent portion of a real number given the specified integer and decimal values of the real number. If the exponent is successfully read-in, the source code stream in incremented appropriately. If a valid exponent is not found, an Exception object is thrown.
	 *  @return	The Token associated with the real number. (Note that a NULL return is not possible, but an Exception may be thrown.)
	 */
	// Assumes that the decimal value is 0.
	Token* matchRealExponent(int integerValue);
	// Multiplies the specified double to a read-in exponent.
	Token* matchRealExponent(double baseValue);

	/** Try to match the next non-whitespace characters in the file to a keyword or non-delimited string by reading in the source code file stream. If a string is read-in, that string is then matched against a set of keyword values and, if the string matches the keyword, the appropriate Token associated with that keyword is returned, otherwise, if the string does not match the keyword, the appropriate token associated with the string literal is returned. If a string is not found, NULL is returned.
	 *  @return	The Token associated with the keyword or string, or NULL if a keyword or string is not found. 
	 */
	Token* matchKeywordOrStringNonDelimited();

	/** Try to match the next non-whitespace characters in the file to a string delimited by either single or double quotes. If a string begins with a double quote, single quotes will be returned in the resulting string, and vice-versa for strings beginning with a single quote. If a string is successfully read-in, a TokenString containing the read-in characters between the delimiters is returned; if a string is not successfully read-in because a closing delimiter is not found, an Exception is thrown. If the next non-whitespace character does not beging a delimited string, NULL is returned.
	 *  @return	The Token associated with the delimited string, or NULL if the a delimited string is not found.
	 */
	Token* matchStringDelimited();

	/** Read-in all whitespace data from the source code file, discading it. When a non-whitespace character is found the function returns void, leaving the aforementioned non-whitespace character to be readable via the peek() function call.
	 */
	void skipWhitespace();
};

#endif // Lexer_H
