/*
** champion.h for  in /home/antune_r/rendu/PSU_2014_lemipc
** 
** Made by Romain Antunes
** Login   <antune_r@epitech.net>
** 
** Started on  Tue Mar  3 14:24:37 2015 Romain Antunes
** Last update Sun Mar  8 16:27:31 2015 Aurélie LAO
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

# define N_TEAM 4
# define N_PLAYER 40
# define T_X 1024
# define T_Y 720
# define max(a, b) (a > b) ? (a) : (b)
# define supp(a) (a > 0) ? (1) : (0)

typedef struct	s_msg
{
  long		mtype;
  char		str[32];
}		t_msg;

typedef	struct	s_data
{
  pid_t		pid;
  key_t		key;
  char		*pwd;
  SDL_Surface	*scr;
  SDL_Surface	*rec;
  SDL_Rect	pos;
  SDL_Event	event;
  int		nbr;
  int		finish;
  int		fail;
  int		can_stop;
  int		shm_id;
  int		sem_id;
  int		msg_id;
  t_msg		msg;
  void		*map;
}		t_data;

typedef struct	s_champ
{
  char		team;
  int		alive;
  int		sdl;
  int		x;
  int		y;
}		t_champ;

void	draw_champion(t_data *sd, int x, int y, char team);
int	init_sdl(t_data *sd);
int	my_aff(t_data *sd, char *map);
int	quit_clean(t_data *d);
int	my_m_aff(t_data *d);
int	move(t_data *d, t_champ *c);
int	play(t_data *d, t_champ *c);
int	check_eated2(t_data *d, t_champ *c, char team);
int	check_eated(t_data *d, t_champ *c);
int	finish(t_data *d, int n1, int n2, int n3);
void	my_putstr_map(char *str);
int	full(t_data *d);
int	recv_sdl(t_data *d);
int	recv_msg(t_data *d);
void	send_msg(t_data *d, char team, long type);
int	create_msgq(t_data *d);
int	get_free(t_data *d, int x, int y);
char	get_pos(t_data *d, int x, int y);
int	set_posc(t_data *d, t_champ *c, int x, int y);
int	set_pos(t_data *d, t_champ *c, char team);
void	op_sem(t_data *d, int ope);
int	delete_sem(t_data *d);
int	create_sem(t_data *d);
int	delete_shm(t_data *d);
int	create_shm(t_data *d);

#endif /* !LEMIPC_H_ */
