/*
** ia.c for lemipc in /home/leprov_a//project/tek2/lemIPC/rendu/module/lemipc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Mar 28 11:28:06 2013 alexis leprovost
** Last update Sat Mar 30 19:34:18 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ipc.h>

#include "lemipc.h"
#include "message.h"

void	get_target(t_bot* bot, int* pos)
{
  const int*	mem = (int*)bot->data;
  int		i;
  int		x;
  int		y;

  pos[X] = bot->map.width;
  pos[Y] = bot->map.height;
  i = -1;
  sem_lock(bot->sem_id);
  while (++i < bot->map.size)
    {
      x = i % bot->map.width;
      y = i / bot->map.width;
      if (mem[i] != bot->id && mem[i] && (pos[X] + pos[Y]) > (x + y))
      {
	pos[X] = x;
	pos[Y] = y;
      }
    }
  sem_unlock(bot->sem_id);
  pos[X] = pos[X] == bot->map.width ? rand() % bot->map.width : pos[X];
  pos[Y] = pos[Y] == bot->map.height ? rand() % bot->map.height : pos[Y];
}

void	find_case_to_move(t_bot* bot, int* pos)
{
  const int*	mem = (int*)bot->data;

  sem_lock(bot->sem_id);
  if (pos[X] >= 0 && pos[X] < bot->map.width &&
      pos[Y] >= 0 && pos[Y] < bot->map.height &&
      !mem[pos[X] + (pos[Y] * bot->map.width)])
    {
      sem_unlock(bot->sem_id);
      move(bot, pos[X], pos[Y]);
    }
  else
    {
      sem_unlock(bot->sem_id);
      if (find_free_case(bot, pos))
	move(bot, pos[X], pos[Y]);
    }
}
