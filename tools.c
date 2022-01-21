#include "poker_tip.h"

int	isdigit_str(char	*s)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (s[i])
	{
		j *= !(!(isdigit(s[i])));
		i++;
	}
	j *= !!i;
	return (j);
}
