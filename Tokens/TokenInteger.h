#ifndef TokenInteger_H
#define TokenInteger_H

#include <cstdlib>
#include <iostream>

#include "Token.h"

/** Token class representing an instance of an integer value in the input code.
 */
class TokenInteger : public Token {
public:
	/** Construct a new TokenInteger object with the specified integer value.
	 */
	TokenInteger(int value);

	/** Returns the integer value of the TokenInteger object.
	 *  @return	The value attribute of the TokenInteger object.
	 */
	int getValue();

	/** Print information about this object instance to cout for debugging purposes.
	 */
	void print();

private:
	// An integer representing the value of an integer in the input code.
	int value;
};

#endif //TokenInteger_H
