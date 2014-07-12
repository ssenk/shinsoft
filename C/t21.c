#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int dblcmp(double d1, double d2, size_t sz)
{
    if ((long long)d1 * pow(10, sz) > INT64_MAX)
    {
	perror("overflow!!!");
	exit(1);
    }
    long long l1 = llround(d1 * pow(10,sz));
    long long l2 = llround(d2 * pow(10,sz));

    return (l1-l2);
}


int compare_dbl (double source, double target)
{
    //-------------------------------------------------------------------------
	// 변수 선언
	    //-------------------------------------------------------------------------
		int  status;
		    long src_buf;       // 비교대상금액 버퍼
			long trg_buf;       // 비교할금액 버퍼

			    //-------------------------------------------------------------------------
				// 소수점 두자리까지 비교하기위해 100을 곱한다.
				    //-------------------------------------------------------------------------
					src_buf = source * 100;
					    trg_buf = target * 100;

						//-------------------------------------------------------------------------
						    // 두 값을 비교
							//-------------------------------------------------------------------------
							    if ( src_buf == trg_buf ) status =  0;
								else
								    if ( src_buf >  trg_buf ) status =  1;
									else
									    if ( src_buf <  trg_buf ) status = -1;

										return status;
										}
//#define DBLCMP(d1, d2, x) (lrintl((d1) * 1000000000000000) - lrintl((d2) * 1000000000000000))
//#define DBLCMP(d1, d2) (llrint((d1) * 100) - llrint((d2) * 100))
//#define DBLNCMP(d1, d2, x) (llrint((d1) * pow(10, (x))) - llrint((d2) * pow(10, (x))))

#define COMPARE_DBL(d1, d2) (llrint((d1)) - llrint((d2)) > 0 ? 1 : (llrint((d1)) - llrint((d2)) < 0 ? -1 : 0)) 
#define DBLNCMP(d1, d2, x) (llrint((d1) * pow(10, (x))) - llrint((d2) * pow(10, (x))) > 0 ?  1 :  (\
			    llrint((d1) * pow(10, (x))) - llrint((d2) * pow(10, (x))) < 0 ? -1 : 0))
#define DBLCMP(d1, d2)   DBLNCMP((d1), (d2), 2)


int main(int argc, char *argv[])
{
    double d1 = 2.01;
    double d2 = 2.01 * 100 / 100;

    printf("%.*f\n", 20, d1);
    printf("%.*f\n", 20, d2);
    printf("dblcmp(%.*f, %.*f) = [%d][%d]\n", 2, d1, 2, d2, dblcmp(d1, d2, 2), compare_dbl(d1, d2));

    for(double d1 = 0; d1 < 100; d1++)
    {
        double d2 = d1 / 100 * 100;
        printf("%.16f = %.16f %.16f [%d][%d]\n", d1, d2, fabs(d1-d2), dblcmp(d1, d2, 2), compare_dbl(d1, d2));
    }

    d1 = 29.0;
    d2 = 29.0 / 100 * 100;
    printf("compare_dbl(%.2f, %.2f) = [%d]\n", d1, d2, compare_dbl(d1, d2));

    printf("compare_dbl(%.2f, %.2f) = [%d]\n", d1, d2, dblcmp(d1, d2, 2));

    d1 = 57.0;
    d2 = 57.0 / 100 * 100;
    printf("compare_dbl(%.2f, %.2f) = [%d]\n", d1, d2, compare_dbl(d1, d2));

    printf("dblcmp(%.2f, %.2f) = [%d]\n", d1, d2, dblcmp(d1, d2, 2));
    printf("COMPARE_DBL(%.2f, %.2f) = [%d]\n", d1, d2, COMPARE_DBL(d1, d2));
    printf("DBLCMP(%.2f, %.2f) = [%d]\n", d1, d2, DBLCMP(d1, d2));

    d1 = 57.00001;
    d2 = 57.00002;
    for (int ii=0; ii<10; ii++) 
    {
	long int lli = d1 * pow(10, ii);
	printf("MATH_ERRNO = [%d]\n", MATH_ERRNO);
	printf("[%.*f] [%.16f]\n", ii, d1, d1);
        printf("dblncmp(%.*f, %.*f, %d) = "
	       "[%d]**[%f] "
	       "[%.*f][%lld] "
	       "[%.*f][%lld]\n"
	       , ii, d1, ii, d2 , ii
	       , DBLNCMP(d1, d2, ii), pow(10, ii)
	       , ii, d1*pow(10,ii), llround(d1*pow(10,ii))
	       , ii, d2*pow(10,ii), llround(d2*pow(10,ii))
	       );
    }
}

