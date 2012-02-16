CCC = g++
CCFLAGS = --pedantic-errors -Wall -Werror

FILES = main \
	../../Exception \
	ParseNode \
	ParseNode/Terminal \
	ParseNode/Nonterminal \
	ParseNode/Nonterminal/F \
	ParseNode/Nonterminal/T \
	ParseNode/Nonterminal/S \
	ParseTree
OUTPUT = tester
OBJS :=

default: compile ${OUTPUT} clean done


compile:
	@for FILE in ${FILES}; do \
		echo " Compiling $$FILE.o."; \
		${CCC} ${CCFLAGS} -c $$FILE.cpp; \
	done
	@rm -f ${OUTPUT} #Poor ad hoc solution to force re-compilation of tester.


done:
	@echo " Done!"


${OUTPUT}:
	@echo " Linking ${OUTPUT}."
	@$(CCC) $(CCFLAGS) -o ${OUTPUT} main.o Exception.o ParseNode.o ParseTree.o Terminal.o Nonterminal.o F.o T.o S.o


clean:
	@echo " Cleaning."
	@rm -f *.o
