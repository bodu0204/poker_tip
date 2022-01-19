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

int	i_str(char *s);


void	o_clear(void);
void	o_continue(void);
void	o_exit(void);
void	o_start(void);
void	o_change(void);
void	o_battle(void);

void	game(player	*p, int	pn);

#endif
