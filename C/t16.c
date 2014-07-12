#include <stdio.h>
#include <string.h>

#define STRNCPY(a, b) strncpy((a), (b), strlen((b)))

int main(int argc, char *argv[])
{
    char orig[32 + 1] = "12345678901234567890123456789012";
    char dest[32 + 1];

    memcpy(dest, orig, sizeof(dest));

    printf("dest = [%s]\n", dest);
    strncpy(dest, "ABCD", 4);
    printf("strncpy(dest, \"ABCD\", 4) = [%s]\n", dest);

    memcpy(dest, orig, sizeof(dest));

    printf("dest = [%s]\n", dest);
    strncpy(dest, "ABCD", sizeof(dest));
    printf("strncpy(dest, \"ABCD\", sizeof(dest)) = [%s]\n", dest);

    memcpy(dest, orig, sizeof(dest));

    printf("dest = [%s]\n", dest);
    strncpy(dest, "ABCD", strlen("ABCD"));
    printf("strncpy(dest, \"ABCD\", strlen(\"ABCD\")) = [%s]\n", dest);

    memcpy(dest, orig, sizeof(dest));

    printf("dest = [%s]\n", dest);
    strncpy(dest, "ABCD", sizeof("ABCD"));
    printf("strncpy(dest, \"ABCD\", sizeof(\"ABCD\")=[%d]) = [%s]\n", sizeof("ABCD"), dest);

    memcpy(dest, orig, sizeof(dest));

    printf("dest = [%s]\n", dest);
    STRNCPY(dest, "ABCD");
    printf("STRNCPY(dest, \"ABCD\") = [%s]\n", dest);
}
