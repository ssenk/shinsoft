#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *artv[], char *envp[])
{
    int size = 1;

    printf("[%08x] [%d] size=1\n", size, size);
    size+=1;
    printf("[%08x] [%d] size+=1\n", size, size);
    size*=2;
    printf("[%08x] [%d] size*=2\n", size, size);
    size<<=1;
    printf("[%08x] [%d] size<<=1\n", size, size);
    size-=1;
    printf("[%08x] [%d] size-=1\n", size, size);
}
