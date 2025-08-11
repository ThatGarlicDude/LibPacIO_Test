#ifndef LIBPACIO_TEST_MAIN_H
	#define LIBPACIO_TEST_MAIN_H

	#include <libpacio.h>
	#include "main.h"
	#include "flag.h"
	#include "path.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	/* The main function of the test program.
	Returns 0 if successful, and returns -1 if not. */
	extern int main(int argc, char* argv[]);

	#ifdef __cplusplus
		}
	#endif

#endif
