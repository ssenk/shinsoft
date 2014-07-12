#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>

#define __LOCAL_DEBUG__
#define __LOCAL_DEBUG_DETAIL__
#ifdef  __LOCAL_DEBUG__
#define BASENAME(V) (strrchr((V), '\\') ? strrchr(V, '\\') + 1 : (V))
#define __DEBUG__(fmt, ...) { \
    char     m[2048]; time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%Y-%m-%d %H:%M:%S", localtime(&t)); \
    snprintf(m, sizeof(m), "[%s:%05d] %s <<%s>> - " fmt " ", BASENAME(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
    puts(m); fflush(NULL); \
}
#else
#define __DEBUG__(...)
#endif  /* __LOCAL_DEBUG__ */

typedef struct context context;
struct context {
	int version;
	context *next;
	char file[PATH_MAX];
	char name[PATH_MAX];
	void (*dump)(context *);
	void (*init)(context *);
	void (*log)(context *, char *, ...);
};

void context_dump(context *pctxp)
{
	__DEBUG__("Start");
	__DEBUG__("context.version = [%d]", (*pctxp).version);
	__DEBUG__("context.file    = [%s]", (*pctxp).file);
	__DEBUG__("context.name    = [%s]", (*pctxp).name);
	__DEBUG__("context.next    = [%s]", (*pctxp).next ? (*pctxp).next->name : "NONE");
	__DEBUG__("Return");
}

void context_init(context *pctxp)
{
	__DEBUG__("Start");
	strncpy((*pctxp).file, BASENAME((*pctxp).file), sizeof((*pctxp).file));
	__DEBUG__("Return");
}

void context_log(context *pctxp, char *fmt, ...)
{
	va_list args, p;
	va_start(args, fmt);
	p = args;
	__DEBUG__("Start");
	printf("[%s] %s %d", (*pctxp).name, fmt, va_arg(p, int));
	vprintf(fmt, args);
	puts("");
	va_end(args);
	__DEBUG__("Return");
}

context ctx2  = {1, 0, __FILE__, "ctx2", context_dump, context_init, context_log};
context ctx   = {1, &ctx2, __FILE__, "ctx", context_dump, context_init, context_log};

int main(int argc, char **argv)
{
	__DEBUG__("Start");

	ctx.init(&ctx);
	ctx.dump(&ctx);
	ctx2.dump(&ctx2);
	ctx.log(&ctx, "           %d", 3);

	__DEBUG__("Return");
	return (EXIT_SUCCESS);
}
