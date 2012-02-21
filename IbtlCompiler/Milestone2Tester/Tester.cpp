#include "Tester.h"


Tester::Tester() {
	// Seed random number generator
	srand(time(NULL));
}

void Tester::run(Lexer* testLexer, VerboseType vType) {
	std::list<int>::iterator tagIterator;
	std::list<std::string>::iterator stringIterator;
	int tagVal;
	int lexerTagVal;
	std::string stringVal;
	Token* lexerToken;
	TokenBoolean* lexerBoolToken;
	TokenInteger* lexerIntToken;
	TokenReal* lexerRealToken;
	TokenString* lexerStringToken;

	tagIterator = tagList.begin();
	stringIterator = stringList.begin();
	while ( tagIterator != tagList.end() ) {
		try {
			tagVal = *tagIterator;
			stringVal = *stringIterator;

			// Get token from lexer
			lexerToken = testLexer->scan();
			lexerTagVal = lexerToken->getTag();

			// Compare token tags
			if ( tagVal != lexerTagVal ) {
				if ( vType != NONE ) {
					std::cout << "TOKEN TAG MISMATCH - Expected: ";

					if ( tagVal != VALUE_BOOLEAN &&
						 tagVal != VALUE_INTEGER &&
						 tagVal != VALUE_REAL    &&
						 tagVal != VALUE_STRING ) {
						std::cout << stringVal << " -- Actual: " << lexerToken->getTagString() << std::endl;
					} else {
						if ( tagVal == VALUE_BOOLEAN ) {
							std::cout << "boolValue" << " (" << stringVal << ") -- Actual: " << lexerToken->getTagString() << " (";
						} else if ( tagVal == VALUE_INTEGER ) {
							std::cout << "intValue" << " (" << stringVal << ") -- Actual: " << lexerToken->getTagString() << " (";
						} else if ( tagVal == VALUE_REAL ) {
							std::cout << "realValue" << " (" << stringVal << ") -- Actual: " << lexerToken->getTagString() << " (";
						} else if ( tagVal == VALUE_STRING ) {
							std::cout << "stringValue" << " (" << stringVal << ") -- Actual: " << lexerToken->getTagString() << " (";
						}

						if ( lexerTagVal == VALUE_BOOLEAN ) {
							lexerBoolToken = (TokenBoolean*) lexerToken;
							std::cout << lexerBoolToken->getValue();
						} else if ( lexerTagVal == VALUE_INTEGER ) {
							lexerIntToken = (TokenInteger*) lexerToken;
							std::cout << lexerIntToken->getValue();
						} else if ( lexerTagVal == VALUE_REAL ) {
							lexerRealToken = (TokenReal*) lexerToken;
							std::cout << lexerRealToken->getValue();
						} else if ( lexerTagVal == VALUE_STRING ) {
							lexerStringToken = (TokenString*) lexerToken;
							std::cout << *lexerStringToken->getValue();
						}

						std::cout <<  ")" << std::endl;
					}
				}
				return;
			} else {
				if ( vType == ALL ) {
					if ( tagVal != VALUE_BOOLEAN &&
						 tagVal != VALUE_INTEGER &&
						 tagVal != VALUE_REAL    &&
						 tagVal != VALUE_STRING ) {
						std::cout << "TOKEN MATCH: " << stringVal << std::endl;
					}
				}
			}

			// Check value matches
			if ( tagVal == VALUE_BOOLEAN ) {
				lexerBoolToken = (TokenBoolean*) lexerToken;

				if ( stringVal.compare("true") == 0 ) {
					if ( lexerBoolToken->getValue() == true ) {
						if ( vType == ALL ) {
							std::cout << "TOKEN MATCH: " << lexerBoolToken->getTagString() << " (" << lexerBoolToken->getValue() << ")" << std::endl;
						}
					} else {
						if ( vType != NONE ) {
							std::cout << "BOOL VALUE MISMATCH - Expected: 1 -- Actual: " << lexerBoolToken->getValue() << std::endl;
							return;
						}
					}
				} else if ( stringVal.compare("false") == 0 ) {
					if ( lexerBoolToken->getValue() == false ) {
						if ( vType == ALL ) {
							std::cout << "TOKEN MATCH: " << lexerBoolToken->getTagString() << " (" << lexerBoolToken->getValue() << ")" << std::endl;
						}
					} else {
						if ( vType != NONE ) {
							std::cout << "BOOL VALUE MISMATCH - Expected: 0 -- Actual: " << lexerBoolToken->getValue() << std::endl;
							return;
						}
					}
				}
			} else if ( tagVal == VALUE_INTEGER ) {
				lexerIntToken = (TokenInteger*) lexerToken;

				int expectedInt = atoi(stringVal.c_str());
				if ( expectedInt == lexerIntToken->getValue() ) {
					if ( vType == ALL ) {
						std::cout << "TOKEN MATCH: " << lexerIntToken->getTagString() << " (" << lexerIntToken->getValue() << ")" << std::endl;
					}
				} else {
					if ( vType != NONE ) {
						std::cout << "INT VALUE MISMATCH - Expected: " << expectedInt << " -- Actual: " << lexerIntToken->getValue() << std::endl;
						return;
					}
				}
			} else if ( tagVal == VALUE_REAL ) {
				lexerRealToken = (TokenReal*) lexerToken;

				double expectedReal = atof(stringVal.c_str());
				if ( expectedReal == lexerRealToken->getValue() ) {
					if ( vType == ALL ) {
						std::cout << "TOKEN MATCH: " << lexerRealToken->getTagString() << " (" << lexerRealToken->getValue() << ")" << std::endl;
					}
				} else {
					if ( vType != NONE ) {
						std::cout << "REAL VALUE MISMATCH - Expected: " << expectedReal << " -- Actual: " << lexerRealToken->getValue() << std::endl;
						return;
					}
				}
			} else if ( tagVal == VALUE_STRING ) {
				lexerStringToken = (TokenString*) lexerToken;

				if ( stringVal.compare(lexerStringToken->getValue()->c_str()) == 0 ) {
					if ( vType == ALL ) {
						std::cout << "TOKEN MATCH: " << lexerStringToken->getTagString() << " (" << *lexerStringToken->getValue() << ")" << std::endl;
					}
				} else {
					if ( vType != NONE ) {
						std::cout << "STRING VALUE MISMATCH - Expected: " << stringVal << " -- Actual: " << *lexerStringToken->getValue() << std::endl;
						return;
					}
				}
			}

		} catch ( Exception* e ) {
			if ( vType != NONE ) {
				std::cout << "!!EXCEPTION THROWN!! (" << *e->getMessage() << ") on lexeme: " << stringVal << std::endl;
				return;
			}
		}

		tagIterator++;
		stringIterator++;
	}
}


