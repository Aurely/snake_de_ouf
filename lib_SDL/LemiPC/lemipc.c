/*
** lemipc.c for  in /home/antune_r/rendu/PSU_2014_lemipc
** 
** Made by Romain Antunes
** Login   <antune_r@epitech.net>
** 
** Started on  Tue Mar  3 14:32:21 2015 Romain Antunes
** Last update Sun Mar  8 16:14:28 2015 Aurélie LAO
*/

#include "lemipc.h"

int		finish(t_data *d, int n1, int n2, int n3)
{
  char		*map;
  int		nbr;
  int		n4;
  int		nb_sup;

  n4 = 0;
  nb_sup = 0;
  map = (char*)d->map;
  nbr = -1;
  while (map[++nbr] != '\0')
    {
      if (map[nbr] == '1')
	++n1;
      else if (map[nbr] == '2')
	++n2;
      else if (map[nbr] == '3')
	++n3;
      else if (map[nbr] == '4')
	++n4;
    }
  nb_sup += supp(n1);
  nb_sup += supp(n2);
  nb_sup += supp(n3);
  nb_sup += supp(n4);
  return ((nb_sup <= 1) ? (0) : (-1));
}

void		my_putstr_map(char *str)
{
  int		j;

  j = 0;
  while (str[j] != '\0')
    {
      if (j != 0 && j % 60 == 0)
	write(1, "\n", 1);
      write(1, &(str[j]), 1);
      ++j;
    }
  write(1, "\n", 1);
}

int		full(t_data *d)
{
  int		j;

  j = 0;
  while (((char*)d->map)[j] != '\0')
    {
      if (((char*)d->map)[j] == '0')
	return (0);
      ++j;
    }
  return (-1);
}

int		main(int argc, char **argv)
{
  t_data	d;
  t_champ	c;

  srandom(time(NULL));
  if (argc == 1)
    c.team = '1';
  else
    c.team = argv[1][0];
  if (((d.pwd = malloc(sizeof(char) * 1024)) == NULL) ||
      ((getcwd(d.pwd, 1024)) == NULL))
    return (-1);
  d.key = ftok(d.pwd, 0);
  create_shm(&d);
  create_sem(&d);
  create_msgq(&d);
  if (argc == 1 || argv[1][0] != '-')
    play(&d, &c);
  else
    my_m_aff(&d);
  if (d.pwd)
    free(d.pwd);
  return (0);
}
