#ifndef POKER_TIP
#define POKER_TIP

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER 32

#define MAX_PEOPLE 4

#define DROP -2
#define ALLIN -1
#define CALL 0
#define BET 1

typedef struct
{
	char name[BUFFER];
	int wallet;
	int table;
	int declare;
} player;

int		i_str(char	*s);
int		i_pn(void);
int		i_tips(void);
void	i_name(player	*p, int	pn);
int		i_n(char	*msg);
int		i_choice(int	rate, player	*p, int pi);


void	o_clear(void);
void	o_continue(void);
void	o_exit(void);
void	o_start(void);
void	o_change(void);
void	o_battle(void);

int	isdigit_str(char *s);

void	game(player	*p, int	pn);


#endif
