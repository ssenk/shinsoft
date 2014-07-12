#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for (int ii=0; ii<sys_nerr; ii++)
        printf("%02d : %s\n", ii, sys_errlist[ii]);
        
	if(!fopen("notfound.txt", "r"))
	{
		perror("fopen()");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
