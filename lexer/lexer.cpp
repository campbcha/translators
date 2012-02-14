#include <fstream>
#include <cctype>
#include <cmath>
#include "token.h"
#include "lexer.h"

// Open the file and initialize the line number to 1.
Lexer::Lexer(std::string file) {
    input.open(file.c_str(), std::ifstream::in);
    line = 1;
}

/*
Generates the next token. The strategy for determining the type
of token is to try a number of possibilities in order. Once one of
these subroutines returns non-NULL, we have a match and can return
the token.

If no matches are found, or there is no more input, it will return NULL.
*/
Token* Lexer::scan() {
    std::string word = getNextLexeme();

    if(word.length() == 0) return NULL;

    Token* result;
    if((result = getKeyword(word))) return result;
    if((result = getInt(word))) return result;
    if((result = getReal(word))) return result;
    if((result = getStringLiteral(word))) return result;
    if((result = getIdentifier(word))) return result;

    return NULL; // Should never get here!
}

/*
Returns the next "word" in the file as a string. How it works:
1. Ignore any leading whitespace, except if you encounter a newline, increment line.
2. Start appending non-whitespace characters to the return string. If the first such
   character is a '(' or a ')', we can return immediately.
3. Keep appending character until we hit whitespace or a paren. When we do, return.
4. If we hit the end of the file, return.
*/
std::string Lexer::getNextLexeme() {
    std::string word = "";
    while (input.peek() > 0) {
        char c = input.get();
        if(c == '\n') line++;
        if(isWhitespace(c)) continue;
        word.append(1, c);
        if(c == '(' || c == ')') return word;
        char next = input.peek();
        if(isWhitespace(next) || next == '(' || next == ')') return word;
    }
    return word;
}

/*
Check if the word is an int, and if it is, return the appropriate token.
*/
Token* Lexer::getInt(std::string word) {
    int res = 0;   // eventual result
    int state = 0; // state for our mini-DFA
    bool negate = false; // is the number negative, in which case we need to invert at the end?
    for(int i=0; i<word.length(); i++) {
        switch(state) {
        // First check for a plus or minus...
        case 0:
            state = 1; // Don't check for sign any time but the first time.
            if(word[i] == '+') break;
            if(word[i] == '-') {
                negate = true;
                break;
            }

        // Then fall through here and start collecting digits.
        case 1:
            if(isdigit(word[i])) {
                res = res * 10 + (word[i] - '0'); // subtract '0' to convert char to int
            }
            else {
                return NULL;
            }
            break;
        }
    }

    if(negate) res = -res;
    return new TypeToken<int>(line, TAG_INT_LIT, res);
}

/*
Check if the word is an real, and if it is, return the appropriate token.
*/
Token* Lexer::getReal(std::string word) {
    double res = 0;   // eventual returned result
    int state = 0;    // state in our mini-DFA below
    bool negate = false; // is the leading sign negative, meaning we need to neagate at end?
    bool is_exp = false; // is there an exponent (after the 'e')?
    int exp = 0;         // what is this exponent?
    bool neg_exp = false; // is the exponent negative?
    int frac_place = 10;  // keep track of our place value after the '.'
    for(int i=0; i<word.length(); i++) {
        switch(state) {
        // First time thorugh, check for leading +/-...
        case 0:
            state = 1;
            if(word[i] == '+') break;
            if(word[i] == '-') {
                negate = true;
                break;
            }
            if(!isdigit(word[i]) && word[i] != '.') return NULL;

        // Then fall through and start collecting digits.
        case 1:
            // if we hit decimal point, move on to fractional part mode
            if(word[i] == '.') {
                state = 2;
                break;
            }
            // if we hit 'e', move on to exponent mode
            if(word[i] == 'e') {
                state = 3;
                break;
            }
            // otherwise, just collect digits normally
            if(isdigit(word[i])) {
                res = res * 10 + (word[i] - '0');
            }
            // if we ever hit something bad, we don't have a real
            else {
                return NULL;
            }
            break;

        case 2:
            if(word[i] == 'e') {
                state = 3;
                break;
            }
            // now in fractional mode, we have to keep track of place value and divide
            // every digit by the current place value
            if(isdigit(word[i])) {
                res = res + (word[i] - '0')/(double)frac_place;
                frac_place *= 10;
            }
            else {
                return NULL;
            }
            break;

        // First time thorugh exponent mode, check for leading +/-...
        case 3:
            state = 4;
            is_exp = true;
            if(word[i] == '+') break;
            if(word[i] == '-') {
                neg_exp = true;
                break;
            }
            if(!isdigit(word[i])) return NULL;

        // Then fall through and start collecting digits.
        case 4:
            if(isdigit(word[i])) {
                exp = exp * 10 + (word[i] - '0');
            }
            else {
                return NULL;
            }
            break;
        }
    }

    if(neg_exp) exp = -exp; // if negative exponent, negate
    if(is_exp) res = res * pow(10, exp); // if there was an exponent, apply it
    if(negate) res = -res;  // if whole number negative, negate
    return new TypeToken<double>(line, TAG_REAL_LIT, res);
}

