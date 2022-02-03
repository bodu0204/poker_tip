#include "poker_tip.h"
#define ENTRY 1

void	settle(int	winer, player	*p, int	pn);
int		det_geme(player	*p, int	pn);

void	game(player	*p, int	pn)
{
	int		win;
	int		i;
	char	*s[BUFFER];

	o_clear();
	o_start();

	/* 参加費 */
	i = 0;
	while (i < pn)
	{
		(p + i)->wallet -= ENTRY;
		(p + i)->table += ENTRY;
		if ((p + i)->wallet <= 0)/* チップが足りない人 */
		{
			o_allin();
			(p + i)->table += (p + i)->wallet;
			(p + i)->wallet = 0;
			(p + i)->declare = ALLIN;
		}
		i++;
	}

	/* 1回戦目 */
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}

	o_change();
	i_str(s);
	bzero(s, BUFFER);

	/* 2回戦目 */
	win = det_geme(p, pn);
	if (win)
	{
		settle(win - 1, p, pn);
		return;
	}

	/* カードオープン */
	win = i_winer(p, pn);
	settle(win - 1, p, pn);
	return;
}

int		det_geme(player	*p, int	pn)/* 勝負が付かなければ->0, 勝負がつけば->何番目のプレーヤか */
{
	int		drop;
	int		allin;
	int		call;
	int		rate;
	int		bet;
	int		i;

	drop = 0;
	allin = 0;
	call = 0;
	for (size_t ii = 0; ii < pn; ii++)
		if ((p + ii)->declare == DROP)
			drop++;
		else if ((p + ii)->declare == ALLIN)
			allin++;
		else
			(p + ii)->declare = BET;
	i = 0;
	rate = 0;
	while (drop + call + allin < pn)
	{
		if ((p + i)->declare == BET)/* DROPとALLINの人はスキップ	(CALLの人はいない) */
		{
			bet = i_choice(rate, p, i);		/* i_choice() :プレーヤに選択を訪ねてそれに応じて、drop-> -2, all_in-> -1, call->0, rase->賭け金 */
			if (!rate && bet == DROP)		/* 降りなくていい勝負で降りている人 */
				bet = CALL;
			if (bet + rate >= (p + i)->table + (p + i)->wallet && bet >= 0/* call or rase */)		/* 賭け金が足りていない人 */
				bet = ALLIN;
			switch (bet)		/* それぞれの状況に合わせて処理 */
			{
			case DROP:
				o_drop();
				(p + i)->declare = DROP;
				drop++;
				break;
			case ALLIN:
				o_allin();
				if ((p + i)->table + (p + i)->wallet > rate)
				{
					rate = (p + i)->table + (p + i)->wallet;
					for (size_t ii = 0; ii < pn; ii++)
						if ((p + ii)->declare == CALL)
							(p + ii)->declare = BET;
				}
				(p + i)->table += (p + i)->wallet;
				(p + i)->wallet = 0;
				(p + i)->declare = ALLIN;
				allin++;
				break;
			case CALL:
				o_call();
				(p + i)->wallet -= rate - (p + i)->table;
				(p + i)->table = rate;
				(p + i)->declare = CALL;
				call++;
				break;
			default:
				o_bet();
				rate += bet;
				(p + i)->wallet -= rate - (p + i)->table;
				(p + i)->table = rate;
				for (size_t ii = 0; ii < pn; ii++)
					if ((p + ii)->declare == CALL)
						(p + ii)->declare = BET;
				call = 0;
				break;
			}
		}
		i++;
		i %= pn;
		if (drop == pn - 1)
			return (i + 1);
	}
	return (0);
}

void	settle(int	winer, player	*p, int	pn)
{
	int	sum;

	sum = 0;
	for (size_t i = 0; i < pn; i++)
	{
		sum += (p + i)->table;
		(p + i)->table = 0;
	}
	o_winer(p + winer , sum);
	(p + winer)->wallet += sum;
	for (size_t i = 0; i < pn; i++)/* 負け犬の除名 */
	{
		(p + i)->declare = BET;
		if ((p + i)->wallet == 0)
		{
			o_loser(p + i);
			memmove(p + i, p + i + 1, sizeof(player) * (pn - i - 1));
			pn--;
			bzero(p + pn, sizeof(player));
		}
	}
	return ;
}



















