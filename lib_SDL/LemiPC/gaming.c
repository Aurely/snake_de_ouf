/*
** gaming.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:13:08 2015 Aurélie LAO
** Last update Sun Mar  8 16:16:39 2015 Aurélie LAO
*/

#include "lemipc.h"

int		move(t_data *d, t_champ *c)
{
  int		random;

  random = 0;
  if (get_free(d, c->x - 1, c->y) == 0 || get_free(d, c->x + 1, c->y) == 0 ||
      get_free(d, c->x, c->y - 1) == 0 || get_free(d, c->x, c->y + 1) == 0)
    {
      while (1)
	{
	  random = rand() % 4;
	  if (random == 0 && get_free(d, c->x - 1, c->y) == 0)
	    return (set_posc(d, c, c->x - 1, c->y));
	  else if (random == 1 && get_free(d, c->x + 1, c->y) == 0)
	    return (set_posc(d, c, c->x + 1, c->y));
	  else if (random == 2 && get_free(d, c->x, c->y - 1) == 0)
	    return (set_posc(d, c, c->x, c->y - 1));
	  else if (random == 3 && get_free(d, c->x, c->y + 1) == 0)
	    return (set_posc(d, c, c->x, c->y + 1));
	}
    }
  return (0);
}

int		play(t_data *d, t_champ *c)
{
  if (full(d) == -1)
    return (-1);
  while (get_pos(d, (c->x = rand() % 60), (c->y = rand() % 60)) != '0')
    ;
  set_pos(d, c, c->team);
  sleep(1);
  while (finish(d, 0, 0, 0) == -1)
    {
      op_sem(d, -1);
      if (recv_sdl(d) == 0 || check_eated(d, c) > 0)
	{
	  op_sem(d, 1);
	  return (set_pos(d, c, '0'));
	}
      move(d, c);
      usleep(600);
      op_sem(d, 1);
    }
  set_pos(d, c, '0');
  send_msg(d, c->team, 1);
  return (0);
}
