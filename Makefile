CCC = g++
CCFLAGS = --pedantic-errors -Wall -Werror
TESTDIR = Milestone2Tester/Milestone2Tester
OBJS =	Main.o \
	Exception.o \
	ExceptionLexer.o \
	Lexer.o \
	Token.o \
	TokenBoolean.o \
	TokenInteger.o \
	TokenReal.o \
	TokenString.o \
	Tester.o
SOURCE = $(TESTDIR)/Main.cpp \
	  Exception.cpp \
	  ExceptionLexer.cpp \
	  Lexer.cpp \
	  Tokens/Token.cpp \
	  Tokens/TokenBoolean.cpp \
	  Tokens/TokenInteger.cpp \
	  Tokens/TokenReal.cpp \
	  Tokens/TokenString.cpp \
	  $(TESTDIR)/Tester.cpp
HEADER = Exception.h \
	 ExceptionLexer.h \
	 Lexer.h \
	 Tokens/Token.h \
	 Tokens/TokenBoolean.h \
	 Tokens/TokenBoolean.h \
	 Tokens/TokenReal.h \
	 Tokens/TokenString.h \
	 $(TESTDIR)/Tester.h
RUNFLAGS = ""

#default: ${OBJS} compiler clean
default : $(OBJS) tester clean

${OBJS}: ${SOURCE} ${HEADER}
	$(CCC) $(CCFLAGS) -c $(SOURCE)

tester: $(OBJS)
	$(CCC) $(CCFLAGS) -o tester $(OBJS)

compiler: $(OBJS)
	$(CCC) $(CCFLAGS) -o compiler $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f testFile*.txt
#	rm -f $(OBJS) compiler core proftest.out stutest1.out stutest2.out
#	ls

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
