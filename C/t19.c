#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef union { 
    struct { 
	unsigned int s:1; 
	unsigned int e:8; 
	unsigned int m:23; 
    } ieee; 
    int   i; 
    float f; 
} st_float_t; /* 32 bits */

typedef union { 
    struct { 
	unsigned long s:1;
	unsigned long e:11;
	unsigned long m:52;
    } ieee; 
    long   l; 
    double d; 
} st_double_t; /* 64 bits */

typedef union { 
    struct { 
	unsigned long long s:1;
	unsigned long long e:14;
	unsigned long long m;
    } ieee; 
    long long   ll; 
    long double ld; 
} st_quad_t; /* 128 bits */

char *to_binary(void *p, size_t s);

int main(int argc, char *argv[])
{
    st_float_t    fb;
    st_float_t    f; 
    long          l = 1;

    f.f = -43.25f;
    printf("[%2d] ==> [%s]\n", sizeof(f.f), to_binary(&f.f, sizeof(f.f)));
    printf("[%2d] ==> [%s]\n", sizeof(f.i), to_binary(&f.i, sizeof(f.i)));

    f.f = -43.25f;
    printf("%d<<23 = %d\n", l, l<<23);
    printf("%.16f ==> sign = [%d], exponent = [%d], matissa = [%d]  [%s]\n"
	    , f.f , f.ieee.s, f.ieee.e-127 , f.ieee.m, to_binary(&f.f, sizeof(f.f)));

    f.f = 0.375f;
    printf("%.16f ==> sign = [%d], exponent = [%d], matissa = [%d]  [%s]\n"
	    , f.f , f.ieee.s, f.ieee.e-127 , f.ieee.m, to_binary(&f.f, sizeof(f.f)));



    f.f = 43.55;
    printf("%.16f ==> sign = [%d], exponent = [%d], matissa = [%d]  [%s]\n"
	    , f.f , f.ieee.s, f.ieee.e-127 , f.ieee.m, to_binary(&f.f, sizeof(f.f)));
    fb.i = (23 + 127) << 23; // basis
    f.f += fb.f;
    f.i -= fb.i;
    printf("toInteger()==> [%d]  [%s]\n", f.i, to_binary(&f.f, sizeof(f.f)));

    f.f = -128.532;
    printf("%.16f ==> sign = [%d], exponent = [%d], matissa = [%d]  [%s]\n"
	    , f.f , f.ieee.s, f.ieee.e-127 , f.ieee.m, to_binary(&f.f, sizeof(f.f)));
    fb.i = ((23 + 127) << 23) + (1 << 22); // basis
    f.f += fb.f;
    f.i -= fb.i;
    printf("toInteger()==> [%d]  [%s]\n", f.i, to_binary(&f.f, sizeof(f.f)));


    puts("-------------------------------------------------");
    f.f = 10.5;
    printf("toInteger()==> [%020.16f] [%d][%u][1.%d]  [%s]\n", f.f, f.ieee.s, f.ieee.e-0x7f, f.ieee.m, to_binary(&f.f, sizeof(f.f)));
    f.f = f.f * 100;
    printf("toInteger()==> [%020.16f] [%d][%u][1.%d]  [%s]\n", f.f, f.ieee.s, f.ieee.e-0x7f, f.ieee.m, to_binary(&f.f, sizeof(f.f)));
    f.f = f.f / 100;
    printf("toInteger()==> [%020.16f] [%d][%u][1.%d]  [%s]\n", f.f, f.ieee.s, f.ieee.e-0x7f, f.ieee.m, to_binary(&f.f, sizeof(f.f)));
}


char *to_binary(void *p, size_t s)
{
    unsigned char  uc = 0;
    unsigned short us = 0;
    unsigned int   ui = 0;
    unsigned long  ul = 0;
    static char *buff;

    buff = realloc(buff, s);
    memset(buff, 0x00, s);

    switch(s) {
    case 1:
        uc = *(unsigned char  *)p;
        sprintf(buff, "%08s", ltostr(uc, 2));
	break;
    case 2:
        us = *(unsigned short *)p;
        sprintf(buff, "%016s", ultostr(us, 2));
	break;
    case 4:
        ui = *(unsigned int   *)p;
        sprintf(buff, "%032s", ultostr(ui, 2));
	break;
    case 8:
        ul = *(unsigned long  *)p;
        sprintf(buff, "%064s", ultostr(ul, 2));
	break;
    case 16:
        ul = *(unsigned long  *)p;
        sprintf(buff, "%064s", ultostr(ul, 2));
        ul = *(((unsigned long  *)p)+1);
        sprintf(buff+64, "%064s", ultostr(ul, 2));
	break;
    }

    return buff;
}
