#include "term/term.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROJECT_NAME "tic-tac-toe"

int main(int argc, char **argv) {
    if (argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
		exit(EXIT_FAILURE);
    }

	if (ttyname(STDOUT_FILENO) == NULL) {
		fprintf(stderr, "%s: Can only run from within a terminal\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf(TERM_STR_CLEAR_ALL);
	zstr cursor = term_set_cursor(0, 0);
	printf(ZSTR_FMT, ZSTR_ARG(cursor));
	zstr_free(&cursor);

	printf("Hello!");

	cursor = term_move_cursor(-5, 5);
	printf(ZSTR_FMT, ZSTR_ARG(cursor));
	zstr_free(&cursor);

	printf("Bye!");

    return 0;
}
