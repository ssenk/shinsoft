#include <stdio.h>
#include <string.h>

#define BUF_SZ 10
typedef char * t_sz;

void f_output(size_t sz, t_sz arr[])
{
    for(int ii=0; ii< sz; ii++)
	printf("array[%02d] => %s\n", ii, arr[ii]);
}

int main(int argc, char**argv)
{
    int  iarray[] = { 1, 2, 3, 4, 5, 6, };
    
    t_sz array[] = { "ABC", "CDKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaSJFLDSJ", "EF@$@$@#", };

    printf("size of iarray is %02d\n", sizeof(iarray)/sizeof(int));
    printf("size of array is %02d\n", sizeof(array) / sizeof(t_sz));

    f_output(sizeof(array)/sizeof(t_sz), array);
}
