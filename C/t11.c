#include <stdio.h>
#include <string.h>

char gc_8bytes[8] = { 0x00, };
char gc_9bytes[9] = "ABCDEFGHI";

int main(int argc, char *argv[])
{
    strncpy(gc_8bytes, gc_9bytes, sizeof(gc_8bytes)-1);

    printf("gc_8bytes = strncpy(gc_8bytes, gc_9bytes, %d) ==> %s\n"
	   "gc_9bytes = %s\n"
	   "strlen(gc_8bytes) = %d\n"
	   "strlen(gc_9bytes) = %d\n"
	   , sizeof(gc_8bytes)-1
	   , gc_8bytes
	   , gc_9bytes
	   , strlen(gc_8bytes)
	   , strlen(gc_9bytes)
	   );

    memset(gc_8bytes, 0x00, sizeof(gc_8bytes));
    strncpy(gc_8bytes, gc_9bytes, sizeof(gc_8bytes)-1);

    printf("gc_8bytes = strncpy(gc_8bytes, gc_9bytes, %d) ==> %s\n"
	   "gc_9bytes = %s\n"
	   "strlen(gc_8bytes) = %d\n"
	   "strlen(gc_9bytes) = %d\n"
	   , sizeof(gc_8bytes)-1
	   , gc_8bytes
	   , gc_9bytes
	   , strlen(gc_8bytes)
	   , strlen(gc_9bytes)
	   );

    memset(gc_8bytes, 0x00, sizeof(gc_8bytes));
    strncpy(gc_8bytes, gc_9bytes, sizeof(gc_8bytes));

    printf("gc_8bytes = strncpy(gc_8bytes, gc_9bytes, %d) ==> %s\n"
	   "gc_9bytes = %s\n"
	   "strlen(gc_8bytes) = %d\n"
	   "strlen(gc_9bytes) = %d\n"
	   , sizeof(gc_8bytes)
	   , gc_8bytes
	   , gc_9bytes
	   , strlen(gc_8bytes)
	   , strlen(gc_9bytes)
	   );
}
