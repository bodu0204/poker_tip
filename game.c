#include "poker_tip.h"
#define ENTRY 1
#define BET 0
#define DROP 1
#define CALL 2

void	settle(int	winer, player	*p, int	pn);
int		det_geme(player	*p, int	pn);

void	game(player	*p, int	pn)
{
	int		win;
	int		i;
	char	*s[32];

	o_clear();

	/* 参加費 */
	i = 0;
	while (i < pn)
	{
		(p + i)->wallet -= ENTRY;
		(p + i)->table += ENTRY;
		i++;
	}

	o_start();

	/* 1回戦目 */
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}

	o_change();
	read(0, s, 32);

	/* 2回戦目 */
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}

	/* カードオープン */
	o_battle();
	win = 0;
	while (!win)
	{
		i = read(0, s, 32);
		s[i - 1] = '\0';
		i = 0;
		while (i < pn)
		{
			if (!strcmp(s, (p + i)->name))
				win = i + 1;
			i++;
		}
		i = atoi(s);
		if(!win && i > 0 && i <= pn)
			win = i;
	}
	settle(win - 1, p, pn);
	return;
}

int		det_geme(player	*p, int	pn)
{
	int		i;
	int		ii;
	char	s[32];
	int		drop;

	while (1)
	{
		i = 0;
		while (i < pn && drop != pn - 1)
		{
			if ((p + i)->declare != DROP || (p + i)->wallet)
			{
				/* 未完 */
				o_choice(p, i);
				ii = read(0, s, 32);
				s[ii - 1] = '\0';
				if (ii == 1 || !strcmp(s, "c") || !strcmp(s, "C") || !strcmp(s, "call") || !strcmp(s, "Call") || !strcmp(s, "CALL") || !strcmp(s, "0"))
				{
					(p + i)->declare = CALL;
				}
				/* 未完\0 */
			}
			i++;
		}
		i = 0;
		if (drop == pn - 1)
		{
			while (i < pn && (p + 1)->declare != DROP)
				i++;
			return (i + 1);
		}
		while ((p + 1)->declare == DROP || (p + 1)->declare == CALL)
		{
			i++;
			if (i == pn)
				return (0);
		}
	}
}
