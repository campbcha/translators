/** A symbol table to store identifiers and their values for one scope.
 */

#ifndef SymbolTable_H
#define SymbolTable_H

#include <string>
#include <map>

#include "../../Tokens/Tokens.h"
#include "../../Exception.h"
#include "Symbol.h"

/** Symbol table class to store identifiers and their values for one scope.
 */
class SymbolTable {
public:
	/** Instantiate a new SymbolTable object.
	 *  Set the previous to NULL if the symbol table is the the top scope.
	 */
	SymbolTable(SymbolTable* prev);

	/** Deconstructs the SymbolTable
	 */
	~SymbolTable();

	/** Declares the identifier for the current symbol table.
	 *  @throw Exception if the identifier is already taken.
	 */
	void declareIdentifier(std::string identifier, TokenType type);

	void setIntegerValue(std::string identifier, int val);

	void setRealValue(std::string identifier, double val);

	void setBooleanValue(std::string identifier, bool val);

	void setStringValue(std::string identifier, std::string val);

	TokenType getIdentifierType(std::string identifier);

	int getIntegerValue(std::string identifier);

	double getRealValue(std::string identifier);

	bool getBooleanValue(std::string identifier);

	std::string getStringValue(std::string identifier);

	/** Prints the map to std::cout.  For debugging purposes only.
	 */
	void printMap();
private:
	SymbolTable* prev;
	std::map<std::string, Symbol> symbolMap;

	/** Returns the first symbol found for the given identifier.
	 *  @throw Exception if identifier wasn't found
	 */
	Symbol* getSymbol(std::string identifier);
};

#endif // SymbolTable_H
