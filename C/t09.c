#include <stdio.h>
#include <string.h>

#define BUF_SZ 10
typedef char * t_sz;

#define BIAN_C_SZ 8
#define BIAN_C_TSZ 8
typedef long long BIAN_C_T;
#define BIAN_SCALE 0
#define BIAN_C_D(varName) BIAN_C_T varName
#define BIAN_C_D_ARR(varName, arr) BIAN_C_T varName[arr]

typedef char DTV8_C_T;
#define DTV8_C_SZ 8
#define DTV8_C_TSZ 1
#define DTV8_C_L 8
#define DTV8_C_D(varName) DTV8_C_T varName[DTV8_C_SZ]


int main(int argc, char**argv)
{
    char a[] = { "ABC" };
    char b[] = { "DEFG" };
    char c[] = { "HIJKL" };
    char d[] = { "NMO" };
    char a1[8] = "1234567";;
    char a2[8] = "234567";;
    char a3[8] = "34567";;
    char a4[8] = "4567";;
    char *abc[4];
    abc[0] = "ABC";
    abc[1] = "CDE"; 
    abc[2] = "KKK";
    abc[3] = "DDD";

    for(int ii=0; ii<4; ii++)
	printf("abc[%02d] = [%s]\n", ii, abc[ii]);
}
