#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//const char const *echo_cpcc(const char const *p); // #2083-D: type qualifier specified more than once
const char *echo_pcc(const char *p)
{
   static char *ppc = "LLLLLLLLLLLLLL";

   p = ppc;

   *(p+3) = 'K'; // error #2137: expression must be a modifiable lvalue
   return p;
}

char const *echo_cpc(char const *p)
{
   static char *ppc = "MMMMMMMMMMMMMM";

   p = ppc;

   *(p+4) = 'K'; // error #2137: expression must be a modifiable lvalue
   return p;
}


int main(int argc, char *argv[])
{
    char org[1024];
    const char *ccp = org;
    char const *cpc = org;

    strncpy(org, "ABCDEFG", sizeof(org));

    org[1] = 'X';
    printf("org[1] = '%c'; org ==> [%s]\n", org[1], org);

    cpc = &org[1];
    cpc[1] = 'Y';
    printf("cpc[1] = '%c'; org ==> [%s]\n", cpc[1], org);

    ccp = cpc+1;
    ccp[1] = 'Z';
    printf("cpc[1] = '%c'; org ==> [%s]\n", ccp[1], org);

    printf("echo_pcc(%s) == [%s}\n", org, echo_pcc(org));
    printf("echo_cpc(%s) == [%s}\n", org, echo_cpc(org));

}

#ifdef noerror
const char const *echo_cpcc(const char const *p)  // #2083-D: type qualifier specified more than once
{
   *(p+5) = 'K'; // error #2137: expression must be a modifiable lvalue
   return p;
}
#endif
