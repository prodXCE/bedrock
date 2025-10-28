#include <stdio.h>
#include "runtime.h"

void print_help() {
	printf(
			"Usage: bedrock [FLAGS] COMMAND [ARGS...]\n"
			"\n"
			" A minimal container engine in C.\n"
			"\n"
			"Flags:\n"
			"  -h, --help     Show this help message\n"
			"  -v, --version  Show version information\n"
			"\n"
			"Commands:\n"
			"  run <CMD> [..] Run a command in a new container\n"
			"  help           Show this help message\n"
		);
}

int bedrock_run(int argc, char **argv) {
	printf("[Phase 1] Attempting to run command: ");

	for (int i = 0; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	printf("\n");

	printf("\n[INFO] Phase 1 complete. No process was started.\n");

	return 0;

}
