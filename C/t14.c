#include <stdio.h>
#include <string.h>

int func(int arr[10])
{
    printf("func.sizeof(arr) = [%d]\n", sizeof(arr));
    for (int ii=0; ii<10; ii++)
        arr[ii] = ii;

    return 0;
}

int main(int argc, char *argv[])
{
    int arr[10] = {0, };

    printf("main.sizeof(arr) = [%d]\n", sizeof(arr));

    for (int ii=0; ii<10; ii++)
	printf("arr[%d] = %d\n", ii, arr[ii]);
    func(arr);
    for (int ii=0; ii<10; ii++)
	printf("arr[%d] = %d\n", ii, arr[ii]);
}
