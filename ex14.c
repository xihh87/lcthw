#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_letters(char arg[])
{
	int i = 0;
	for(i = 0; i < strlen(arg); i++) {

		char ch = arg[i];
		if(isalnum(ch) || isblank(ch) || ispunct(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

	
int main(int argc, char *argv[])
{
	int i = 0;
	for(i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
	return 0;
}
