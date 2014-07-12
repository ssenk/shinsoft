#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    int		i;
    long	l;

    i = 0x0ffff;
    l = i;

    printf("sizeof(int ) = %d, sizeof(i) = %d, i = %d\n", sizeof(int ), sizeof(i), i);
    printf("sizeof(long) = %d, sizeof(l) = %d, l = %d\n", sizeof(long), sizeof(l), l);
}
