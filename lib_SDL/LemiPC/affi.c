/*
** affi.c for  in /home/antune_r/rendu/PSU_2014_lemipc
** 
** Made by Romain Antunes
** Login   <antune_r@epitech.net>
** 
** Started on  Wed Mar  4 20:27:06 2015 Romain Antunes
** Last update Sun Mar  8 16:16:30 2015 Aurélie LAO
*/

#include "lemipc.h"

void		draw_champion(t_data *sd, int x, int y, char team)
{
  SDL_Surface	*dis;

  dis = SDL_GetVideoSurface();
  sd->pos.x = x + (x * 9);
  sd->pos.y = y + (y * 9);
  sd->pos.w = 10;
  sd->pos.h = 10;
  if (team == '0')
    SDL_FillRect(dis, &sd->pos, SDL_MapRGB(dis->format, 0, 0, 0));
  else if (team == '1')
    SDL_FillRect(dis, &sd->pos, SDL_MapRGB(dis->format, 0, 0, 255));
  else if (team == '2')
    SDL_FillRect(dis, &sd->pos, SDL_MapRGB(dis->format, 0, 255, 0));
  else if (team == '3')
    SDL_FillRect(dis, &sd->pos, SDL_MapRGB(dis->format, 255, 0, 0));
  else if (team == '4')
    SDL_FillRect(dis, &sd->pos, SDL_MapRGB(dis->format, 125, 125, 125));
}

int		init_sdl(t_data *sd)
{
  if ((SDL_Init(SDL_INIT_VIDEO) == -1) ||
      ((sd->scr = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE)) == NULL))
    return (-1);
  sd->finish = 0;
  sd->can_stop = 1;
  return (0);
}

int		my_aff(t_data *sd, char *map)
{
  int		n;

  n = 0;
  SDL_FillRect(sd->scr, NULL, SDL_MapRGB(sd->scr->format, 0, 0, 0));
  while (map[n] != '\0')
    {
      draw_champion(sd, n % 60, n / 60, map[n]);
      ++n;
    }
  SDL_Flip(sd->scr);
  return (0);
}

int		quit_clean(t_data *d)
{
  delete_shm(d);
  delete_sem(d);
  msgctl(d->msg_id, IPC_RMID, NULL);
  SDL_Quit();
  return (0);
}

int		my_m_aff(t_data *d)
{
  t_data	sd;
  int		j;

  sd.fail = init_sdl(&sd);
  j = 0;
  while (sd.fail == 0 && sd.finish == 0)
    {
      if (recv_msg(d) == 0)
  	return (quit_clean(d));
      SDL_PollEvent(&sd.event);
      if (sd.event.type == SDL_QUIT)
	{
	  while (j++ < 3600)
	    send_msg(d, 'D', 42);
	  usleep(550000);
	  return (quit_clean(d));
	}
      else
  	my_aff(&sd, d->map);
    }
  return (0);
}
