/*
** is_eat.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:07:14 2015 Aurélie LAO
** Last update Sun Mar  8 16:16:44 2015 Aurélie LAO
*/

#include "lemipc.h"

int		check_eated2(t_data *d, t_champ *c, char team)
{
  int		pos;
  char		*map;
  int		nbr;

  pos = c->y * 60 + c->x;
  map = ((char*)d->map);
  nbr = 0;
  if (pos - 61 > 0 && map[pos - 61] == team)
    ++nbr;
  if (pos - 60 > 0 && map[pos - 60] == team)
    ++nbr;
  if (pos - 59 > 0 && map[pos - 59] == team)
    ++nbr;
  if (pos - 1 > 0 && map[pos - 1] == team)
    ++nbr;
  if (pos + 1 < 3600 && map[pos + 1] == team)
    ++nbr;
  if (pos + 61 < 3600 && map[pos + 61] == team)
    ++nbr;
  if (pos + 60 < 3600 && map[pos + 60] == team)
    ++nbr;
  if (pos + 59 < 3600 && map[pos + 59] == team)
    ++nbr;
  return ((nbr >= 2) ? (nbr) : (0));
}

int		check_eated(t_data *d, t_champ *c)
{
  int		nbr;

  nbr = 0;
  nbr = max(nbr, check_eated2(d, c, '1'));
  nbr = max(nbr, check_eated2(d, c, '2'));
  nbr = max(nbr, check_eated2(d, c, '3'));
  nbr = max(nbr, check_eated2(d, c, '4'));
  return (nbr);
}
