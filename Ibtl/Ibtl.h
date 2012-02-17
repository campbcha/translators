/** Namespace to hold various utilities for the IBTL compiler.
 */

#include "../Tokens/Tokens.h"

namespace Ibtl {
	// The alphabet for the IBTL language.
	char stringAlphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

	/** Returns a random boolean.
	 */
	bool randomBoolean();

	/** Returns a random double.
	 */
	double randomDouble();

	/** Returns a random integer.
	 */
	int randomInteger();

	/** Allocates and returns a pointer to a randomly-generated string in the
	 *  IBTL.
	 */
	std::string* randomString();

	/** Returns a TokenBoolean with a random value.
	 */
	TokenBoolean* randomTokenBoolean();

	/** Returns a TokenReal with a random value.
	 */
	TokenReal* randomTokenReal();

	/** Returns a TokenInteger with a random value.
	 */
	TokenInteger* randomTokenInteger();

	/** Returns a TokenString with a random value.
	 */
	TokenString* randomTokenString();
}
