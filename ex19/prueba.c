#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	char *msg = argv[0];
	perror(msg);
	return 0;
}
