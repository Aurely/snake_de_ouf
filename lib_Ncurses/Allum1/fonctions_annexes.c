/*
** fonctions_annexes.c for allum1 in /home/lao_e/rendu/Allum1
** 
** Made by lao_e
** Login   <lao_e@epitech.net>
** 
** Started on  Tue Feb  4 15:52:25 2014 lao_e
** Last update Sat Feb 15 14:09:27 2014 lao_e
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	index;

  index = 0;
  if (str[0] == '\0')
    return (-1);
  while (str[index])
    my_putchar(str[index++]);
  return (0);
}

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*snew;

  if ((snew = malloc(my_strlen(str))) == 0)
    return (0);
  my_strcpy(snew, str);
  return (snew);
}
