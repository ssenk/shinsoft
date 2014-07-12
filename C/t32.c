#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char gc_str[] = "12345678901234567890123456789012";

int main(int argc, char **argv, char **env)
{
    char lc_str[32];

    printf("sizeof(gc_str) = [%d]\n" , sizeof(gc_str));
    printf("sizeof(lc_str) = [%d]\n" , sizeof(lc_str));

    memset(lc_str, 0x00, sizeof(lc_str));
    memcpy(lc_str, gc_str, sizeof(lc_str));
    printf("gc_str = [%s]\n" , gc_str);
    printf("lc_str = [%s] <=== memcpy(lc_str, gc_str, sizeof(lc_str))\n" , lc_str);

    memset(lc_str, 0x00, sizeof(lc_str));
    snprintf(lc_str, sizeof(lc_str), "%s", gc_str);
    printf("gc_str = [%s]\n" , gc_str);
    printf("lc_str = [%s] <=== snprintf(lc_str, sizeof(lc_str), \"%%s\", gc_str)\n" , lc_str);

    memset(lc_str, 0x00, sizeof(lc_str));
    strncpy(lc_str, gc_str, sizeof(lc_str));
    printf("gc_str = [%s]\n" , gc_str);
    printf("lc_str = [%s] <=== strncpy(lc_str, gc_str, sizeof(lc_str))\n" , lc_str);

    memset(lc_str, 0x00, sizeof(lc_str));
    strncpy(lc_str, gc_str, sizeof(lc_str)-1);
    printf("gc_str = [%s]\n" , gc_str);
    printf("lc_str = [%s] <=== strncpy(lc_str, gc_str, sizeof(lc_str)-1)\n" , lc_str);
}
