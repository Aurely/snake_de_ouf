
/*
** allum3.c for allum1 in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Fri Feb 14 15:19:39 2014 lao_e
** Last update Sat Feb 15 14:18:45 2014 lao_e
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "allum.h"

char	**my_modif_tabl(char **tabl, t_allum *allum)
{
  int	line;
  int	index;

  line = allum->line;
  index = 0;
  while (tabl[line][index] != '|')
    index++;
  while (tabl[line][index] != '\0' && allum->row > 0)
    {
      if (tabl[line][index] == '|')
	tabl[line][index] = 'x';
      index++;
      allum->row--;
    }
  return (tabl);
}

void	my_press_arrow(t_allum *allum1, char **tabl)
{
  int	j;
  int	nbr_line;

  j = 0;
  nbr_line = 0;
  while (tabl[allum1->line][j] != '\0')
    {
      if (tabl[allum1->line][j] == '|')
	nbr_line++;
      j++;
    }
  if (allum1->keycode == CODE_LEFT && allum1->row > 0)
    allum1->row--;
  else if (allum1->keycode == CODE_RIGHT && allum1->row < nbr_line)
    allum1->row++;
  if (allum1->keycode == CODE_UP && allum1->line > 0)
    {
      allum1->line--;
      allum1->row = 0;
    }
  else if (allum1->keycode == CODE_DOWN && allum1->line < 3)
    {
      allum1->line++;
      allum1->row = 0;
    }
}

void	my_print_result(int counter, int a)
{
  if (a == 0)
    {
      if (counter == 1)
	my_putstr("you lost");
      else
	my_putstr("you won");
    }
  else
    {
      if (counter == 1)
	my_putstr("you won");
      else
	my_putstr("you lost");
    }
}

int	my_check_allum(char **tabl, int counter, int a)
{
  int	line;
  int	row;

  line = 0;
  while (tabl[line])
    {
      row = 0;
      while (tabl[line][row])
	{
	  if (tabl[line][row] == '|')
	    counter++;
	  row++;
	}
      line++;
    }
  if (counter == 1 || counter == 0)
    my_print_result(counter, a);
  return (counter);
}

char	**my_ia_player(char **tabl, t_allum *tallum, int nb_allum)
{
  int	line;
  int	row;
  int	i;

  i = 0;
  line = 0;
  while (tabl[line])
    {
      row = 0;
      while (tabl[line][row] && i == 0)
	{
	  if (tabl[line][row] == '|')
	    {
	      tabl[line][row] = 'o';
	      i = 1;
	    }
	  row++;
	}
      line++;
    }
  return (tabl);
}
