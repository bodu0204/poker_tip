#include <stdio.h>

#include "poker_tip.h"

int	i_str(char *s)
{
	int	l;
	int	e;

	l = read(0, s, 32);
	e = 0;
	while (s[31] != '\0' || e)
	{
		e = 1;
		if (s[31] == '\0')
		{
			bzero(s, 32);
			return (-1);
		}
		bzero(s, 32);
		read(0, s, 32);
	}
	s[l - 1] = '\0';
	return (l);
}
