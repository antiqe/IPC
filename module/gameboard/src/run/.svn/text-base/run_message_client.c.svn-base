/*
** run_message_client.c for run_message_client in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/run
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 30 13:13:46 2013 ronan guiho
** Last update Sat Mar 30 16:48:39 2013 ronan guiho
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
#include "message.h"
#include "font.h"

int run_message_newclient_team(t_game *game, int id,
			       char *name, int *pos)
{
  t_team *team;
  t_player *player;

  if ((team = new_team(name, id)) == NULL)
    return (EXIT_FAILURE);
  player = new_player(pos);
  player->color[0] = team->color[0];
  player->color[1] = team->color[1];
  player->color[2] = team->color[2];
  team->player->push_back(team->player, player);
  game->list_team->push_back(game->list_team, team);
  return (EXIT_SUCCESS);
}

int run_message_newclient_player(t_team *team, int *pos)
{
  t_player *player;

  if ((player = new_player(pos)) == NULL)
    return (EXIT_FAILURE);
  player->color[0] = team->color[0];
  player->color[1] = team->color[1];
  player->color[2] = team->color[2];
  team->player->push_back(team->player, player);
  return (EXIT_SUCCESS);
}

int run_message_newclient(t_game *game, t_font *font, char *buffer)
{
  int id;
  int pos[2];
  char *name;
  t_team *team;
  const char	delim[2] = { MSG_DELIM, '\0' };

  name = strdup(strtok(buffer, delim));
  id = atoi(strtok(NULL, delim));
  pos[0] = atoi(strtok(NULL, delim));
  pos[1] = atoi(strtok(NULL, delim));
  if (game->status == INGAME)
    send_msg(game->id_msg, ID_START, "", 0);
  if ((team = game->list_team->find_if(game->list_team,
				       team_find_by_id, &id, NULL)) == NULL)
    run_message_newclient_team(game, id, name, pos);
  else
    run_message_newclient_player(team, pos);
  if (font)
    run_wait_display(game, font, game->list_team->size(game->list_team));
  return (EXIT_SUCCESS);
}
