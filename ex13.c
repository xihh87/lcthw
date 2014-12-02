#include <stdio.h>

int main(int argc, char *argv[])
{
	int a;
	for(a = 1; a < argc; a++) {

	int i, letter;
	for(i = 0; letter = argv[a][i], letter != '\0'; i++) {

		switch(letter) {
		case 'a':
		case 'A':
			printf("%d: 'A'\n", i);
			break;

		case 'e':
		case 'E':
			printf("%d: 'E'\n", i);
			break;

		case 'i':
		case 'I':
			printf("%d: 'I'\n", i);
			break;

		case 'o':
		case 'O':
			printf("%d: 'O'\n", i);
			break;

		case 'u':
		case 'U':
			printf("%d: 'U'\n", i);
			break;

		case 'y':
		case 'Y':
			if(i > 2) {
				/* It's only sometimes Y */
				printf("%d: 'Y'\n", i);
			}
			break;

		default:
			printf("%d: %c is not a vowel\n", i, letter);
		}
	}

	}

	return 0;
}
