#ifndef Tester_H
#define Tester_H

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <list>

#include "Tokens.h"
#include "Lexer.h"
#include "Exception.h"

#define INIT_VAL 0xdeadbeef
#define MAX_LEXEMES 500
#define MAX_WHITE_SPACE 1
#define MAX_STRING_LENGTH 50

enum VerboseType {
	NONE,
	ERRORS,
	ALL,
	VERBOSE_TYPE_MAX
};


class Tester {
public:
	/**
	 *
	 */
	Tester(std::string fileName);

	/**
	 * @throws Exception with a message
	 */
	void run(VerboseType vType);

private:
	std::string testFileName;
	std::ofstream testFile;
	std::list<Token> tokenList;

	
	/**
	 *
	 */
	void generateTestFile();

	/**
	 *
	 */
	bool generateBoolean();

	/** returns the string of a random, positive int
	 *
	 */
	std::string generateInteger();

	/** returns the string of a random, positive real
	 *
	 */
	std::string generateReal();

	/**
	 *
	 */
	std::string generateString();

	/**
	 *
	 */
	std::string generateWhiteSpace();

	/**
	 *
	 */
	int randInt();
};

#endif