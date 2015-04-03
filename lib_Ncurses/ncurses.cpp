//
// ncurses.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Fri Apr  3 15:14:38 2015 Aurélie LAO
// Last update Fri Apr  3 15:32:00 2015 Aurélie LAO
//

#include "../header/the_snake.hh"

void		go_Ncurses(Snake *s)
{
  check_status(s);
  s->check_can_eat();
  check_status(s);
}
