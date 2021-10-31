.DEFAULT_GOAL := run
norminette:
	-norminette ./ex00/functions.h
	-norminette ./ex00/tools.c
	-norminette ./ex00/casecheck.c
	-norminette ./ex00/input_management.c
	-norminette ./ex00/main.c

compile:	norminette
	-gcc -Wall -Wextra -Werror ./ex00/functions.h ./ex00/tools.c ./ex00/input_management.c ./ex00/casecheck.c ./ex00/main.c

run:	compile
	-./a.out "4 1 2 3 1 2 2 2 2 2 2 1 3 2 1 4" | cat -e

test:
	-./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e

test2:
	-./a.out "2 2 3 1 2 2 1 3 3 2 1 2 1 3 2 2" | cat -e

test3:
	-./a.out "2 3 1 3 3 1 2 2 2 1 3 2 2 2 1 3" | cat -e

test-nosolution:
	-./a.out "2 3 4 1 1 2 3 4 1 4 2 3 3 4 2 1" | cat -e

clean:
	-rm -rf ./a.out
	-rm -rf ./ex00/functions.h.gch


