/*
** message.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:08:11 2015 Aurélie LAO
** Last update Sun Mar  8 16:17:03 2015 Aurélie LAO
*/

#include "lemipc.h"

int		recv_sdl(t_data *d)
{
  int		rc;

  rc = msgrcv(d->msg_id, &d->msg, sizeof(d->msg), 42, IPC_NOWAIT);
  if (rc != -1)
    return (0);
  return (-1);
}

int		recv_msg(t_data *d)
{
  int		rc;

  rc = msgrcv(d->msg_id, &d->msg, sizeof(d->msg), 1, IPC_NOWAIT);
  if (rc != -1)
    {
      printf("%s\n", d->msg.str);
      msgctl(d->msg_id, IPC_RMID, NULL);
      return (0);
    }
  return (-1);
}

void		send_msg(t_data *d, char team, long type)
{
  bzero(&d->msg, sizeof(d->msg));
  d->msg.mtype = type;
  sprintf(d->msg.str, "La team %c WIN", team);
  msgsnd(d->msg_id, &d->msg, sizeof(d->msg), IPC_NOWAIT);
}

int		create_msgq(t_data *d)
{
  d->msg_id = msgget(d->key, SHM_R | SHM_W);
  if (d->msg_id == -1)
    d->msg_id = msgget(d->key, IPC_CREAT | SHM_R | SHM_W);
  return (0);
}
