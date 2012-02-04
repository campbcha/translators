#ifndef Exception_H
#define Exception_H

#include <iostream>
#include <string>

/** An alternative to the C++ exception class. Contains a human-readable error message.
 */
class Exception {
public:
	/** Construct a new Exception object with the specified character array.
	 */
	Exception(const std::string message);

	/** Deletes the message attribtue.
	 */
	~Exception();

	/** Prints the Exception message to cerr for debugging purposes.
	 */
	void print();

	/**
	 */
	std::string* getMessage();
private:
	// A string object representing the message generated by the exception.
	std::string* message;
};

#endif // Exception_H
