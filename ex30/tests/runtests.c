#include <stdio.h>
#include "dbg.h"

int find_tests(const char *dir, const char *tests);
int run(char *test);

int
main(int argc, char *argv[])
{
	int i=0,
	int ntests=0;
	char *dir[] = NULL;
	char *tests[] = NULL;

	ntests = find_tests(dir, tests);
	for (i = 0; i <= ntests; i++) {
		run(tests[i]);
	}
}
