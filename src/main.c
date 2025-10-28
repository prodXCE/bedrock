#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <runtime.h>

int main(int argc, char **argv) {

	static struct option long_options[] = {
		{"help", no_argument, 0, 'h'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0}
	};

	int c;
	int option_index = 0;

	while ((c = getopt_long(argc, argv, "hv", long_options, &option_index)) != -1) {
		switch (c) {
			case 'h':
				print_help();
				return 0;
			case 'v':
				printf("bedrock version 0.1.1\n");
				return 0;
			case '?':
				return 1;
			default:
				abort();
		}
	}


	if (optind >= argc) {
		fprintf(stderr, "Error: No command provided.\n");
		print_help();
		return 1;
	}

	char *subcommand = argv[optind];

	int sub_argc = argc - optind;

	char **sub_argv = argv + optind;

	if (strcmp(subcommand, "run") == 0) {
		if (sub_argc < 2) {
			fprintf(stderr, "Error: 'run' requries a command to execute.\n");
			print_help();
			return 1;
		}

		return bedrock_run(sub_argc - 1, sub_argv + 1);

	} else if (strcmp(subcommand, "help") == 0) {
		print_help();
		return 0;
	} else {
		fprintf(stderr, "Error: Unknown command '%s'\n", subcommand);
		print_help();
		return 1;
	}

	return 0;
}


