/*
** init.c for lemipc in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 15:30:33 2013 alexis leprovost
** Last update Sun Mar 31 15:21:34 2013 alexis leprovost
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "lemipc.h"
#include "message.h"

static int	init_map(t_bot* bot)
{
  const char	delim[2] = { MSG_DELIM, '\0' };
  t_msg		buff;

  if (send_msg(bot->msg_id[GLOBAL], ID_GETSIZE, "", IPC_NOWAIT) ||
      recv_msg(bot->msg_id[GLOBAL], &buff, ID_SETSIZE, 0) == -1)
    return (EXIT_FAILURE);
  bot->map.width = atoi(strtok(buff.str, delim));
  bot->map.height = atoi(strtok(NULL, delim));
  bot->map.size = bot->map.width * bot->map.height;
  return (bot->map.size ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int	init_pos(t_bot* bot)
{
  const int*	mem = (int*)bot->data;
  int		i;
  int		c;

  c = 0;
  sem_lock(bot->sem_id);
  while (c < bot->map.size)
    {
      i = rand() % bot->map.size;
      if (!mem[i])
	{
	  bot->pos[X] = i % bot->map.width;
	  bot->pos[Y] = i / bot->map.width;
	  c =  bot->map.size + 1;
	}
    }
  sem_unlock(bot->sem_id);
  return (c == bot->map.size + 1 ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int	init_bot(t_bot* bot, char* teamname)
{
  int*			mem;
  char			buff[MSG_SIZE];

  bzero(buff, MSG_SIZE);
  mem = (int*)bot->data;
  sem_lock(bot->sem_id);
  mem[bot->pos[X] + (bot->pos[Y] * bot->map.width)] = bot->id;
  sem_unlock(bot->sem_id);
  sprintf(buff, "%.64s%c%d%c%d%c%d", teamname, MSG_DELIM, bot->id, MSG_DELIM,
	  bot->pos[X], MSG_DELIM, bot->pos[Y]);
  return (send_msg(bot->msg_id[GLOBAL], ID_NEWCLIENT, buff, IPC_NOWAIT));
}

int	init(t_bot* b, char* pathname, char* teamname)
{
  b->id = hash(teamname);
  if ((b->key[GLOBAL] = ftok(pathname, 0)) == -1)
    return (GLOBAL_KEY_MSG_ERROR);
  if ((b->msg_id[GLOBAL] = msgget(b->key[GLOBAL], SHM_R | SHM_W)) == -1)
    return (GLOBAL_ID_MSG_ERROR);
  if (init_map(b) == EXIT_FAILURE)
    return (MAP_ERROR);
  if ((b->shm_id = shmget(b->key[GLOBAL], b->map.size, SHM_R | SHM_W)) == -1 ||
      (b->sem_id = semget(b->key[GLOBAL], 1, SHM_R | SHM_W)) == -1 ||
      ((long)(b->data = shmat(b->shm_id, NULL, SHM_R | SHM_W)) == -1))
    return (DATA_ERROR);
  if (init_pos(b) == EXIT_FAILURE)
    return (FULL_MAP_ERROR);
  if (init_bot(b, teamname) == EXIT_FAILURE)
    return (BOT_ERROR);
  return (0);
}
