#include <stdio.h>

#include "poker_tip.h"
void o_clear(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void o_space(void)
{
	printf("\n\n\n");
}

void o_nline(int n)
{
	write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", n % 16);
	n >>= 4;
	while (n)
	{
		write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 16);
		n--;
	}
}

