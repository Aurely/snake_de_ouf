/*
** shared_memory.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:07:40 2015 Aurélie LAO
** Last update Sun Mar  8 16:28:26 2015 Aurélie LAO
*/

#include "lemipc.h"

int		delete_shm(t_data *d)
{
  return (shmctl(d->shm_id, IPC_RMID, NULL));
}

int		create_shm(t_data *d)
{
  int		j;

  j = 0;
  d->shm_id = shmget(d->key, sizeof(char) * 3601, SHM_R | SHM_W);
  if (d->shm_id == -1)
    {
      d->shm_id = shmget(d->key, sizeof(char) * 3601,
			 IPC_CREAT | SHM_R | SHM_W);
      d->map = shmat(d->shm_id, NULL, SHM_R | SHM_W);
      while (j < 3600)
	((char*)d->map)[j++] = '0';
      ((char*)d->map)[j++] = '\0';
    }
  else
    d->map = shmat(d->shm_id, NULL, SHM_R | SHM_W);
  return (0);
}
