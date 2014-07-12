#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define __LOCAL_DEBUG__
#define __LOCAL_DEBUG_DETAIL__
#ifdef  __LOCAL_DEBUG__
#define BASENAME(V) (strrchr((V), '\\') ? strrchr(V, '\\') + 1 : (V))
#define __DEBUG__(fmt, ...) { \
    char     m[2048]; time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%Y-%m-%d %H:%M:%S", localtime(&t)); \
	snprintf(m, sizeof(m), "[%s:%05d] %s <<%s>> - " fmt, BASENAME(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
	puts(m); \
}
#else
#define __DEBUG__(...)
#endif  /* __LOCAL_DEBUG__ */

int main(int argc, char **argv, char **env)
{
    __DEBUG__("Start");
    puts("Hello, C");
    __DEBUG__("Exit");
	return EXIT_SUCCESS;
}
