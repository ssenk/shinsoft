#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
    char lca1[] = "ABCDEFGH";
    char lca2[8];
    char lca3[] = "ZZZZZZZZ";

    memcpy(lca2, lca1, 8);

    printf("lca1 = [%s]\n", lca1);
    printf("lca2 = [%s]\n", lca2);
    printf("lca2 = [%.8s]\n", lca2);
    printf("lca2 = [%.6s]\n", lca2);
}
