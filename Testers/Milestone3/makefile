CCC = g++
CCFLAGS = --pedantic-errors -Wall -Werror

FILES = main ../../Exception ParseNode ParseTree
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
	@$(CCC) $(CCFLAGS) -o ${OUTPUT} main.o Exception.o ParseNode.o ParseTree.o


clean:
	@echo " Cleaning."
	@rm -f *.o
