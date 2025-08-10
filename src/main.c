#include <libpacio.h>
#include <stdio.h>
#include "main.h"

/* The main function of the test program.
Returns 0 if successful, and returns -1 if not. */
int main(int argc, char* argv[]) {
	/* Initiate the target for LibPacIO. */
	if (pacio_init_target(NULL) == -1) {
		return -1;
	}
	printf("Current Working Directory: %s\n", pacio_get_target());
	return 0;
}
