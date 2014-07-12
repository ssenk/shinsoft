#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>                         /* basename                      */
#include <time.h>

/*---------------------------------------------------------------------------*/
/*  CONSTANTS DEFINITION                                                     */
/*---------------------------------------------------------------------------*/
#define __LOCAL_DEBUG__
#define __LOCAL_DEBUG_DETAIL__
#ifdef  __LOCAL_DEBUG__
#define __DEBUG__(fmt, ...) { \
    char     m[2048]; time_t   t; char     dt[20] = { 0x00, }; \
    time(&t); strftime(dt, sizeof(dt),"%G-%m-%d %H:%M:%S", localtime(&t)); \
    snprintf(m, sizeof(m), "[%s:%05d] %s <<%s>> - " ## fmt ## "\n", basename(__FILE__), __LINE__, dt, __FUNCTION__, ##__VA_ARGS__); \
    printf("%s", m); \
    fflush(NULL); \
}
#else
#define __DEBUG__(...)
#endif  /* __LOCAL_DEBUG__ */

#ifndef SETSTRUCT
#define SETSTRUCT(S, V)  memset(&(S), (V), sizeof(S))
#endif  /* SETSTRUCT */

#ifndef SETPSTRUCT
#define SETPSTRUCT(P, T, V)  memset((P), (V), sizeof(T))
#endif  /* SETPSTRUCT */

#ifndef SUCCESS
#define SUCCESS 1
#endif  /* SUCCESS */

#ifndef FAILURE
#define FAILURE 0
#endif  /* FAILURE */

static int  Dump_environ( void );

void dump_environ(void);

int main(int argc, char **argv, char **env)
{
    char *key, *val;

    dump_environ();
    Dump_environ();
/*
    while( *environ )
    {
    key = strtok_r(*environ++, "=", &val);
    //printf("%s\n", *environ++);
    printf("%-*s=%s\n>>>%s<<<\n", 16, key, val, *env++);
    }
    */
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


/******************************************************************************
*                                                                             *
*     �Լ��� : Dump_environ                                                   *
*                                                                             *
*       ���� : �Է��ĸ�����Dump                                               *
*                                                                             *
*     �ۼ��� : ������                                                         *
*                                                                             *
*     �ۼ��� : 2011/05/05                                                     *
*                                                                             *
*   �Ķ���� : IN/OUT  PARAM NAME    TYPE            DESCRIPTION              *
*              ------  ----------    --------------  ------------------------ *
*                                                                             *
*     ���ϰ� : TRUE  : SUCCESS                                                *
*              FALSE : FAILURE                                                *
*                                                                             *
******************************************************************************/
static int  Dump_environ( void )
{
    char    **env   = environ;

    __DEBUG__("Start");

#ifdef __LOCAL_DEBUG_DETAIL__
    puts("------------------- Dupm : environ ---------------------");
    for (;*env;)
    {
        puts( *env++ );
    }
    puts("-------------------------------------------------------");
#endif  /* __LOCAL_DEBUG_DETAIL__ */

    return (SUCCESS);
}
