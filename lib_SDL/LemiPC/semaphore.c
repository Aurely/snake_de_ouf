/*
** semaphore.c for  in /home/lao_e/rendu/LemiPC/PSU_2014_lemipc
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Mar  8 16:07:24 2015 Aurélie LAO
** Last update Sun Mar  8 16:17:17 2015 Aurélie LAO
*/

#include "lemipc.h"

void		op_sem(t_data *d, int ope)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = ope;
  semop(d->sem_id, &sops, 1);
}

int		delete_sem(t_data *d)
{
  semctl(d->sem_id, 1, IPC_RMID, NULL);
  return (0);
}

int		create_sem(t_data *d)
{
  d->sem_id = semget(d->key, 1, SHM_R | SHM_W);
  if (d->sem_id == -1)
    {
      d->sem_id = semget(d->key, 1, IPC_CREAT | SHM_R | SHM_W);
      semctl(d->sem_id, 0, SETVAL, 1);
    }
  return (0);
}
