/*
 * t45.c
 *
 *  Created on: 2011. 6. 12.
 *      Author: Andrew
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>

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

#define LOG(fmt, ...) { \
	logs(__FILE__, __FUNCTION__, __LINE__, ""fmt, ##__VA_ARGS__); \
}
#define LOG2(fmt, ...) { \
    time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%Y-%m-%d %H:%M:%S", localtime(&t)); \
	logs2("[%s:%05d] %s <<%s>> "fmt"\n", BASENAME(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
}

void logs(const char *pFile, const char *pFunction, int pLine, char *fmt, ...)
{
	va_list varg;
	time_t t;
	char ca[20];

	time(&t), strftime(ca, sizeof(ca), "%Y-%m-%d %H:%M:%S", localtime(&t));
	va_start(varg, fmt);
	printf("[%s:%05d] %s <<%s>> ", BASENAME(pFile), pLine, ca, pFunction);
	vprintf(fmt, varg);
	puts("");
	fflush(0);
	va_end(varg);
}

void logs2(char *fmt, ...)
{
	va_list varg;
	va_start(varg, fmt);
	vprintf(fmt, varg);
	fflush(0);
	va_end(varg);
}

typedef struct context_t context_t;
struct context_t
{
	int version;
	context_t *next;
	char file[PATH_MAX];
	char name[PATH_MAX];
	char *c1;
	const char *c2;
	char const *c3;
};

context_t *ctxp;
char c0[] = "ABC_c0_HIX";
char c1[] = "ABC_c1_HIX";
char c2[] = "ABC_c2_HIY";
char c3[] = "ABC_c3_HIZ";

void test(char const *c0, const char *c1, char * const c2, char * c3)
{
	__DEBUG__("Start");
	__DEBUG__("c0 = %s", c0);
	c0++;
	//c0[0] = 'T'; //error: assignment of read-only location '*c1'
	__DEBUG__("c1 = %s", c1);
	c1++;
	//c1[0] = 'T'; //error: assignment of read-only location '*c1'
	__DEBUG__("c2 = %s", c2);
	//c2++; //error: increment of read-only location 'c2'
	c2[0] = 'T';
	__DEBUG__("c3 = %s", c3);
	c3++;
	c3[0] = 'T';
	__DEBUG__("c1 = %s", c1);
	__DEBUG__("c2 = %s", c2);
	__DEBUG__("c3 = %s", c3);
	__DEBUG__("Return");
}

int main(int argc, char **argv)
{
	context_t ctx =
	{ 1, 0, __FILE__, "batch" };
	__DEBUG__("Start");
	ctxp = &ctx;

	(*ctxp).c1 = c1;
	(*ctxp).c2 = c2;
	(*ctxp).c3 = c3;

	__DEBUG__("%s> %s", ctx.name, ctx.file);
	__DEBUG__("%s.c1 = %s", ctx.name, (*ctxp).c1);
	(*ctxp).c1[0] = 'X';
	__DEBUG__("%s.c2 = %s", ctx.name, (*ctxp).c2);
	(*ctxp).c2 = c3;
	__DEBUG__("%s.c3 = %s", ctx.name, (*ctxp).c3);
	(*ctxp).c3 = c2;

	__DEBUG__("%s.c1 = %s", ctx.name, (*ctxp).c1);
	__DEBUG__("%s.c2 = %s", ctx.name, (*ctxp).c2);
	__DEBUG__("%s.c3 = %s", ctx.name, (*ctxp).c3);

	test(c0, c1, c2, c3);
	__DEBUG__("%d", 333);
	logs(__FILE__, __FUNCTION__, __LINE__,
			"---------------------------------------------------------");
	LOG("%d", 333);
	LOG2("%d", 333);
	LOG2();

	__DEBUG__("%s.c1 = %s", ctx.name, (*ctxp).c1);
	__DEBUG__("%s.c2 = %s", ctx.name, (*ctxp).c2);
	__DEBUG__("%s.c3 = %s", ctx.name, (*ctxp).c3);

	__DEBUG__("Return");
	return (EXIT_SUCCESS);
}
