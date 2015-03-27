/*
** allum.h for allum1 in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Tue Feb  4 15:59:59 2014 lao_e
** Last update Sat Feb 15 13:42:00 2014 lao_e
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# define SIZE_LINE 4
# define SIZE_ROW 8

# define CODE_LEFT 4479771
# define CODE_UP 4283163
# define CODE_RIGHT 4414235
# define CODE_DOWN 4348699
# define CODE_ENTER 10

typedef struct		s_allum
{
  unsigned int		keycode;
  int			row;
  int			line;
}			t_allum;

char	*my_get_term_name(char *env_term);
char	**my_modif_tabl(char **tabl, t_allum *allum);
char	*my_strdup(char *str);
char	**my_ia_player(char **tabl, t_allum *tallum, int nb_allum);

#endif /* !ALLUM_H_ */
