//
// my_print.cpp for  in /home/lao_e/rendu/snake_de_ouf/lib_Ncurses
// 
// Made by Aurélie LAO
// Login   <lao_e@epitech.net>
// 
// Started on  Tue Mar 31 10:47:51 2015 Aurélie LAO
// Last update Fri Apr  3 15:40:15 2015 Aurélie LAO
//

#include <ncurses/curses.h>
#include "my_exception.hh"
#include <iostream>
#include <cstring>
#include <unistd.h>

bool curses_started = false;

void endCurses()
{
  if (curses_started && !isendwin())
    endwin();
}


void startCurses()
{
  if (curses_started)
    refresh();
  else
    {
      initscr();
      cbreak();
      noecho();
      intrflush(stdscr, false);
      keypad(stdscr, true);
      curses_started = true;
    }
}
