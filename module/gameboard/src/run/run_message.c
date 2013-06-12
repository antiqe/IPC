/*
** run_message.c for run_message in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/run
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 30 13:13:06 2013 ronan guiho
** Last update Sun Mar 31 16:25:47 2013 ronan guiho
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "team.h"
#include "game.h"
#include "player.h"
#include "console.h"
#include "message.h"
#include "font.h"

void run_message_delclient_init(int *id, int *pos, char *buffer)
{
  const char	delim[2] = { MSG_DELIM, '\0' };

  *id = atoi(strtok(buffer, delim));
  pos[0] = atoi(strtok(NULL, delim));
  pos[1] = atoi(strtok(NULL, delim));
}

void run_message_delclient(t_game *game, char *buffer)
{
  int id;
  int pos[2];
  t_team  *team;
  t_player *player;
  char buffer1[1024];

  run_message_delclient_init(&id, pos, buffer);
  if ((team = game->list_team->find_if(game->list_team,
				       team_find_by_id, &id, game)) != NULL)
    {
      if ((player = team->player->find_if(team->player,
					  player_find_by_pos, pos, game)) != NULL)
	{
	  bzero(buffer1, 1024);
	  sprintf(buffer1, "A player from the team %.9s has died", team->name);
	  console_write(game, buffer1);
	  sprintf(buffer1, "There are %d bots left from the team %.10s", \
		  team->player->size(team->player), team->name);
	  console_write(game, buffer1);
	  team->player->erase(team->player, player);
	}
      if (team->player->size(team->player) == 0)
	game->list_team->erase(game->list_team, team);
    }
}

void run_message_sizeboard(t_game *game)
{
  char buffer[MSG_SIZE];

  bzero(buffer, MSG_SIZE);
  sprintf(buffer, "%d|%d", game->board->getWidth(game->board),
	  game->board->getHeight(game->board));
  send_msg(game->id_msg, ID_SETSIZE, buffer, 0);
}

void run_message_move(t_game *game, char *buffer)
{
  int id;
  int pos[2][2];
  t_team  *team;
  t_player *player;
  const char	delim[2] = { MSG_DELIM, '\0' };

  id = atoi(strtok(buffer, delim));
  pos[0][0] = atoi(strtok(NULL, delim));
  pos[0][1] = atoi(strtok(NULL, delim));
  pos[1][0] = atoi(strtok(NULL, delim));
  pos[1][1] = atoi(strtok(NULL, delim));
  if ((team = game->list_team->find_if(game->list_team,
				       team_find_by_id, &id, game)) != NULL)
    {
      if ((player = team->player->find_if(team->player,
					  player_find_by_pos, pos[0], game)) != NULL)
	{
	  player->pos[X] = pos[1][X];
	  player->pos[Y] = pos[1][Y];
	}
    }
}
