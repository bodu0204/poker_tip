#include "poker_tip.h"

int main(void)
{
	int pn;
	int tips;
	int j;
	int i;
	int ii;
	int iii;
	char s[32];
	player *p;

	d_clear();
	printf("Settings\n");
	while (1)
	{
		printf("How many playrs? :");	scanf("%d", &pn);
		if (pn < 2)
			printf("Too few people!\n");
		else if (pn > 4)
			printf("Too many people!\n");
		else
		{
			printf("%d people. OK\n", pn);
			break;
		}
	}
	p = malloc(sizeof(player) * pn);
	if (!p)
	{
		printf("System error\n");
		return (0);
	}
	bzero(p, sizeof(player) * pn);
	while (1)
	{
		printf("How many tips per person? :");	scanf("%d", &tips);
		if (tips < 1)
			printf("Too few tips!\n");
		else if (tips > 101)
			printf("Too many tips!\n");
		else
		{
			i = 0;
			while (i < pn)
			{
				(p + i)->wallet = tips;
				memcpy((p + i)->name, "player", 6);
				*(((p + i)->name) + 6) = '1' + i;
				*(((p + i)->name) + 7) = '\0';
				i++;
			}
			printf("%dtips.OK\n", tips);
			break;
		}
	}
	printf("Setting name?(No->Enter)");
	if (read(0, s, 32) > 1)
	{
		bzero(s, 32);
		i = 0;
		while (i < pn)
		{
			while (1)
			{
				printf("player%d, What your name?\n", i + 1);
				iii = read(0, s, 32);
				if (iii < 32)
				{
					s[iii - 1] = '\0';
					ii = 0;
					j = 1;
					while (j > 0 && ii < i)
					{
						j *= !(!(strcmp(s, (p + ii)->name)));
						ii++;
					}
					if (j)
					{
						bzero((p + i)->name, 32);
						strcpy((p + i)->name, s);
						bzero(s, 32);
						printf("Welcome, %s", (p + i)->name);
						break;
					}
				}
				printf("You can't use this name.\n");
			}
			i++;
		}
	}
	do
	{
		game(p, pn);
		i = 0;
		while (i < pn && (p + i)->wallet)
			i++;
		pn = i;
		d_continue();
	}while (read(0, s, 32) < 2);
	free(p);
	d_exit();
	return (0);
}
