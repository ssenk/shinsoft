#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define INT_PRINTF(fmt, v) \
    printf("value = [%d], format = [\"%s\"], output ===> [" ## fmt ## "]\n", (v), (fmt), (v));

#define DBL_PRINTF(fmt, v) \
    printf("value = [%f], format = [\"%s\"], output ===> [" ## fmt ## "]\n", (v), (fmt), (v));

int main(int argc, char *argv[])
{
    int d = 10;
    float f = 123.12345;
    long double ld = 123.12345;

    INT_PRINTF("%+d", d);
    INT_PRINTF("%+20d", d);
    INT_PRINTF("%-20d", d);
    INT_PRINTF("%-20d", d);
    DBL_PRINTF("%.f", f);

    printf("value = [%.16f], format = [\"%s\"], output ===> [%.f]\n", (f), ("%.f"), (f));
    printf("value = [%.16f], format = [\"%s\"], output ===> [%f]\n", (f), ("%f"), (f));
    printf("value = [%.16f], format = [\"%s\"], output ===> [%.3f]\n", (f), ("%.3f"), (f));
    printf("value = [%.16f], format = [\"%s\"], output ===> [%7.3f]\n", (f), ("%7.3f"), (f));
    printf("value = [%.16f], format = [\"%s\"], output ===> [%2.*f]\n", (f), ("%2.*f"), 2, (f));
    printf("value = [%.16f], format = [\"%s\"], output ===> [%*.*f]\n", (f), ("%*.*f"), 10, 2, (f));

    printf("value = [%.16Lf], format = [\"%s\"], output ===> [%.3Lf]\n", (ld), ("%.3Lf"), (ld));
}
