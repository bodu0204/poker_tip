#include "poker_tip.h"

int	i_str(char *s)
{
	int	l;
	int	e;

	bzero(s, BUFFER);
	l = read(0, s, BUFFER);
	e = 0;
	while (s[BUFFER - 1] != '\0' || e)
	{
		e = 1;
		if (s[BUFFER - 1] == '\0')
		{
			bzero(s, BUFFER);
			return (-1);
		}
		bzero(s, BUFFER);
		read(0, s, BUFFER);
	}
	s[l - 1] = '\0';
	return (l);
}

int	i_pn(void)
{
	int	pn;

	while (1)
	{
		pn = i_n("How many playrs? :");
		if (pn < 2)
			write(1, "Too few people!\n", 16);
		else if (pn > 4)
			write(1, "Too many people!\n", 17);
		else
		{
			printf("%d people. OK\n", pn);
			break;
		}
	}
	return (pn);
}

int	i_tips(void)
{
	int	tips;

	while (1)
	{
		tips = i_n("How many tips per person? :");
		if (tips < 1)
			printf("Too few tips!\n");
		else if (tips > 101)
			printf("Too many tips!\n");
		else
		{
			printf("%dtips.OK\n", tips);
			break;
		}
	}
	return (tips);
}

void	i_name(player	*p, int	pn)
{
	int		i;
	int		ii;
	int		iii;
	int		j;
	char	s[BUFFER];

	i = 0;
	while (i < pn)
	{
		while (1)
		{
			write(1, (p + i)->name, BUFFER);	write(1, ", What your name?:", 18);
			bzero(s, BUFFER);
			iii = i_str(s);
			if (iii != -1)
			{
				ii = 0;
				j = 1;
				while (j > 0 && ii < i)
				{
					j *= !(!(strcmp(s, (p + ii)->name)));
					ii++;
				}
				if (j)
				{
					bzero((p + i)->name, BUFFER);
					strcpy((p + i)->name, s);
					printf("Welcome, %s!\n", (p + i)->name);
					break;
				}
			}
			printf("You can't use this name.\n");
		}
		write(1, "\n", 1);
		i++;
	}
}

int	i_n(char	*msg)
{
	int		l;
	int		sl;
	char	s[BUFFER];

	if (msg)
		sl = strlen(msg);
	while (1)
	{
		if (msg)
			write(1, msg, sl);
		l = i_str(s);
		if (l == -1 || l > 10)
			write(1, "Too long!\n", 10);
		else if (isdigit_str(s))
			break;
		else
			write(1, "Input number!\n", 14);
	}
	return (atoi(s));
}
