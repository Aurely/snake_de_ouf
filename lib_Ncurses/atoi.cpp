//
// atoi.cpp for  in /home/trotie_m/training/snake_de_ouf/lib_Ncurses
// 
// Made by Trotier Marie
// Login   <trotie_m@epitech.net>
// 
// Started on  Thu Apr  2 17:06:07 2015 Trotier Marie
// Last update Thu Apr  2 17:06:15 2015 Trotier Marie
//

#include <iostream>
#include <sstream>

int                     my_totoi(char *str)
{
  std::istringstream    stream((std::string(str)));
  int                   result;
  int                   i = 0;

  stream >> result;
  if (str[i] == '-')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        return (-1);
      i = i + 1;
    }
  return (result);
}
