#include <stdio.h>
#include <libgen.h>
#include <string.h>

char gc_src[256] = "/home/ssenk/bb/lgtar/v200_0/ac/src/barcbi07t.c";
char gc_dst[256];

char *basename2(char *b, char *f, char *e)
{
    char *s = b;
    char *n = basename(f);
    char *p = strrstr(n, e);

    size_t l = (p==NULL) ? strlen(n) : ((p==n) ? strlen(n) : p - n);

    if (!s) s = strdup(n);

    strncpy(s, n, l);
    s[l] = '\0';

    return s;
}

int main(int argc, char **argv)
{
    strncpy(gc_dst, gc_src, strrstr(gc_src, ".c") - gc_src);	
    memset(gc_dst, 0x00, sizeof(gc_dst));

    printf("[%s:%04d] <<%s>>\n", __FILE__, __LINE__, __FUNCTION__);

    printf("%s ===> %s\n", gc_src, basename2(     0, gc_src, ".ppc"));
    printf("%s ===> %s\n", gc_src, basename2(gc_dst, gc_src, ".c"));
    printf("%s ===> %s\n", gc_src, basename2(gc_dst, gc_src, ""));
    printf("%s ===> %s\n", gc_src, basename2(gc_dst, gc_src, ".c"));
    printf("%s ===> %s\n", gc_src, basename2(     0, gc_src, ".c"));
}