/*
Check if the word is an string literal, and if it is, return the appropriate token.
*/
Token* Lexer::getStringLiteral(std::string word) {
    // if no starting quote, not a string literal
    if(word[0] != '"') return NULL;

    std::string output = ""; // eventual returned result
    char c = 0;

    // First, check for any escape characters and replace them.
    for(int i=1; i<word.length(); i++) {
        c = word[i];
        if(c == '\\' && i < word.length() - 1) {
            char next = word[i+1];
            switch (next) {
                case 'n': output.append(1, '\n'); i++; break;
                case 't': output.append(1, '\t'); i++; break;
                case 'r': output.append(1, '\r'); i++; break;
                case '\'': output.append(1, '\''); i++; break;
                case '"': output.append(1, '"'); i++; break;
                case '\\': output.append(1, '\\'); i++; break;
                default: output.append(1, '\\'); break;
            }
        }
        // Done if the string also ends in a quote.
        else if(c == '"' && i == word.length() - 1) {
            return new TypeToken<std::string>(line, TAG_STRING_LIT, output);
        }
        // Otherwise, append to result and move on.
        else {
            output.append(1, c);
        }
    }

    // NOW... If previous string did not end in a quote, this means that we need to
    // start grabbing more characters out of the input stream looking for the end quote.
    // Basically keep appending characters until we find another non-escaped quote. If we
    // hit the end of the file and still haven't found it, declare an error.
    while(input.peek() > 0) {
        c = input.get();
        if(c == '\\') {
            char next = input.peek();
            switch (next) {
                case 'n': output.append(1, '\n'); input.get(); break;
                case 't': output.append(1, '\t'); input.get(); break;
                case 'r': output.append(1, '\r'); input.get(); break;
                case '\'': output.append(1, '\''); input.get(); break;
                case '"': output.append(1, '"'); input.get(); break;
                case '\\': output.append(1, '\\'); input.get(); break;
                default: output.append(1, '\\'); break;
            }
        }
        else if(c == '"') {
            char next = input.peek();
            if(next < 0 || isWhitespace(next)) {
               return new TypeToken<std::string>(line, TAG_STRING_LIT, output);
            }
        }
        else {
            output.append(1, c);
        }
    }

    return new TypeToken<std::string>(line, TAG_ERROR, "String literal reached end of input without closing.");
}

/*
Check if the word is an keyword, and if it is, return the appropriate token.
*/
Token* Lexer::getKeyword(std::string word) {
    if(word.compare("true") == 0) return new TypeToken<bool>(line, TAG_BOOL_LIT, true);
    if(word.compare("false") == 0) return new TypeToken<bool>(line, TAG_BOOL_LIT, false);
    if(word.compare("(") == 0) return new Token(line, TAG_OPENPAREN);
    if(word.compare(")") == 0) return new Token(line, TAG_CLOSEPAREN);
    if(word.compare("assign") == 0) return new Token(line, TAG_ASSIGN);
    if(word.compare("if") == 0) return new Token(line, TAG_IF);
    if(word.compare("iff") == 0) return new Token(line, TAG_IFF);
    if(word.compare("let") == 0) return new Token(line, TAG_LET);
    if(word.compare("while") == 0) return new Token(line, TAG_WHILE);
    if(word.compare("println") == 0) return new Token(line, TAG_PRINTLN);
    if(word.compare("+") == 0) return new Token(line, TAG_ADD);
    if(word.compare("-") == 0) return new Token(line, TAG_SUB);
    if(word.compare("*") == 0) return new Token(line, TAG_MULT);
    if(word.compare("/") == 0) return new Token(line, TAG_DIV);
    if(word.compare("%") == 0) return new Token(line, TAG_MOD);
    if(word.compare("^") == 0) return new Token(line, TAG_EXP);
    if(word.compare("log") == 0) return new Token(line, TAG_LOG);
    if(word.compare("sin") == 0) return new Token(line, TAG_SIN);
    if(word.compare("cos") == 0) return new Token(line, TAG_COS);
    if(word.compare("tan") == 0) return new Token(line, TAG_TAN);
    if(word.compare("and") == 0) return new Token(line, TAG_AND);
    if(word.compare("or") == 0) return new Token(line, TAG_OR);
    if(word.compare("not") == 0) return new Token(line, TAG_NOT);
    if(word.compare("=") == 0) return new Token(line, TAG_EQUAL);
    if(word.compare("<") == 0) return new Token(line, TAG_LT);
    if(word.compare("bool") == 0) return new Token(line, TAG_BOOL);
    if(word.compare("int") == 0) return new Token(line, TAG_INT);
    if(word.compare("real") == 0) return new Token(line, TAG_REAL);
    if(word.compare("string") == 0) return new Token(line, TAG_STRING);
    return NULL;
}

/*
This takes care of basically anything that does not fall into any of the other categories.
*/
Token* Lexer::getIdentifier(std::string word) {
    return new TypeToken<std::string>(line, TAG_IDEN, word);
}

/*
Helper function so I don't have to type this line over and over.
*/
bool Lexer::isWhitespace (char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
