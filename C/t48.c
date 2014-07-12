/**
 ***********************************************************
 *   Filename : t48.c
 * Created on : 2011. 6. 12.
 *     Author : Andrew
 *    Project : t48
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
#include <unistd.h>

#define __LOCAL_DEBUG__
//#define __LOCAL_DEBUG_DETAIL__
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

int icmp(const void *a, const void *b)
{
    return (*(int*) a - *(int*) b);
}

int icmpr(const void *a, const void *b)
{
    return (*(int*) b - *(int*) a);
}

void sort(void *base, size_t nel, size_t size,
        int(**f)(const void *, const void *))
{
    qsort(base, nel, size, *f);
}

void int_array_dump(int *int_array, int max_array)
{
#ifdef __LOCAL_DEBUG_DETAIL__
    int ii;
    __DEBUG__();
    printf("int_array = {");
    for ( ii = 0; ii < max_array; ii++)
        printf("%s%d", (ii>0?", ": ""), int_array[ii]);
    puts("}");
#endif
}

int main(int argc, char **argv)
{
    int *int_array, ii;
    int max_array = 30;
    int(*icmprp)(const void *, const void *);
    int(*(*icmprpp))(const void *, const void *) = &icmprp;

    context_t context = { 1, "t48", argc, argv, environ, __FILE__ };
    ctx = &context;

    __DEBUG__("started with context");

    if (argc == 2) max_array = atoi(argv[1]);
    __DEBUG__("max_array setting ==> [%d]", max_array);

    __DEBUG__("array allocating...");
    int_array = (int *) malloc(sizeof(int) * max_array);

    __DEBUG__("array shuffling...");
    for ( ii = 0; ii < max_array; ii++)
    {
        int_array[ii] = rand()%max_array;
    }

    int_array_dump(int_array, max_array);

    __DEBUG__("array sort by ascending");
    qsort(int_array, max_array, sizeof(int), icmp);

    int_array_dump(int_array, max_array);

    __DEBUG__("array sort by descending");
    icmprp = icmpr;
    sort(int_array, max_array, sizeof(int), icmprpp);

    int_array_dump(int_array, max_array);

    __DEBUG__("return (EXIT_SUCCESS)");
    return (EXIT_SUCCESS);
}
/**********************************************************/
/* End of Program                                         */
/**********************************************************/
