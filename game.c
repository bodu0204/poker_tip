#include "poker_tip.h"
#define DROP 1
#define CALL 2

void	settle(int	winer, player	*p, int	pn);
int		det_geme(player	*p, int	pn);

void	game(player	*p, int	pn)
{
	int		win;
	int		i;
	char	*s[32];

	d_clear();
	d_start();
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}
	d_change();
	read(0, s, 32);
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}
	d_battle();
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
	int	i;
	int	drop;

	while (1)
	{
		i = 0;
		while (i < pn && drop != pn - 1)
		{
			/* それぞれに賭けさせる */
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
