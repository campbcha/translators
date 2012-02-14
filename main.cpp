/** Entry point to the IBTL Compiler
 */

#include <iostream>
#include <string>
#include <list>
#include "Exception.h"

void printHelp();
void printVerboseOptions();

// Enumeration for possible verbose types
enum VerboseType {
	NONE,
	ERRORS,
	WARNINGS,
	ALL,
	DEBUG,
	VERBOSE_TYPE_MAX
};

int main( int argc, char** argv ) {
	VerboseType vType = ALL;
	std::list<std::string> fileList;
	std::list<std::string>::iterator fileListIterator;
	const int STRING_EQUALITY = 0;
	int numRuns = 0;
	
	std::cout << "------------ IBTL Translator -------------" << std::endl;
	std::cout << "CS480: campbcha, clinew, zoonb, piorkowd" << std::endl << std::endl;

	// Analyze parameters
	if ( argc <= 1 ) {
		std::cout << "Need at least one file name." << std::endl;
		printHelp();
		return 0;
	}

	for ( int i = 1; i < argc; i++ ) {
		std::string argument = argv[i];

		if ( argument.compare("--help") == STRING_EQUALITY
			 || argument.compare("-h") == STRING_EQUALITY ) {
			// Print help and exit
			printHelp();
			return 0;
		} else if ( argument.compare("-v") == STRING_EQUALITY
			 || argument.compare("--verbose") == STRING_EQUALITY ) {
			// Assign verbose to correct value
			std::string vTypeArg = argv[++i];

			if ( vTypeArg.compare("none") == STRING_EQUALITY ) {
				vType = NONE;
			} else if ( vTypeArg.compare("errors") == STRING_EQUALITY ) {
				vType = ERRORS;
			} else if ( vTypeArg.compare("warnings") == STRING_EQUALITY ) {
				vType = WARNINGS;
			} else if ( vTypeArg.compare("all") == STRING_EQUALITY ) {
				vType = ALL;
			} else if ( vTypeArg.compare("debug") == STRING_EQUALITY ) {
				vType = DEBUG;
			} else {
				std::cout << "Invalid verbose type. See valid options below." << std::endl;
				printVerboseOptions();
				return 0;
			}
		} else {
			// Assume filename to compile
			fileList.push_back(argument);
			numRuns++;
		}
	}

	// Print verbose message
	switch ( vType ) {
	case NONE:
		std::cout << "PRINTING NO MESSAGES";
		break;
	case ERRORS:
		std::cout << "PRINTING ONLY ERRORS";
		break;
	case WARNINGS:
		std::cout << "PRINTING ONLY WARNINGS";
		break;
	case ALL:
		std::cout << "PRINTING ALL MESSAGES";
		break;
	case DEBUG:
		std::cout << "PRINTING ALL MESSAGES + DEBUG";
		break;
	default:
		std::cout << "VERBOSE ERROR";
		return 0;
	}
	std::cout << std::endl << std::endl;

	// Run compiling process for each file
	for ( fileListIterator = fileList.begin(); fileListIterator != fileList.end(); fileListIterator++ ) {
		std::string fileName = *fileListIterator;

		if ( vType == ALL || vType == DEBUG ) {
			std::cout << "--------------------------------" << std::endl;
			std::cout << "Starting file " << fileName << std::endl;
		}
		
		try {
			// Run parser
			std::cout << "PARSING FILE " << fileName << std::endl;
		} catch (Exception e) {
			e.print();
		} catch (...) {
			std::cerr << "ffs.\n";
		}

		if ( vType == ALL || vType == DEBUG ) {
			std::cout << "Compiling " << fileName << " done" << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}
	}

	// Do nothing, but a dance.
	return 0;
}

void printHelp() {
	std::cout << "Compiler USAGE: compiler [-v vType] fileName1 [fileName2 ...]" << std::endl;
	std::cout << "\tThis compiler will take one or more source files of the Itty-Bitty Teaching Language (IBTL)" << std::endl;
	std::cout << "\tand compile them into forth code. All arguments are case sensitive." << std::endl << std::endl;
	printVerboseOptions();
}

void printVerboseOptions() {
	std::cout << "Verbose options: Use -v or --verbose followed by one of the following verbose types. Default type is all." << std::endl;
	std::cout << "\tnone: Prints no messages" << std::endl;
	std::cout << "\terrors: Prints only error messages" << std::endl;
	std::cout << "\twarnings: Prints only warning and error messages" << std::endl;
	std::cout << "\tall: Prints all messages" << std::endl;
}
