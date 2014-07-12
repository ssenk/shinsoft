/**
 ***********************************************************
 *   Filename : t47.c
 * Created on : 2011. 6. 12.
 *     Author : Andrew
 *    Project : t47
 *    Version : 
 *    License :
 *    History : 
 ***********************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <iso646.h>

#define __LOCAL_DEBUG__
#define __LOCAL_DEBUG_DETAIL__
#ifdef  __LOCAL_DEBUG__
#define PATHEND '\\'
#define BASENAME(V) (strrchr((V), PATHEND) ? strrchr(V, PATHEND) + 1 : (V))
#define __DEBUG__(fmt, ...) { \
    char     m[2048]; time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%Y-%m-%d %H:%M:%S", localtime(&t)); \
    snprintf(m, sizeof(m), "[%s:%05d] %s <<%s>> - " fmt " ", BASENAME(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
    puts(m); fflush(NULL); \
}
#else
#define __DEBUG__(...)
#endif  /* __LOCAL_DEBUG__ */

typedef struct context_t context_t;
struct context_t
{
	int version;
	char name[PATH_MAX];
	int argc;
	char **argv;
	char **envs;

	char file[PATH_MAX];
	context_t *next;
};

static context_t *ctx;

void exit_db(void)
{
	__DEBUG__("started");
	__DEBUG__("db disconnect");
	__DEBUG__("return")
}

void exit_context(void)
{
    int ii;
	__DEBUG__("started");
	for (ii=0; ii < (*ctx).argc; ii++)
	{
	    printf("argv[%d] = [%s]\n", ii, (*ctx).argv[ii]);
	}
	for (ii=0;*(*ctx).envs; ii++)
	{
        printf("env[%d]  = [%s]\n", ii, *(*ctx).envs++);
	}
	__DEBUG__("context clear");
	__DEBUG__("return")
}

int main(int argc, char **argv)
{
	context_t context =	{ 1, "t47", argc, argv, environ, __FILE__ };
	ctx = &context;

	__DEBUG__("started with context");
	atexit(exit_context);

	__DEBUG__("dbconnect success");
	atexit(exit_db);

	__DEBUG__("return (EXIT_SUCCESS)");
	return (EXIT_SUCCESS);
}
/**********************************************************/
/* End of Program                                         */
/**********************************************************/
