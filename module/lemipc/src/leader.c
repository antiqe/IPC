/*
** leader.c for lemipc in /home/leprov_a//project/tek2/lemipc/rendu/module/lemipc/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Mar 30 11:23:10 2013 alexis leprovost
** Last update Sun Mar 31 14:52:48 2013 alexis leprovost
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>

#include "lemipc.h"
#include "message.h"

static void	ia_leader(t_bot* bot, int* ennemy, int* teammate)
{
  int	pos[2];

  if (teammate[X] == -1 || teammate[Y] == -1)
    {
      pos[X] = bot->pos[X] + (ennemy[X] - bot->pos[X] > 0 ? 1 :
			      (ennemy[X] - bot->pos[X] < 0 ? -1 : 0));
      pos[Y] = bot->pos[Y] + (ennemy[Y] - bot->pos[Y] > 0 ? 1 :
			      (ennemy[Y] - bot->pos[Y] < 0 ? -1 : 0));
    }
  else if (ABS((teammate[X] + teammate[Y]) - (bot->pos[X] + bot->pos[Y])) >
	   ABS((ennemy[X] + ennemy[Y]) - (bot->pos[X] + bot->pos[Y])))
    {
      pos[X] = bot->pos[X] + (ennemy[X] - bot->pos[X] > 0 ? -1 :
			      (ennemy[X] - bot->pos[X] < 0 ? 1 : 0));
      pos[Y] = bot->pos[Y] + (ennemy[Y] - bot->pos[Y] > 0 ? -1 :
			      (ennemy[Y] - bot->pos[Y] < 0 ? 1 : 0));
    }
  else
    {
      pos[X] = bot->pos[X] + (teammate[X] - bot->pos[X] > 0 ? 1 :
			      (teammate[X] - bot->pos[X] < 0 ? -1 : 0));
      pos[Y] = bot->pos[Y] + (teammate[Y] - bot->pos[Y] > 0 ? 1 :
			      (teammate[Y] - bot->pos[Y] < 0 ? -1 : 0));
    }
  find_case_to_move(bot, pos);
}

int	as_leader(t_bot* bot)
{
  t_msg	buff;
  int	teammate[2];
  int	ennemy[2];

  while (!is_dead(bot) &&
	 !is_victory(bot) &&
	 recv_msg(bot->msg_id[TEAM], &buff, ID_END, IPC_NOWAIT) == -1)
    {
      get_target(bot, ennemy);
      get_teammate(bot, teammate);
      ia_leader(bot, ennemy, teammate);
      usleep(100);
    }
  die(bot);
  return (EXIT_SUCCESS);
}
