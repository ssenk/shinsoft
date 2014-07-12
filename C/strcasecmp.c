#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv)
{
   int ii;
   for( ii=0; ii < argc; ii++ )
   {
       printf("argv[%d] ==> [%s], strcasecmp(%s, %s) ==> [%d]\n", ii, argv[ii], argv[ii], "UP", strcasecmp(argv[ii], "UP"));
   }
}