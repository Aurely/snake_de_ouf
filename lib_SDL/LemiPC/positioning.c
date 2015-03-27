/*
** positioning.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:12:17 2015 Aurélie LAO
** Last update Sun Mar  8 16:17:11 2015 Aurélie LAO
*/

#include "lemipc.h"

int		get_free(t_data *d, int x, int y)
{
  if (x >= 0 && x <= 59 && y >= 0 && y <= 59)
    {
      if (((char*)d->map)[y * 60 + x] == '0')
	return (0);
    }
  return (-1);
}

char		get_pos(t_data *d, int x, int y)
{
  return (((char*)d->map)[y * 60 + x]);
}

int		set_posc(t_data *d, t_champ *c, int x, int y)
{
  ((char*)d->map)[c->y * 60 + c->x] = '0';
  c->x = x;
  c->y = y;
  ((char*)d->map)[y * 60 + x] = c->team;
  return (0);
}

int		set_pos(t_data *d, t_champ *c, char team)
{
  ((char*)d->map)[c->y * 60 + c->x] = team;
  return (0);
}
