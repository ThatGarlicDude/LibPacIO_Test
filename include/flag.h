#ifndef LIBPACIO_TEST_FLAG_H
	#define LIBPACIO_TEST_FLAG_H

	#define LIST_SIZE 4

	#include "main.h"

	#ifdef __cplusplus
		extern "C" {
	#endif

	/* A typedef struct that serves as the blueprint for a test option
	designed for the terminal in mind. */
	typedef struct flag_option {
		const char* name;
		const char* parameter;
		const char* description;
	} flag_option_t;

	/* A list of options that LibPacIO_Test will use. */
	static const flag_option_t flag_option_list[LIST_SIZE];

	/* The index counter that LibPacIO_Test uses to go over flag
	options. */
	static uint8_t flag_index;

	/* Go through all the flags in the LibPacIO_Test.
	Returns 0 if successful, but returns -1 if there is an error. */
	extern int handle_flags(int __argc, char* __argv[]);

	/* Gets the name of a flag option. */
	extern const char* get_flag_name(uint8_t __index);

	/* Adds a number to the flag_index counter. */
	extern void add_flag_index(const uint8_t __amount);

	/* Resets the flag_index counter from the LibPacIO_Test. */
	extern void reset_flag_index(void);

	/* Returns the flag_index from the LibPacIO_Test. */
	extern uint8_t get_flag_index(void);

	#ifdef __cplusplus
		}
	#endif

#endif
