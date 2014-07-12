#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lf_test(char *, double *);
int main (int argc, char **argv, char **env)
{
    char lc_test[32];
    double ld_test = 0.0;

    strcpy(lc_test, "###############");

    printf("Before lf_test(): lc_test = [%s], ld_test = [%12.6f]\n", lc_test, ld_test);
    lf_test(lc_test, &ld_test);
    printf("After  lf_test(): lc_test = [%s], ld_test = [%12.6f]\n", lc_test, ld_test);
}

void lf_test(char *pc_test, double *pdp_test)
{
    size_t l = strlen(pc_test);
    char lc_test[32];
    double ld_test = 7777.77;

    strcpy(lc_test, "AAAAAAA");

    strncpy(pc_test, lc_test, strlen(lc_test));
    *pdp_test = ld_test;
}
