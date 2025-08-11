#include "main.h"

/* The starting, default index LibPacIO will use. */
#define DEFAULT_INDEX 1

/* Determines if a string matches. */
#define MATCHING 0

/* Flag macros. */
#define FLAG_PATH 0
#define FLAG_VERSION 1
#define FLAG_HELP 2
#define FLAG_TEST 3

/* A list of options that LibPacIO_Test will use. */
static const flag_option_t flag_option_list[LIST_SIZE] = {
	/* Path */
	{"-p", "<filepath>",
		"Sets the target filepath for LibPacIO to use."},
	/* Version */
	{"-v", NULL,
		"Prints the versions for both LibPacIO and LibPacIO_Test."},
	/* Help */
	{"--help", NULL,
		"Prints the help menu for LibPacIO_Test."},
	/* Test */
	{"--test", "<testname>",
		"Executes a test for LibPacIO."}
};

/* The index counter that LibPacIO_Test uses to go over the flag options. */
static uint8_t flag_index = DEFAULT_INDEX;

/* Go through all the flags in the LibPacIO_Test.
Returns 0 if successful, but returns -1 if there is an error. */
int handle_flags(int __argc, char* __argv[]) {
	reset_flag_index();
	while (flag_index < __argc) {
		const char* arg = __argv[flag_index];
		// TODO: Work on all four of those flags.
		if (strcmp(arg, get_flag_name(FLAG_PATH)) == MATCHING) {
			/* Path */
			printf("Change the filepath.\n");
		} else if (strcmp(arg, get_flag_name(FLAG_VERSION)) == MATCHING) {
			/* Version */
			printf("Display version\n");
		} else if (strcmp(arg, get_flag_name(FLAG_HELP)) == MATCHING) {
			/* Help */
			printf("Show help menu.\n");
		} else if (strcmp(arg, get_flag_name(FLAG_TEST)) == MATCHING) {
			/* Test*/
			printf("Perform a test.\n");
		} else {
			/* Error */
			printf("An error occured.\n");
			return PAC_FAILURE;
		}
		add_flag_index(1);
	}
	return PAC_SUCCESS;
}

/* Gets the name of a flag option. */
const char* get_flag_name(uint8_t __index) {
	if (__index < LIST_SIZE) {
		return flag_option_list[__index].name;
	} else {
		return NULL;
	}
}

/* Adds a number to the flag_index counter. */
void add_flag_index(const uint8_t __amount) {
	flag_index += __amount;
	return;
}

/* Resets the flag_index counter from the LibPacIO_Test. */
void reset_flag_index(void) {
	flag_index = DEFAULT_INDEX;
	return;
}

/* Returns the flag_index from LibPacIO_Test. */
uint8_t get_flag_index(void) {
	return flag_index;
}
