#ifndef POKER_TIP
#define POKER_TIP

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
typedef struct
{
    char name[32];
    int wallet;
    int table;
	int declare;
} player;

void	d_clear(void);
void	d_continue(void);
void	d_exit(void);
void	d_start(void);
void	d_change(void);
void	d_battle(void);

void	game(player	*p, int	pn);

#endif
