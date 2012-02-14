#include "token.h"

std::string Token::toString() {
    switch(tag) {
	case TAG_OPENPAREN: return "(";
	case TAG_CLOSEPAREN: return ")";

	case TAG_ASSIGN: return "=";
	case TAG_IF: return "if";
	case TAG_IFF: return "iff";
	case TAG_LET: return "let";
	case TAG_WHILE: return "while";
	case TAG_PRINTLN: return "println";

	case TAG_ADD: return "+";
    case TAG_SUB: return "-";
    case TAG_MULT: return "*";
    case TAG_DIV: return "/";
    case TAG_MOD: return "%";
    case TAG_EXP: return "^";
    case TAG_LOG: return "log";
    case TAG_SIN: return "sin";
	case TAG_COS: return "cos";
	case TAG_TAN: return "tan";

	case TAG_AND: return "and";
	case TAG_OR: return "or";
	case TAG_NOT: return "not";
	case TAG_EQUAL: return "equal";
	case TAG_LT: return "<";

	case TAG_BOOL: return "bool";
	case TAG_INT: return "int";
	case TAG_REAL: return "real";
	case TAG_STRING: return "string";

	case TAG_BOOL_LIT: return "bool_lit";
	case TAG_INT_LIT: return "int_lit";
	case TAG_REAL_LIT: return "real_lit";
	case TAG_STRING_LIT: return "string_lit";

	case TAG_IDEN: return "iden";
	case TAG_ERROR: return "ERROR";

	default: return "ERROR: Bad Token Value";
    }
}
