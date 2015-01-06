#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 	srand(time(NULL));
	int result = rand();
	printf("Printing rand() result: %d\n",
		result);
	return 0;
}