void Tester::generateTestFile(std::string testFileName) {
	// Generate number of lexemes to use in file
	int numLexemes = rand() % (MAX_LEXEMES + 1);
	std::ofstream testFile;

	// Create test file stream
	testFile.open(testFileName.c_str());
	if ( testFile.is_open() == false ) {
		throw new Exception("Unable to open file to write");
	}

	// Generate file of lexemes
	for ( int i = 0; i < numLexemes; i++ ){
		int lexemeType = rand() % TAG_MAX;
		std::string lexemeStr;

		//generate type of lexeme
		switch ( lexemeType ) {
		case FUNCTION_COSINE:
			lexemeStr = "cos";
			break;
		case FUNCTION_LOGARITHM:
			lexemeStr = "logn";
			break;
		case FUNCTION_PRINTLN:
			lexemeStr = "println";
			break;
		case FUNCTION_SINE:
			lexemeStr = "sin";
			break;
		case FUNCTION_TANGENT:
			lexemeStr = "tan";
			break;
		case OPERATOR_ADDITION:
			lexemeStr = "+";
			break;
		case OPERATOR_AND:
			lexemeStr = "and";
			break;
		case OPERATOR_DIVISION:
			lexemeStr = "/";
			break;
		case OPERATOR_EQUALITY:
			lexemeStr = "=";
			break;
		case OPERATOR_EXPONENTIATION:
			lexemeStr = "^";
			break;
		case OPERATOR_LESS_THAN:
			lexemeStr = "<";
			break;
		case OPERATOR_MODULUS:
			lexemeStr = "%";
			break;
		case OPERATOR_MULTIPLICATION:
			lexemeStr = "*";
			break;
		case OPERATOR_NOT:
			lexemeStr = "not";
			break;
		case OPERATOR_OR:
			lexemeStr = "or";
			break;
		case OPERATOR_SUBTRACTION:
			lexemeStr = "-";
			break;
		case PARENTHESIS_CLOSE:
			lexemeStr = ")";
			break;
		case PARENTHESIS_OPEN:
			lexemeStr = "(";
			break;
		case STATEMENT_ASSIGN:
			lexemeStr = "assign";
			break;
		case STATEMENT_IF:
			lexemeStr = "if";
			break;
		case STATEMENT_IFF:
			lexemeStr = "iff";
			break;
		case STATEMENT_LET:
			lexemeStr = "let";
			break;
		case STATEMENT_WHILE:
			lexemeStr = "while";
			break;
		case TYPE_BOOLEAN:
			lexemeStr = "bool";
			break;
		case TYPE_INTEGER:
			lexemeStr = "int";
			break;
		case TYPE_REAL:
			lexemeStr = "real";
			break;
		case TYPE_STRING:
			lexemeStr = "string";
			break;
		case VALUE_BOOLEAN:
			lexemeStr = generateBoolean();
			break;
		case VALUE_INTEGER:
			lexemeStr = generateInteger();
			break;
		case VALUE_REAL:
			lexemeStr = generateReal();
			break;
		case VALUE_STRING:
			lexemeStr = generateString();
			break;
		default:
			lexemeStr = "ERROR";
			break;
		}

		testFile << lexemeStr;
		testFile << generateWhiteSpace();

		tagList.push_back(lexemeType);
		stringList.push_back(lexemeStr);
	}
	
	testFile.close();
}


