CCC = g++
CCFLAGS = --pedantic-errors -Wall -Werror
OBJS =	main.o \
	Exception.o \
	ExceptionLexer.o \
	Ibtl.o \
	Lexer.o \
	Token.o \
	TokenBoolean.o \
	TokenInteger.o \
	TokenReal.o \
	TokenString.o
SOURCE = main.cpp \
	 Exception.cpp \
	 ExceptionLexer.cpp \
	 Ibtl/Ibtl.cpp \
	 Lexer.cpp \
	 Tokens/Token.cpp \
	 Tokens/TokenBoolean.cpp \
	 Tokens/TokenInteger.cpp \
	 Tokens/TokenReal.cpp \
	 Tokens/TokenString.cpp
HEADER = Exception.h \
	 ExceptionLexer.h \
	 Ibtl/Ibtl.h \
	 Lexer.h \
	 Tokens/Token.h \
	 Tokens/TokenBoolean.h \
	 Tokens/TokenBoolean.h \
	 Tokens/TokenReal.h \
	 Tokens/TokenString.h
RUNFLAGS = ""

default: ${OBJS} compiler clean

${OBJS}: ${SOURCE} ${HEADER}
	$(CCC) $(CCFLAGS) -c $(SOURCE)

compiler: $(OBJS)
	$(CCC) $(CCFLAGS) -o compiler $(OBJS)

clean:
	rm -f $(OBJS) stutest.out proftest.out

stutest.out: compiler
	cat stutest1.in
	-compiler $(RUNFLAGS) stutest1.in > stutest1.out
	cat stutest1.out
# Notice the next line. The `-' says to ignore the return code. This
# is a way to have multiple tests of errors that cause non-zero return
# codes.
	cat stutest2.in
	-compiler stutest2.in > stutest2.out
	cat stutest2.out

proftest.out: compiler
	cat $(PROFTEST)
	compiler $(PROFTEST) > proftest.out
	cat proftest.out
