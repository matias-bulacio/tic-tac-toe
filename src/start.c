#include <include/app.h>
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


    return app();
}
