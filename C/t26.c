#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define MALLOC_HASH_KEY
#define MALLOC_HASH_VAL
#define HASH_SIZ 1024

int main( int argc, char **argv, char **env)
{
    ENTRY item, *result;

    char buf[1024];
    char key[256];
    char val[256];
    char *p;

    /* Hash Create */
    hcreate(HASH_SIZ);

    for (int ii=0; ii<HASH_SIZ; ii++)
    {
#ifdef MALLOC_HASH_KEY
	sprintf(buf, "%d", ii);
	p = malloc(strlen(buf)+1);
	strcpy(p, buf);
	item.key = p;
#else   /* MALLOC_HASH_KEY */
	sprintf(key, "%d", ii);
        item.key = key;
#endif  /* MALLOC_HASH_KEY */

#ifdef MALLOC_HASH_VAL
	sprintf(buf, "value %d", ii);
	p = malloc(strlen(buf)+1);
	strcpy(p, buf);
	item.data = p;
#else   /* MALLOC_HASH_VAL */
	sprintf(val, "value %d", ii);
	item.data = val;
#endif  /* MALLOC_HASH_VAL */

        /* Hash.Add() */
        hsearch(item, ENTER);
    }

    item.key = "66";
    /* Hash.Get() */
    if (result = hsearch( item, FIND ))
	printf("%s key data is \"%s\"\n", (*result).key, (char *)(*result).data);

    strcpy(val, "###########");

    item.key = "66";
    /* Hash.Get() */
    if (result = hsearch( item, FIND ))
	printf("%s key data is \"%s\"\n", (*result).key, (char *)(*result).data);

    /* Hash.Delete() */
    hdestroy(); 
}
