#include <stdio.h>
#include <assert.h>

void print_names_ages(char *names[], int ages[],
	int elem, const char *format)
{
	int i = 0;
	for (i = 0; i < elem; i++) {
		printf(format, names[i], ages[i]);
	}

	printf("---\n");
}

void print_names_ages_addr(char **names, int *ages,
	int elem, const char *format)
{
	int i = 0;
	for (i = 0; i < elem; i++) {
		printf(format, names[i], ages[i],
			&names[i], &ages[i]);
	}

	printf("---\n");
}

int main(int argc, char *argv[])
{
	/* create two arrays we care about */
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa",
	};

	const char *formats[] = {
		"%s has %d years alive.\n",
		"%s is %d years old.\n",
		"%s is %d years old again.\n",
		"%s lived %d years so far.\n",
	};

	int formats_cnt = sizeof(formats) / sizeof(formats[0]);
	int ages_cnt = sizeof(ages) / sizeof(ages[0]);
	int names_cnt = sizeof(names) / sizeof(names[0]);

	assert(names_cnt == ages_cnt);
	
	int i = 0;
	for (i = 0; i < formats_cnt; i++)
	{
		print_names_ages(names, ages, names_cnt, formats[i]);
	}

	print_names_ages_addr(names, ages, names_cnt,
		"%s have lived %d years for now\nname: %p\nage: %p\n\n");
	
	return 0;
}
