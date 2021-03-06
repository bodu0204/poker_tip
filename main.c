#include "poker_tip.h"

int main(void)
{
	int pn;
	int tips;
	int i;
	char s[BUFFER];
	player p[MAX_PEOPLE];


	bzero(p, sizeof(player) * MAX_PEOPLE);
	/* d_clear(); */
	printf("Settings\n");
	pn = i_pn();/* 人数の取得 */
	tips = i_tips();/* チップ数の取得 */

	/* 数値の設定 */
	i = 0;
	while (i < pn)
	{
		(p + i)->wallet = tips;
		memcpy((p + i)->name, "player", 6);
		*(((p + i)->name) + 6) = '1' + i;
		*(((p + i)->name) + 7) = '\0';
		i++;
	}

	write(1,"Setting name?(No->Enter)",25);
	if (i_str(s) != 1)
		i_name(p, pn);/* 名前の取得 */
	do
	{
		game(p, pn);
		i = 0;
		while (i < pn && (p + i)->wallet)
			i++;
		pn = i;
		if (pn == 1)
			break ;
		o_continue();
	}while (i_str(s) == 1 && pn != 1);
	o_exit(p);
	return (0);
}
