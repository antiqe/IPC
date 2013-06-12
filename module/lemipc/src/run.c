/*
** run.c for lemipc in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 16:28:14 2013 alexis leprovost
** Last update Sat Mar 30 19:40:57 2013 alexis leprovost
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>

#include "lemipc.h"
#include "message.h"

int	is_dead(t_bot* bot)
{
  const int*	mem = (int*)bot->data;
  int		c;
  int		x;
  int		y;

  c = 0;
  y = bot->pos[Y] - 2;
  sem_lock(bot->sem_id);
  while (++y < bot->pos[Y] + 2)
    {
      x = bot->pos[X] - 2;
      while (++x < bot->pos[X] + 2)
	if ((x >= 0 && x < bot->map.width) &&
	    (y >= 0 && y < bot->map.height) &&
	    (mem[x + (y * bot->map.width)] != bot->id))
	  c += mem[x + (y * bot->map.width)] ? 1 : 0;
    }
  sem_unlock(bot->sem_id);
  return (c < 2 ? 0 : 1);
}

int	is_victory(t_bot* bot)
{
  const int*	mem = (int*)bot->data;
  int		i;

  i = -1;
  sem_lock(bot->sem_id);
  while (++i < bot->map.size)
    if (mem[i] && mem[i] != bot->id)
      {
	sem_unlock(bot->sem_id);
	return (0);
      }
  sem_unlock(bot->sem_id);
  return (1);
}

void	get_teammate(t_bot* bot, int* pos)
{
  const int*	mem = (int*)bot->data;
  int		i;
  int		x;
  int		y;

  pos[X] = bot->map.width + 1;
  pos[Y] = bot->map.height + 1;
  i = -1;
  sem_lock(bot->sem_id);
  while (++i < bot->map.size)
    {
      x = i % bot->map.width;
      y = i / bot->map.width;
      if (mem[i] == bot->id && bot->pos[X] != x && bot->pos[Y] != y &&
	  ((ABS((pos[X] + pos[Y]) - (bot->pos[X] + bot->pos[Y])) >
	    ABS((x + y) - (bot->pos[X] + bot->pos[Y]))) ||
	   pos[X] == -1 || pos[Y] == -1))
      {
	pos[X] = x;
	pos[Y] = y;
      }
    }
  sem_unlock(bot->sem_id);
  pos[X] = pos[X] == bot->map.width + 1 ? -1 : pos[X];
  pos[Y] = pos[Y] == bot->map.height + 1 ? -1 : pos[Y];
}

int	find_free_case(t_bot* bot, int *pos)
{
  const int*	mem = (int*)bot->data;
  int		x;
  int		y;

  y = bot->pos[Y] - 2;
  sem_lock(bot->sem_id);
  while (++y < bot->pos[Y] + 2)
    {
      x = bot->pos[X] - 2;
      while (++x < bot->pos[X] + 2)
	if ((x >= 0 && x < bot->map.width) &&
	    (y >= 0 && y < bot->map.height) &&
	    (!mem[x + (y * bot->map.width)]))
	  {
	    pos[X] = x;
	    pos[Y] = y;
	    sem_unlock(bot->sem_id);
	    return (1);
	  }
    }
  sem_unlock(bot->sem_id);
  return (0);
}
