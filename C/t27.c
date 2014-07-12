#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv, char **env)
{
    double a = 100.23;
    double b = 10.23;

    printf("%g^%g = %g\n", a, b, pow(a, b));
}

