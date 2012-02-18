#ifndef TokenReal_H
#define TokenReal_H

#include <cstdlib>
#include <iostream>

#include "Token.h"

/** Token class representing an instance of an real number value in the input code. The real number value is converted into a double-precision floating-point number.
 */
class TokenReal : public Token {
public:
	/** Construct a new TokenReal object with the specified double value.
	 */
	TokenReal(double value);

	/** Returns the double value of the TokenReal object.
	 *  @return	The value attribute of the TokenReal object.
	 */
	double getValue();

	/** Prints information abouts this object instance to cout for debugging purposes.
	 */
	void print();

	/** Write the double value of the token to the specified ostream.
	 */
	virtual void printLexeme(std::ostream& ostream);

private:
	// A double representing the value of a real number in the input code.
	double value;
};

#endif //TokenReal_H
