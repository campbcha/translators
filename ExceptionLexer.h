#ifndef ExceptionLexer_H
#define ExceptionLexer_H

#include "Exception.h"

/** An extension of the Exception class intended for the Lexical analyzer. Contains information specific to lexical analysis.
 */
class ExceptionLexer : public Exception {
public:
	/** Construct a new ExceptionLexer object with the specified character array and the specified line number.
	 */
	ExceptionLexer(const std::string message, int lineNumer);

	/** Deallocate the object properly. 
	 */
	~ExceptionLexer();

	/** Return the line number of the source code file that caused the lexical analyzer to throw the exception.
	 */
	int getLineNumber();

	/** Print a human-readable message to cerr.
	 */
	void print();

private:
	// The line number of the source code file that the exception was thrown on.
	int lineNumber;
};

#endif // ExceptionLexer_H
