#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_BILL_ACNT_GRP_NO 100

int main2(int, char *[]);

int main(int argc, char *argv[])
{
    main2(argc, argv);
}

int main2(int argc, char *argv[])
{
    double ld_db1 = 1234567890;
    double ld_db2;

    printf("%.0f mod %d = fmod(%.0f, %d) = %.0f\n"
	   , ld_db1
	   , MAX_BILL_ACNT_GRP_NO
	   , ld_db1
	   , MAX_BILL_ACNT_GRP_NO
	   , fmod(ld_db1, MAX_BILL_ACNT_GRP_NO)
	   );

   return 0;
}
