/** A symbol object for the symbol table.
 */

#ifndef Symbol_H
#define Symbol_H

#include <string>

#include "../../Tokens/Tokens.h"
#include "../../Exception.h"

/** Symbol class that represents a single identifier in a scope in the symbol table.
 */
class Symbol {
public:
	/** Instantiate a new Symbol object that stores the given type for this scope.
	 */
	Symbol(TokenType type);

	/** Deconstructs the Symbol
	 */
	~Symbol();

	/** getType returns the Symbol's type.
	 *  @return	An value from the TokenType enumeration defined in Tokens.h.
	 */
	TokenType getType();

	/** setIntegerValue sets a integer symbol's token's value
	 * @throw Exception if trying to set symbol's value to an invalid type
	 */
	void setIntegerValue(int val);

	/** setRealValue sets a real symbol's token's value
	 * @throw Exception if trying to set symbol's value to an invalid type
	 */
	void setRealValue(double val);

	/** setBooleanValue sets a boolean symbol's token's value
	 * @throw Exception if trying to set symbol's value to an invalid type
	 */
	void setBooleanValue(bool val);

	/** setStringValue sets a string symbol's token's value
	 * @throw Exception if trying to set symbol's value to an invalid type
	 */
	void setStringValue(std::string val);

	/** getIntegerValue gets a integer symbol's token's value
	 * @throw Exception if trying to get symbol's value to an invalid type or no value exists
	 * @return Integer value of symbol's token
	 */
	int getIntegerValue();

	/** getRealValue gets a real symbol's token's value
	 * @throw Exception if trying to get symbol's value to an invalid type or no value exists
	 * @return Real value of symbol's token
	 */
	double getRealValue();

	/** getBooleanValue gets a boolean symbol's token's value
	 * @throw Exception if trying to get symbol's value to an invalid type or no value exists
	 * @return Boolean value of symbol's token
	 */
	bool getBooleanValue();

	/** getStringValue gets a string symbol's token's value
	 * @throw Exception if trying to get symbol's value to an invalid type or no value exists
	 * @return Pointer to string value of symbol's token
	 */
	std::string getStringValue();

private:
	TokenType symbolType;
	Token* symbolToken;
};

#endif // Symbol_H
