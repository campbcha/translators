#ifndef TokenBoolean_H
#define TokenBoolean_H

#include <iostream>

#include "Token.h"

/** Token class representing an instance of a boolean value in the input code.
 */
class TokenBoolean : public Token {
public:
	/** Construct a new TokenBoolean object with specified boolean value.
	 */
	TokenBoolean(bool value);

	/** Returns the boolean value of the TokenBoolean object.
	 *  @return	The value attribute of the TokenBoolean object.
	 */
	bool getValue();

	/** Prints information about this object instance to cout for debugging purposes.
	 */
	void print();

private:
	// A boolean representing the value of a boolean in the input code.
	bool value;
};

#endif //TokenBoolean_H
