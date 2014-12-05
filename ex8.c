#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	char full_name[] = {
		'Z', 'e', 'd',
		' ', 'A', '.', ' ',
		'S', 'h', 'a', 'w', 
	};

	areas[-1] = 100;
	full_name[0] = 'N';
	full_name[8] = 'n';
	full_name[9] = 'o';
	name[0] = 'R'; 

	/* Warning: on some systems you may have to change the
	 * %ld in this code to a %u since it will use unsigned ints */
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n",
		sizeof(areas));
	printf("The number of ints in areas: %ld\n",
		sizeof(areas) / sizeof(int));
	int *cur_area = areas;
	printf("The first area is %d, the 2nd %d.\n",
		*cur_area, *(cur_area + 1));

	printf("The contents of areas (int[]): %d, %d, %d, %d, %d, %d\n",
		*(cur_area + 0), *(cur_area + 1), *(cur_area + 2), *(cur_area + 3), *(cur_area + 4),
		*(cur_area + -1));

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n",
		sizeof(name));
	printf("The number of chars: %ld\n",
		sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
		sizeof(full_name));
	printf("The number of chars: %ld\n",
		sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full_name=\"%s\"\n",
		name, full_name);

	return 0;
}
