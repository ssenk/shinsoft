/*
 * t43.c
 *
 *  Created on: 2011. 6. 6.
 *      Author: Andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>

void ctrl_c(int);

void ctrl_c(int pi)
{
	static int called = 0;
	signal(SIGINT, SIG_IGN);
	called++;
	if (called > 3)
		exit(1);
	else
	{
		if (signal(SIGINT, ctrl_c) == SIG_ERR)
			puts("Cann't set SIGINT");
	}
}

int main(void)
{
	if (signal(SIGINT, ctrl_c) == SIG_ERR)
		puts("Cann't set SIGINT");
	while (1)
	{
		putchar('#');
	}
	return EXIT_SUCCESS;
}
