#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <sys/stat.h>

#include "spaghetti.h"

#define SPAGHETTIFIER_VERSION ("spaghetti 1.0")

static void help(void) {
	printf("spaghetti - Makes your code uncompilable by replacing letters with unicode symbols that look the same!\n\n");
	printf("Usage example:\n");
	printf("spaghetti [(-h|--help)] [(-V|--version)] [(-v|--verbose)] [(-i|--in) file] [(-o|--out) file] [(-p|--print)] [(-e|--spaghettify)] [(-d|--despaghettify)]\n\n");
	printf("Options:\n");
	printf("-h or --help: Displays this information.\n");
	printf("-V or --version: Displays the current version number.\n");
	printf("-i or --in: Input file instead of stdin.\n");
	printf("-o or --out: Output file instead of stdout.\n");
	printf("-p or --print: Show how characters are converted.\n");
	printf("-e or --spaghettify: Do spaghettification (default).\n");
	printf("-d or --despaghettify: Undo spaghettification.\n");
}

static void version(void) {
	printf("%s\n", SPAGHETTIFIER_VERSION);
}

int main(int argc, char **argv) {

	char opt_help = 0;
	char opt_version = 0;
	char opt_print = 0;
	char opt_spaghettify = 0;
	char opt_despaghettify = 0;

	const char *opt_in = 0;
	const char *opt_out = 0;

	int next_option;
	const char* const short_options = "hVvi:o:ped" ;
	const struct option long_options[] = {
		{"help", 0, 0, 'h'},
		{"version", 0, 0, 'V'},
		{"in", 1, 0, 'i'},
		{"out", 1, 0, 'o'},
		{"print", 0, 0, 'p'},
		{"spaghettify", 0, 0, 'e'},
		{"despaghettify", 0, 0, 'd'},
		{0, 0, 0, 0}
	};
	while (1) {
		next_option = getopt_long (argc, argv,
			short_options, long_options, NULL);

		if (next_option == -1)
			break;

		switch (next_option){
		case 'h':
			opt_help = 1;
			break;

		case 'V':
			opt_version = 1;
			break;

		case 'i':
			opt_in = optarg;
			break;

		case 'o':
			opt_out = optarg;
			break;

		case 'p':
			opt_print = 1;
			break;

		case 'e':
			opt_spaghettify = 1;
			break;

		case 'd':
			opt_despaghettify = 1;
			break;

		case '?':
			break;

		case -1:
			break;

		default:
			return(1);
		}
	}

	if (opt_help) {
		help();
		exit(0);
	}

	if (opt_version) {
		version();
		exit(0);
	}

	int selected = (opt_print + opt_spaghettify + opt_despaghettify);
	if (selected > 1) {
		printf("Too many options selected\n");
		exit(0);
	} else if (selected == 0) {
		opt_spaghettify = 1;
	}

	if (opt_print) {
		spaghetti_print(stdout);
		exit(0);
	}

	if (!opt_in) {
		opt_in = "/dev/stdin";
	}

	if (!opt_out) {
		opt_out = "/dev/stdout";
	}

	FILE *in = fopen(opt_in, "r");
	if (!in) {
		fprintf(stderr, "Cannot read '%s': ", opt_in);
		perror(NULL);
		exit(1);
	}

	FILE *out = fopen(opt_out, "w");
	if (!out) {
		fprintf(stderr, "Cannot write '%s': ", opt_out);
		perror(NULL);
		exit(1);
	}

	if (opt_spaghettify) {
		spaghetti_do(in, out);
	}

	if (opt_despaghettify) {
		spaghetti_undo(in, out);
	}

	fclose(out);
	fclose(in);

	return 0;
}
