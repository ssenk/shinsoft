/**
 *   Filename : t46.c
 * Created on : 2011. 6. 12.
 *     Author : Andrew
 *    Project : t46
 *    License :
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

int main(int argc, char **argv)
{
	context_t context =	{ 1, "t46", argc, argv, environ, __FILE__ };
	ctx = &context;

	__DEBUG__("started with context");

	if( (*ctx).version == 1 and (*ctx).next == 0)
	{
		__DEBUG__("context.version = 1");
	}
	__DEBUG__("return (EXIT_SUCCESS)");
	return (EXIT_SUCCESS);
}