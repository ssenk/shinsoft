/*
 ============================================================================
 Name        : t42.c
 Author      : Andrew
 Version     :
 Copyright   : RKHouse
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>

#define __LOCAL_DEBUG__
#define __LOCAL_DEBUG_DETAIL__
#ifdef  __LOCAL_DEBUG__
#define BASENAME(V) (strrchr((V), '\\') ? strrchr(V, '\\') + 1 : (V))
#define __DEBUG__(fmt, ...) { \
    char     m[2048]; time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%Y-%m-%d %H:%M:%S", localtime(&t)); \
    snprintf(m, sizeof(m), "[%s:%05d] %s <<%s>> - " fmt, BASENAME(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
    puts(m); fflush(NULL); \
}
#else
#define __DEBUG__(...)
#endif  /* __LOCAL_DEBUG__ */

int callee(void);

jmp_buf env;
time_t T0;

int main(int argc, char **argv)
{
	int ret;

	__DEBUG__("Start");

	__DEBUG__("setjmp(env)");

	switch (ret = setjmp(env))
	{
	case 0:
		__DEBUG__("T0 = time(0)");
		T0 = time(0);
		__DEBUG__("call to callee()");
		callee();
		break;
	default:
		__DEBUG__("result of callee [%d]", ret)
		;
		break;
	}

	__DEBUG__("Return");
	return EXIT_SUCCESS;
}


int callee(void)
{
	__DEBUG__("Start");
	long t1 = time(0) - T0;

	__DEBUG__("longjum(env,val)");

	longjmp(env, t1);

	__DEBUG__("Return");
	return 1;
}
