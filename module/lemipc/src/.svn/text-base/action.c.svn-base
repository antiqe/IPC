/*
** action.c for lemipc in /home/leprov_a//project/tek2/lemIPC/rendu/module/lemipc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Mar 28 11:33:17 2013 alexis leprovost
** Last update Sun Mar 31 15:20:05 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "lemipc.h"
#include "message.h"

void	die(t_bot* bot)
{
  int*  mem;
  char	buff[MSG_SIZE];

  sprintf(buff, "%d%c%d%c%d", bot->id, MSG_DELIM, bot->pos[X], MSG_DELIM,
	  bot->pos[Y]);
  mem = (int*)bot->data;
  sem_lock(bot->sem_id);
  mem[bot->pos[X] + (bot->pos[Y] * bot->map.width)] = 0;
  send_msg(bot->msg_id[GLOBAL], ID_DELCLIENT, buff, 0);
  sem_unlock(bot->sem_id);
}

void	move(t_bot* bot, int x, int y)
{
  int*	mem;
  char	buff[MSG_SIZE];

  mem = (int*)bot->data;
  sprintf(buff, "%d%c%d%c%d%c%d%c%d", bot->id, MSG_DELIM, bot->pos[X],
	  MSG_DELIM, bot->pos[Y], MSG_DELIM, x, MSG_DELIM, y);
  sem_lock(bot->sem_id);
  mem[bot->pos[X] + (bot->pos[Y] * bot->map.width)] = 0;
  bot->pos[X] = x;
  bot->pos[Y] = y;
  mem[bot->pos[X] + (bot->pos[Y] * bot->map.width)] = bot->id;
  send_msg(bot->msg_id[GLOBAL], ID_POSCLIENT, buff, 0);
  sem_unlock(bot->sem_id);
}
