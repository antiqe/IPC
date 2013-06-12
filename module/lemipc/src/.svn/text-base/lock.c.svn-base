/*
** lock.c for lemipc in /home/leprov_a//project/tek2/lemIPC/rendu/module/lemipc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 19:36:02 2013 alexis leprovost
** Last update Wed Mar 27 19:40:44 2013 alexis leprovost
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "lemipc.h"

void	sem_lock(int id)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_op = -1;
  sops.sem_flg = 0;
  semop(id, &sops, 1);
}

void	sem_unlock(int id)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_op = 1;
  sops.sem_flg = 0;
  semop(id, &sops, 1);
}
