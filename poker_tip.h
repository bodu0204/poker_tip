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

//input.c
int		i_str(char *s);
int		i_pn(void);
int		i_tips(void);
void	i_name(player	*, int);
int		i_n(char	*);
int		i_choice(int, player	*, int);
int		i_winer(player	*, int);

//output.c
void	o_continue(void);						/* <-未完 */
void	o_exit(player	*);						/* <-未完 */
void	o_clear(void);							/* <-未完 */
void	o_start(void);							/* <-未完 */
void	o_change(void);							/* <-未完 */
void	o_battle(player	*, int);				/* <-未完 */
void	o_drop(void);							/* <-未完 */
void	o_allin(void);							/* <-未完 */
void	o_call(void);							/* <-未完 */
void	o_bet(void);							/* <-未完 */
void	o_winer(player	*, int);				/* <-未完 */
void	o_loser(player	*);						/* <-未完 */
void	o_choice(int, player	*, int);		/* <-未完 */

//tools.c
int		isdigit_str(char *s);

//game.c
void	game(player	*p, int	pn);


#endif
