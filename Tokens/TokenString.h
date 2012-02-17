#ifndef TokenString_H
#define TokenString_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "Token.h"

/** Token class representing an instance of a string value in the input code.
 */
class TokenString : public Token {
public:
	/** Construct a new TokenString object with the specified string object.
	 */
	TokenString(std::string* value);

	/** Returns the string object of the TokenString object.
	 *  @return	The value attribute of the TokenString object.
	 */
	const std::string* getValue();

	/** Prints information about this object to cout for debugging purposes.
	 */
	void print();

	/** Writes the value of the string to the specified output stream.
	 */
	virtual void writeLexeme(std::ostream& ostream);

private:
	// A string object representing the value of a string in the input code.
	std::string* value;
};

#endif //TokenString_H
