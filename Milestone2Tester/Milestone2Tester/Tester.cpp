#include "Tester.h"


Tester::Tester() {
	// Seed random number generator
	srand(time(NULL));
}

// NEED to accept Lexical analyzer
void Tester::run(Lexer* testLexer, VerboseType vType) {
	std::list<Token>::iterator tokenIterator;
	Token lexerToken;
	Token storedToken;

	std::cout << "------------ Lexer Tester -------------\n";
	std::cout << "CS480: campbcha, wadec, zoonb, piorkowd\n\n";
	if ( vType == ALL ) {
		std::cout << "PRINTING ALL MESSAGES\n\n";
	} else if ( vType == ERRORS ) {
		std::cout << "PRINTING ONLY ERRORS\n\n";
	} else if ( vType == NONE ) {
		std::cout << "PRINTING NO MESSAGES\n\n";
	} else {
		std::cout << "VERBOSE ERROR\n\n";
	}

	for ( tokenIterator = tokenList.begin(); tokenIterator != tokenList.end(); tokenIterator++ ) {
		try {
			storedToken = *tokenIterator;
			lexerToken = *testLexer->scan();

			// Compare tokens
			if ( storedToken.getTag() != lexerToken.getTag() ) {
				std::cout << "TOKEN TAG MISMATCH: " << storedToken.getTag() << " " << lexerToken.getTag() << "\n";
			} else {
				std::cout << "TOKEN MATCH: " << storedToken.getTag() << "\n";
			}
		} catch ( Exception* e ) {
			if ( vType != NONE ) {
				std::cout << "!!EXCEPTION THROWN!! " << *e->getMessage();
			}
		}
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
		Token tempToken;
		bool tempBool;

		//generate type of lexeme
		switch ( lexemeType ) {
		case FUNCTION_COSINE:
			lexemeStr = "cos";
			tempToken = Token(FUNCTION_COSINE);
			break;
		case FUNCTION_LOGARITHM:
			lexemeStr = "logn";
			tempToken = Token(FUNCTION_LOGARITHM);
			break;
		case FUNCTION_PRINTLN:
			lexemeStr = "println";
			tempToken = Token(FUNCTION_PRINTLN);
			break;
		case FUNCTION_SINE:
			lexemeStr = "sin";
			tempToken = Token(FUNCTION_SINE);
			break;
		case FUNCTION_TANGENT:
			lexemeStr = "tan";
			tempToken = Token(FUNCTION_TANGENT);
			break;
		case OPERATOR_ADDITION:
			lexemeStr = "+";
			tempToken = Token(OPERATOR_ADDITION);
			break;
		case OPERATOR_AND:
			lexemeStr = "and";
			tempToken = Token(OPERATOR_AND);
			break;
		case OPERATOR_DIVISION:
			lexemeStr = "/";
			tempToken = Token(OPERATOR_DIVISION);
			break;
		case OPERATOR_EQUALITY:
			lexemeStr = "=";
			tempToken = Token(OPERATOR_EQUALITY);
			break;
		case OPERATOR_EXPONENTIATION:
			lexemeStr = "^";
			tempToken = Token(OPERATOR_EXPONENTIATION);
			break;
		case OPERATOR_LESS_THAN:
			lexemeStr = "<";
			tempToken = Token(OPERATOR_LESS_THAN);
			break;
		case OPERATOR_MODULUS:
			lexemeStr = "%";
			tempToken = Token(OPERATOR_MODULUS);
			break;
		case OPERATOR_MULTIPLICATION:
			lexemeStr = "*";
			tempToken = Token(OPERATOR_MULTIPLICATION);
			break;
		case OPERATOR_NOT:
			lexemeStr = "not";
			tempToken = Token(OPERATOR_NOT);
			break;
		case OPERATOR_OR:
			lexemeStr = "or";
			tempToken = Token(OPERATOR_OR);
			break;
		case OPERATOR_SUBTRACTION:
			lexemeStr = "-";
			tempToken = Token(OPERATOR_SUBTRACTION);
			break;
		case PARENTHESIS_CLOSE:
			lexemeStr = ")";
			tempToken = Token(PARENTHESIS_CLOSE);
			break;
		case PARENTHESIS_OPEN:
			lexemeStr = "(";
			tempToken = Token(PARENTHESIS_OPEN);
			break;
		case STATEMENT_ASSIGN:
			lexemeStr = "assign";
			tempToken = Token(STATEMENT_ASSIGN);
			break;
		case STATEMENT_IF:
			lexemeStr = "if";
			tempToken = Token(STATEMENT_IF);
			break;
		case STATEMENT_IFF:
			lexemeStr = "iff";
			tempToken = Token(STATEMENT_IFF);
			break;
		case STATEMENT_LET:
			lexemeStr = "let";
			tempToken = Token(STATEMENT_LET);
			break;
		case STATEMENT_WHILE:
			lexemeStr = "while";
			tempToken = Token(STATEMENT_WHILE);
			break;
		case TYPE_BOOLEAN:
			lexemeStr = "bool";
			tempToken = Token(TYPE_BOOLEAN);
			break;
		case TYPE_INTEGER:
			lexemeStr = "int";
			tempToken = Token(TYPE_INTEGER);
			break;
		case TYPE_REAL:
			lexemeStr = "real";
			tempToken = Token(TYPE_REAL);
			break;
		case TYPE_STRING:
			lexemeStr = "string";
			tempToken = Token(TYPE_STRING);
			break;
		case VALUE_BOOLEAN:
			tempBool = generateBoolean();
			
			if ( tempBool == true ) {
				lexemeStr = "true";
			} else {
				lexemeStr = "false";
			}

			tempToken = TokenBoolean(tempBool);
			break;
		case VALUE_INTEGER:
			lexemeStr = generateInteger();
			tempToken = Token(VALUE_INTEGER);
			break;
		case VALUE_REAL:
			lexemeStr = generateReal();
			tempToken = Token(VALUE_REAL);
			break;
		case VALUE_STRING:
			lexemeStr = generateString();
			tempToken = Token(VALUE_STRING);
			break;
		default:
			lexemeStr = "ERROR";
			break;
		}

		testFile << lexemeStr;
		testFile << generateWhiteSpace();

		tokenList.push_back(tempToken);
	}
	
	testFile.close();
}


bool Tester::generateBoolean() {
	int boolValue = rand() % 2;

	if ( boolValue == 0 ) {
		return true;
	} else {
		return false;
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

	// Add integer to stringstream
	out << randInt();

	return out.str();
}


std::string Tester::generateReal() {
	int randVal; // randVal is used whenever anything needs to be randomly generated
	std::stringstream out;

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

	return out.str();
}


std::string Tester::generateString() {
	std::stringstream out;
	int stringLength = rand() % (MAX_STRING_LENGTH + 1);
	//char stringAlphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()-_=+[]{}:;',.<>/?`\\|";
	char stringAlphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	for ( int i = 0; i < stringLength; i++ ) {
		out << stringAlphabet[rand() % sizeof(stringAlphabet)];
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
			out << "\n";
		}
	}

	return out.str();
}


int Tester::randInt() {
	return rand() % INT_MAX;
}

