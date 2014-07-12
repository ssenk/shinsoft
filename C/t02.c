#include <stdio.h>
void dump_environ(void);

int
main(int argc, char **argv)
{
        int ii;
	printf("================================\n");
	printf("ARGUMENT DUMP (ARGC ==> [%02d])\n", argc);
	printf("================================\n");
	for( ii=0; ii < argc; ii++ )
	{
		printf("ARGV[%02d] ==> [%s]\n", ii, argv[ii]);
	}
	printf("================================\n");
    dump_environ();
	printf("================================\n");
}


void dump_environ(void)
{
    //extern char **environ;
    char **env = environ;
    while (*env)
    {
    puts(*env++);
    }
}

