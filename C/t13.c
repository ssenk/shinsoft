#include <stdio.h>
#include <string.h>

int lf_func();

int main (int argc, char *argv[])
{
    char lc_arr[3][3] = { { '1', '2', '3' }, };

    lf_func(lc_arr);
}

int lf_func(char pc_arr[3][3])
{
    for (int ii=0; ii<3; ii++)
	for (int jj=0; jj<3; jj++)
	    printf("arr[%d][%d] ==> ['%c']\n", ii, jj, pc_arr[ii][jj]);

    return 0;
}
