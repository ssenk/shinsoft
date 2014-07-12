#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winbase.h>

int main(void)
{
	int ii;
	for (ii = 0; ii < sys_nerr; ii++)
	{
		printf("%02d : %s\n", ii, sys_errlist[ii]);
	}
	fflush(NULL);

	for (ii = 0; ii < 10; ii++)
	{
		Sleep(1000);
		putchar('.');
		fflush(NULL);
	}

	if (!fopen("notfound.txt", "r"))
	{
		perror("fopen()");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
