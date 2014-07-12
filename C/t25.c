#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

extern char *sys_errlist[];
extern int sys_nerr;
void dump_sys_errlist( void );

static long gl_status = EXIT_SUCCESS;
#define ERROR_HANDLER(f) if (errno) { \
    gl_status = EXIT_FAILURE; \
    printf("[%s:%05d] <<%s>> " ## f ## " - %05d:%s\n", basename(__FILE__), __LINE__, __FUNCTION__, errno, strerror(errno)); \
    errno = 0; \
    }

int main(int argc, char **argv, char **env)
{
    int ret;
    dump_sys_errlist();

    FILE *fp = fopen("./NOT_FOUND_FILE_TEST", "r");
    ERROR_HANDLER("fopen");
    if (fp) fclose(fp);

    ret = system("cooooooooooooooooop t25.c ./NOT_FOUND_FILE_TEST");
    switch (ret) {
    case 127: printf("execve() 호출 실패"); 
	      break;
    case -1:  printf("127 이외의 에러"); 
              ERROR_HANDLER("system");
	      break;
    case 0:   printf("system success"); 
	      break;
    default:  printf("system error : [%d]\n", ret); 
	      break;
    }

    printf("exit code = [%d]\n", gl_status);
    return (gl_status);
}

void dump_sys_errlist( void )
{
    char **p = sys_errlist;

    for (int ii=0; *p && ii<=sys_nerr; ii++)
    {
	printf("[%03d] %s\n", ii, *p++);
    }
}

