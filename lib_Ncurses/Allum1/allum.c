/*
** allum.c for  in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Tue Feb  4 16:47:02 2014 lao_e
** Last update Sat Feb 15 14:22:14 2014 lao_e
*/

#include <stdlib.h>
#include <ncurses/curses.h>
#include <termios.h>
#include "allum.h"

char			**my_creator_tab(char **tabl)
{
  int		index;

  index = 0;
  if ((tabl = malloc(sizeof(char *) * SIZE_LINE)) == NULL)
    return (NULL);
  while (tabl[index])
    if ((tabl[index++] = malloc(sizeof(char) * SIZE_ROW)) == NULL)
      return (NULL);
  tabl[0] = my_strdup("   |   ");
  tabl[1] = my_strdup("  |||  ");
  tabl[2] = my_strdup(" ||||| ");
  tabl[3] = my_strdup("|||||||");
  tabl[4] = '\0';
  return (tabl);
}

int			my_get_line_env_term(char **env)
{
  int			i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'T')
        if (env[i][1] == 'E')
          if (env[i][2] == 'R')
            if (env[i][3] == 'M')
              return (i);
      i++;
    }
  my_putstr("Error : no TERM into the environment\n");
  return (-1);
}

char			*my_get_term_name(char *env_term)
{
  int			i;
  int			j;
  char			*str;

  if ((str = malloc(sizeof(char) * my_strlen(env_term))) == NULL)
    {
      my_putstr("Error: Malloc failed\n");
      return (NULL);
    }
  i = 5;
  j = 0;
  while (env_term[i])
    str[j++] = env_term[i++];
  str[j] = '\0';
  return (str);
}

int			modif_term(char **env)
{
  struct termios	t;
  int			term_env_line;
  char			*term_name;

  if (((term_env_line = my_get_line_env_term(env)) == -1) ||
      ((term_name = my_get_term_name(env[term_env_line])) == NULL))
    return (-1);
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
  if ((change_to_raw_mode(t)) == -1)
    return (-1);
  return (0);
}

int			main(int ac, char **av, char **env)
{
  char			**tabl;
  struct termios	t;

  tabl = my_creator_tab(tabl);
  if (modif_term(env) == -1)
    return (-1);
  if ((my_print(tabl, env)) == -1)
    return (-1);
  return (0);
}
