#include <stdlib.h>
#include <string.h>
#include <langtypes.h> /* UInt32 */
#include <math.h>      /* fabs, lround */

void printfloat(float f)
{
    UInt32 t;
    char temp[35], bin[35];

    t = *(UInt32 *)&f;

    memset(temp, '0', 35);
    strncpy(bin , ultostr(t, 2), sizeof(bin));
    strcpy(temp+32 - strlen(bin), bin);

    bin[0] = temp[0];
    bin[1] = ' ';
    strncpy(bin+2,temp+1,8);

    bin[10] = ' ';
    strncpy(bin+11, temp+9, 8);

    printf("실  수=%f(%s), ", f, bin);

    printf("지수부=%d\n", (t>>23 & 0xff) - 127);

}

int fcmp(double a, double b)
{
//    return fabs(a-b) < EPSILON;
    return fabs(a-b);
}

char *to_binary(void *p, size_t s)
{
    unsigned char  uc = 0;
    unsigned short us = 0;
    unsigned int   ui = 0;
    unsigned long  ul = 0;
    static char *buff;

    buff = buff ? buff : malloc(s);
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

void dump_binary(void *p, size_t s)
{
    char dump[256+1];
    char temp[256+1];
    unsigned char  uc = 0;
    unsigned short us = 0;
    unsigned int   ui = 0;
    unsigned long  ul = 0;
    int ii;

    memset(dump, 0x00, sizeof(dump));
    memset(temp, 0x00, sizeof(dump));

    switch(s) {
    case 1:
        uc = *(unsigned char  *)p;
        sprintf(dump, "%08s", ltostr(uc, 2));
	break;
    case 2:
        us = *(unsigned short *)p;
        sprintf(dump, "%016s", ultostr(us, 2));
	break;
    case 4:
        ui = *(unsigned int   *)p;
        sprintf(dump, "%032s", ultostr(ui, 2));
	break;
    case 8:
        ul = *(unsigned long  *)p;
        sprintf(dump, "%064s", ultostr(ul, 2));
	break;
    case 16:
        ul = *(unsigned long  *)p;
        sprintf(dump, "%064s", ultostr(ul, 2));
        ul = *(((unsigned long  *)p)+1);
        sprintf(dump+64, "%064s", ultostr(ul, 2));
	break;
    }

    for(ii=0; ii<6; ii++) temp[ii] = ' ';
    for(ii=0; ii<s*8; ii++)
    {
	temp[ii+6] = (ii+1)/10>9 ? 'A' - 10 + (ii+1)/10 : '0' + (ii+1)/10;
    }
    temp[ii+6] = '\0';
    puts(temp);
    for(ii=0; ii<s*8; ii++)
    {
	temp[ii+6] = '0' + ((ii+1)%10);
    }
    temp[ii+6] = '\0';
    puts(temp);
    sprintf(temp, "[%2d] [%s]\n", s, dump);
    puts(temp);
}

int main(int argc, char *argv[])
{
    char  c = -1;
    short s = -1;
    int   i = -1;
    long  l = -1;
    float f = -1.0f;
    double       d = -1.0;
    long double  q = -1.0;

    double md = 1.0e16;
    double md2;
    double d201 = 2.01;

    for(double db = 0; db < 100; db++)
    {
	double d = db / 100 * 100;
	    printf("%.16f = %.16f %.16f\n", db, d, fabs(db-d));
    }

    if (md == md+1)
    {
	md2 = md+1;
        printf("%.16f(1.0e16)가 %.16f + 1와 같다\n", md, md);
	dump_binary(&md,  sizeof(md));
	dump_binary(&md2, sizeof(md2));
    }

    printf("d201 = %.2f => (int)(d201*100) = %d\n", d201, (int)(d201 * 100));

    dump_binary(&c, sizeof(c));
    dump_binary(&s, sizeof(s));
    dump_binary(&i, sizeof(i));
    dump_binary(&l, sizeof(l));
    dump_binary(&f, sizeof(f));
    dump_binary(&d, sizeof(d));
    dump_binary(&q, sizeof(q));

    printf("%2d ==> [%s] \n", sizeof(c), to_binary(&c, sizeof(c)));
    printf("%2d ==> [%s] \n", sizeof(s), to_binary(&s, sizeof(s)));
    printf("%2d ==> [%s] \n", sizeof(i), to_binary(&i, sizeof(i)));
    printf("%2d ==> [%s] \n", sizeof(l), to_binary(&l, sizeof(l)));
    printf("%2d ==> [%s] \n", sizeof(f), to_binary(&f, sizeof(f)));
    printf("%2d ==> [%s] \n", sizeof(d), to_binary(&d, sizeof(d)));
    printf("%2d ==> [%s] \n", sizeof(q), to_binary(&q, sizeof(q)));

    printfloat(f);
}
