#include <stdio.h>
#include <string.h>

typedef long status_t;
typedef char char_t;
typedef struct { long id; char name[20]; } tag_t;

static status_t func(void *);

int main(int argc, char *argv[])
{
    status_t status;
    char_t c;
    tag_t tag;

    status =func(&tag);

    return 0;
}

static status_t func(void *p)
{
    tag_t *t = (tag_t *)p;

    printf("sizeof(p) = [%d]\n", sizeof(p));
    printf("sizeof(*(tag_t)p) = [%d]\n", sizeof(*(tag_t *)p));
    printf("tag_t *t = (tag_t *)p;\n");
    printf("sizeof(t) = [%d]\n", sizeof(t));
    printf("sizeof(*t) = [%d]\n", sizeof(*t));

    return (0);
}
