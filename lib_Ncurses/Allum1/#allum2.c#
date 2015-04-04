/*
** allum2.c for allum1 in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Wed Feb  5 16:39:35 2014 lao_e
** Last update Sat Feb 15 14:11:51 2014 lao_e
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "allum.h"

void		init_struct(t_allum *allum)
{
  allum->keycode = 0;
  allum->row = 0;
  allum->line = 0;
}

int		my_underline(char *str, int row, int nb, int i)
{
  while (str[nb])
    {
      if (str[nb] != ' ')
	{
	  my_putstr(tgetstr("us", NULL));
	  if (str[nb] == '|' && row != 0)
	    {
	      my_putchar('x');
	      row--;
	      i++;
	    }
	  else
	    my_putchar(str[nb]);
	  my_putstr(tgetstr("ue", NULL));
	}
      else
	my_putchar(str[nb]);
      nb++;
    }
  return (i);
}

int		print_tab(char **tabl, t_allum *allum, int index)
{
  if (((tgetstr("us", NULL)) == 0) ||
      ((tgetstr("ue", NULL)) == 0))
    {
      my_putstr("Error: tgetstr failed \n");
      return (-1);
    }
  if (my_term_clear() == -1)
    return (-1);
  while (tabl[index])
    {
      if (index == allum->line)
	{
	  if ((allum->row = my_underline(tabl[index], allum->row, 0, 0)) == -1)
	    return (-1);
	  index++;
	}
      else
	my_putstr(tabl[index++]);
      my_putchar(10);
    }
  return (0);
}

int		my_print(char **tabl, char **env)
{
  int		nb;
  int		term_env_line;
  char		*term_name;
  t_allum	allum;

  init_struct(&allum);
  nb = 0;
  if (((term_env_line = my_get_line_env_term(env)) == -1) ||
      ((term_name = my_get_term_name(env[term_env_line])) == NULL))
    return (-1);
  if (my_term_clear() == -1)
    return (-1);
  if ((print_tab(tabl, &allum, 0)) == -1)
    return (-1);
  if (modif_term_mode(term_name, tabl, &allum) == -1)
    return (-1);
}

int		my_read_term(char **tabl)
{
  t_allum	allum1;
  int		nb_allum;

  nb_allum = 0;
  init_struct(&allum1);
  while (allum1.keycode != 27)
    {
      allum1.keycode = 0;
      read(0, &(allum1.keycode), 4);
      my_press_arrow(&allum1, tabl);
      if (print_tab(tabl, &allum1, 0) == -1)
	return (-1);
      if (allum1.keycode == CODE_ENTER)
	{
	  tabl = my_modif_tabl(tabl, &allum1);
	  if ((nb_allum = my_check_allum(tabl, 0, 1)) == 0 || nb_allum == 1)
	    return (0);
	  tabl = my_ia_player(tabl, &allum1, nb_allum);
	  if ((nb_allum = my_check_allum(tabl, 0, 0)) == 0 || nb_allum == 1)
	    return (0);
	}
    }
  return (0);
}
