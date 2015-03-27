/*
** modif_term.c for allum1 in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Tue Feb  4 16:36:43 2014 lao_e
** Last update Wed Feb 12 17:08:50 2014 lao_e
*/

#include "allum.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>

int			my_term_reset(struct termios t)
{
  if (tcgetattr(0, &t) == -1)
    return (-1);
  t.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, &t) == -1)
    return (-1);
}

int			my_change_mod(struct termios t, char **tabl)
{
  int			i;
  int			j;

  i = 0;
  t.c_lflag &= ~ECHO;
  if ((tcsetattr(0, TCSADRAIN, &t)) == -1)
    return (-1);
  if (my_read_term(t, tabl) == -1)
    return (-1);
  my_putchar('\n');
  if (my_term_reset(t) == -1)
    return (-1);
}

int			my_term_clear()
{
  if (tgetstr("cl", NULL) == 0)
    {
      my_putstr("Error: tgetstr failed\n");
      return (-1);
    }
  my_putstr(tgetstr("cl", NULL));
  return (0);
}

int			change_to_raw_mode(struct termios t)
{
  t.c_lflag &= ~(ICANON);
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSADRAIN, &t)) == -1)
    {
      my_putstr("Error: tcsetattr failed\n");
      return (-1);
    }
  return (0);
}

int			modif_term_mode(char *term_name, char **tabl)
{
  struct termios	t;

  if ((tgetent(NULL, term_name)) == -1)
    {
      my_putstr("Error : Database of termcaps not found\n");
      return (-1);
    }
  if ((tgetent(NULL, term_name)) == 0)
    {
      my_putstr("Error : Terminal's name invalid\n");
      return (-1);
    }
  if ((tcgetattr(0, &t)) == 1)
    {
      my_putstr("Error: tcgetattr failed\n");
      return (-1);
    }
  if ((my_change_mod(t, tabl)) == -1)
    return (-1);
  return (0);
}
