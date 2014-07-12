#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void parse_env(char *s);
void dump_env(char *env[]);

int main(int argc, char *argv[], char *env[])
{
    char *p1;
    char *p2;

    dump_env(env);

    /*
    for (int ii=0; env[ii] != NULL; ii++) {
	// printf("env[%d] = [%s]\n", ii, env[ii]);
	p1 = env[ii];
	p2 = strchr(env[ii], '=') ;
	env[ii][p2-p1] = '\0';
	p2++;
	printf("[%32s] = [%s]\n", p1, p2);
	parse_env(env[ii]);
    }
	*/
}

void parse_env(char *s)
{
int ii = 0;
char *last, *tok[64];

tok[ii++] = strtok(s, "=");
while (tok[ii++] = strtok(NULL, "=")) ;

printf("[%32s] = [%s]\n", tok[0], tok[1]);
}

#ifdef A
void dump_env(char *env[])
{
    char *key[1024];
    char *val[1024];

    int  key_max = 0;
    int  val_max = 0;
    int  env_siz = 0;
    int  ii;

    for (ii =0; env[ii] != NULL; ii++)
    {
	key[ii] = strtok( env[ii], "=" );
	key_max = key_max < strlen(key[ii]) ? strlen(key[ii]) : key_max;
	val[ii] = strtok( NULL   , "=" );
	val_max = val_max < strlen(val[ii]) ? strlen(val[ii]) : val_max;

	env_siz++;
    }
    for (ii = 0; ii < env_siz; ii++) 
	printf("[%03d][%*s] = [%s]\n", ii, key_max, key[ii], val[ii]);
}
#endif

void dump_env(char *env[])
{
    char *key[512], *val[512];
    int  key_max=0;

    /* search max length of key */
    for (int ii=0, jj=0; env[ii] != NULL; ii++)
    {
	key[ii] = strtok( env[ii], "=" );
	jj = strlen(key[ii]);
	key_max = key_max < jj ? jj : key_max;

	val[ii] = strtok( NULL   , "=" );
    }

    key_max+=2;
    /* dump key and val pairs */
    for (int ii=0; env[ii] != NULL; ii++) 
    {
	printf("[%*s] = [%s]\n", key_max, key[ii], val[ii]);
    }
}
