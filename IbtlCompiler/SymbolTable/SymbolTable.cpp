#include "SymbolTable.h"

SymbolTable::SymbolTable(SymbolTable* prev) : prev(prev) {
	; // Do nothing
}

SymbolTable::~SymbolTable() {
	// Delete Symbols

	; // Do nothing
}



void SymbolTable::declareIdentifier(std::string identifier, TokenType type) {
	Symbol* tempSymbol = new Symbol(type);
	if ( symbolMap.insert(std::map<std::string, Symbol>::value_type(identifier, *tempSymbol)).second == FALSE) {
		throw new Exception ("Identifier Already Exists", "declareIdentifier");
	}
}

void SymbolTable::setIntegerValue(std::string identifier, int val) {
	Symbol* tempSymbol = getSymbol(identifier);
	
	if ( tempSymbol->getType() != TOKEN_INTEGER ) {
		throw new Exception("Invalid Type", "setIntegerValue");
	}

	tempSymbol->setIntegerValue(val);
}

void SymbolTable::setRealValue(std::string identifier, double val) {
	Symbol* tempSymbol = getSymbol(identifier);
	
	if ( tempSymbol->getType() != TOKEN_REAL ) {
		throw new Exception("Invalid Type", "setRealValue");
	}

	tempSymbol->setRealValue(val);
}

void SymbolTable::setBooleanValue(std::string identifier, bool val) {
	Symbol* tempSymbol = getSymbol(identifier);
	
	if ( tempSymbol->getType() != TOKEN_BOOLEAN ) {
		throw new Exception("Invalid Type", "setBooleanValue");
	}

	tempSymbol->setBooleanValue(val);
}

void SymbolTable::setStringValue(std::string identifier, std::string val) {
	Symbol* tempSymbol = getSymbol(identifier);
	
	if ( tempSymbol->getType() != TOKEN_STRING ) {
		throw new Exception("Invalid Type", "setStringValue");
	}

	tempSymbol->setStringValue(val);
}

TokenType SymbolTable::getIdentifierType(std::string identifier) {
	return getSymbol(identifier)->getType();
}

int SymbolTable::getIntegerValue(std::string identifier) {
	Symbol* tempSymbol = getSymbol(identifier);

	if ( tempSymbol->getType() != TOKEN_INTEGER ) {
		throw new Exception("Invalid Type", "getIntegerValue");
	}

	return tempSymbol->getIntegerValue();
}

double SymbolTable::getRealValue(std::string identifier) {
	Symbol* tempSymbol = getSymbol(identifier);

	if ( tempSymbol->getType() != TOKEN_REAL ) {
		throw new Exception("Invalid Type", "getRealValue");
	}

	return tempSymbol->getRealValue();
}

bool SymbolTable::getBooleanValue(std::string identifier) {
	Symbol* tempSymbol = getSymbol(identifier);

	if ( tempSymbol->getType() != TOKEN_BOOLEAN ) {
		throw new Exception("Invalid Type", "getBooleanValue");
	}

	return tempSymbol->getBooleanValue();
}

std::string SymbolTable::getStringValue(std::string identifier) {
	Symbol* tempSymbol = getSymbol(identifier);

	if ( tempSymbol->getType() != TOKEN_STRING ) {
		throw new Exception("Invalid Type", "getStringValue");
	}

	return tempSymbol->getStringValue();
}

Symbol* SymbolTable::getSymbol(std::string identifier) {
	for ( SymbolTable* i = this; i != NULL; i = i->prev ) {
		std::map<std::string, Symbol>::iterator symbolIterator = i->symbolMap.find(identifier);
		if ( symbolIterator != i->symbolMap.end() ) {
			return &symbolIterator->second;
		} else if ( symbolIterator == symbolMap.end() && i->prev != NULL ) {
			continue;
		}
	}

	throw new Exception("Identifier not found", "getSymbol");
}

void SymbolTable::printMap() {
	for ( SymbolTable* i = this; i != NULL; i = i->prev ) {
		std::cout << "Symbol Table " << i << std::endl;
		for (std::map<std::string, Symbol>::iterator it=i->symbolMap.begin() ; it != i->symbolMap.end(); it++ ) {
			std::cout << it->first << " => ";

			switch (it->second.getType()) {
			case TOKEN:
				std::cout << "ERROR: Type Token";
				break;
			case TOKEN_INTEGER:
				try {
					std::cout << it->second.getIntegerValue();
				} catch (Exception* e) {
					e->print();
				}
				break;
			case TOKEN_REAL:
				try {
					std::cout << it->second.getRealValue();
				} catch (Exception* e) {
					e->print();
				}
				break;
			case TOKEN_BOOLEAN:
				try {
					std::cout << it->second.getBooleanValue();
				} catch (Exception* e) {
					e->print();
				}
				break;
			case TOKEN_STRING:
				try {
					std::cout << it->second.getStringValue();
				} catch (Exception* e) {
					e->print();
				}
				break;
			}
			
			std::cout << std::endl;
		}
	}
}