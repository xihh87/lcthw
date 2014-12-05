#include <stdio.h>

void print_names_ages_array(char **names, int *ages, int count)
{
	/* first way using indexing */
	int i = 0;
	while (i < count) {
		printf("%s has %d years alive.\n",
			names[i], ages[i]);
		i++;
	}

	printf("---\n");

}

void print_names_ages_pointer_start(char **names, int *ages, int count)
{
	/* setup the pointers to the start of the arrays */
	int *cur_age = ages;
	char **cur_name = names;

	/* second say using pointers */
	int i = 0;
	while (i < count) {
		printf("%s is %d years old.\n",
			*(cur_name + i), *(cur_age + i));
		i++;
	}

	printf("---\n");
}

void print_names_ages_pointer_array(char **names, int *ages, int count)
{
	/* setup the pointers to the start of the arrays */
	int *cur_age = ages;
	char **cur_name = names;

	/* third way, pointers are just arrays */
	int i = 0;
	while (i < count) {
		printf("%s is %d years old again.\n",
			cur_name[i], cur_age[i]);
		i++;
	}

	printf("---\n");
}

void print_names_ages_pointer_math(char **names, int *ages, int count)
{
	/* setup the pointers to the start of the arrays */
	int *cur_age = ages;
	char **cur_name = names;

	/* fourth way with pointers in a stupid complex way */
	while ((cur_age - ages) < count)
	{
		printf("%s lived %d years so far.\n",
			*cur_name, *cur_age);
		cur_name++, cur_age++;
	}

}

int main(int argc, char *argv[])
{
	/* create two arrays we care about */
	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa",
	};

	/* safely get the sizes of ages */
	int count = sizeof(ages) / sizeof(int);

	print_names_ages_array(names, ages, count);
	print_names_ages_pointer_start(names, ages, count);
 	print_names_ages_pointer_array(names, ages, count);
	print_names_ages_pointer_math(names, ages, count);

	return 0;
}
