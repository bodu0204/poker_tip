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
	int	i;

	i = n % 32;
	n -= i;
	write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", i);
	while (n)
	{
		write(1, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 32);
		n -= 32;
	}
}

