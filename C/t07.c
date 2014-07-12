#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACRO_TEST(alias) \
      (*alias).f1 \
    , (*alias).f2 \
    , (*alias).f3

typedef struct st_f123 {
    int f1;
    char f2[1024];
    char f3[1024];
} t_f123_s;

t_f123_s A;

int main(int argc, char **argv)
{
    t_f123_s B;

    sprintf(A.f2, "%s", "테스트데이터A");
    sprintf(A.f3, "%s", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    memset(&B, 0x00, sizeof(t_f123_s));
    sprintf(B.f2, "%s", "테스트데이터B");
    sprintf(B.f3, "%s", "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");

    printf("MACRO_TEST(A)[%d] = (%d, %s, %s)\n", sizeof(A), MACRO_TEST(&A));
    printf("MACRO_TEST(B)[%d] = (%d, %s, %s)\n", sizeof(B), MACRO_TEST(&B));
}