std::string Tester::generateBoolean() {
	int boolValue = rand() % 2;

	if ( boolValue == 0 ) {
		return "true";
	} else {
		return "false";
	}
}


std::string Tester::generateInteger() {
	int intSymbol = rand() % 3;
	std::stringstream out;

	// Add +, -, or nothing to stringstream
	if ( intSymbol == 0 ) {
		out << "+";
	} else if ( intSymbol == 1 ) {
		out << "-";
	}

	// Add random integer to stringstream
	out << randInt();

	return out.str();
}


std::string Tester::generateReal() {
	int randVal; // randVal is used whenever anything needs to be randomly generated
	std::stringstream out;
	std::string returnString;
	double checkVal;

	// Redo target if generated real is out of bounds
redo:

	// Add +, -, or nothing to stringstream
	randVal = rand() % 3;
	if ( randVal == 0 ) {
		out << "+";
	} else if ( randVal == 1 ) {
		out << "-";
	}
	
	// Add number to stringstream
	out << randInt();
	
	// Add . or e to stringstream
	randVal = rand() % 2;
	if ( randVal == 0 ) {
		out << ".";

		// If . added, add number or <> to stringstream
		randVal = rand() % 2;
		if ( randVal == 0 ) {
			out << randInt();
		}

		// if . added, add e or <> to stringstream
		randVal = rand() % 2;
		if ( randVal == 0 ) {
			out << "e";

			// Add +, -, or nothing to stringstream
			randVal = rand() % 3;
			if ( randVal == 0 ) {
				out << "+";
			} else if ( randVal == 1 ) {
				out << "-";
			}

			out << randInt();
		}
	} else {
		out << "e";

		// Add +, -, or nothing to stringstream
		randVal = rand() % 3;
		if ( randVal == 0 ) {
			out << "+";
		} else if ( randVal == 1 ) {
			out << "-";
		}

		out << randInt();
	}

	returnString = out.str();
	checkVal = atof(returnString.c_str());
	if ( checkVal == 0 || checkVal == HUGE_VAL || checkVal == -HUGE_VAL) {
		out.str("");
		goto redo;
	}
	return returnString;
}


std::string Tester::generateString() {
	std::stringstream out;
	int stringLength = rand() % MAX_STRING_LENGTH + 1;
	char stringAlphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
	for ( int i = 0; i < stringLength; i++ ) {
		// No numbers for first character
		if ( i == 0 ) {
			out << stringAlphabet[rand() % (sizeof(stringAlphabet) - 1 - 10)];
		} else {
			out << stringAlphabet[rand() % (sizeof(stringAlphabet) - 1)];
		}
	}

	// Check if return string is a keyword!

	return out.str();
}


std::string Tester::generateWhiteSpace() {
	int whiteSpaceCount = rand() % MAX_WHITE_SPACE + 1;
	int whiteSpaceType = INIT_VAL;
	std::stringstream out;

	for ( int i = 0; i < whiteSpaceCount; i++ ) {
		whiteSpaceType = rand() % 3;
		if ( whiteSpaceType == 0 ) {
			out << " ";
		}
		else if ( whiteSpaceType == 1 ) {
			out << "\t";
		}
		else {
			out << std::endl;
		}
	}

	return out.str();
}


int Tester::randInt() {
	return rand() % INT_MAX;
}

