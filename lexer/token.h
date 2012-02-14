#ifndef Token_H
#define Token_H

#include <sstream>

// List of all possible token tags.
enum Tag {
    // Parenthesis
	TAG_OPENPAREN,
	TAG_CLOSEPAREN,

	// Keywords
	TAG_ASSIGN,
	TAG_IF,
	TAG_IFF,
	TAG_LET,
	TAG_WHILE,
	TAG_PRINTLN,

	// Math
	TAG_ADD,
    TAG_SUB,
    TAG_MULT,
    TAG_DIV,
    TAG_MOD,
    TAG_EXP,
    TAG_LOG,
    TAG_SIN,
	TAG_COS,
	TAG_TAN,

	// Logic
	TAG_AND,
	TAG_OR,
	TAG_NOT,
	TAG_EQUAL,
	TAG_LT,

	// Types
	TAG_BOOL,
	TAG_INT,
	TAG_REAL,
	TAG_STRING,

	// Type literals
	TAG_BOOL_LIT,
	TAG_INT_LIT,
	TAG_REAL_LIT,
	TAG_STRING_LIT,

	// Identifier
	TAG_IDEN,

	// Errors
	TAG_ERROR
};

/*
Generic token, of no special type. Contains simply a tag and a line number.
*/
class Token {
public:
	Token(int l, Tag t) : line(l), tag(t) {}
	Tag getTag() { return tag; }
	int getLine() { return line; }

    // Gets a string that includes the line number and a string reprsentation
    // of the tag.
	virtual std::string toString();

protected:
	Tag tag;
	int line; // which line in the source file this token was on
};

/*
Token with a tag and a value of type T. Current supported types are bool, int,
double, std::string.
*/
template<typename T>
class TypeToken : public Token {
public:
	TypeToken(int line, Tag tag, T val) : Token(line, tag), value(val) {}
	T getValue() { return value; }

	// Gets a string that includes the line number and a string reprsentation
    // of the tag. Also includes a string representation of the value.
	virtual std::string toString() {
	    std::string ret = Token::toString().append("\t");
        std::stringstream ss;
        ss << value;
        return ret.append(ss.str());
	}

protected:
	T value;
};

#endif //Token_H
