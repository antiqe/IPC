/*
** team.c for team in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 22:03:02 2013 ronan guiho
** Last update Sun Mar 31 14:47:47 2013 ronan guiho
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "game.h"
#include "list.h"
#include "team.h"
#include "player.h"
#include "message.h"

t_team *new_team(char *name, int id)
{
  t_team *team;

  if ((team = malloc(sizeof(t_team))) == NULL)
    return (NULL);
  if ((team->player = new_list()) == NULL)
    return (NULL);
  team->id = id;
  team->name = name;
  get_random_color(team->color);
  return (team);
}

void team_display(void *context, void *data, int i)
{
  t_team *team;
  t_game *game;

  (void)i;
  game = (t_game *)context;
  team = (t_team *)data;
  team->player->iter(team->player, player_display, game);
}

void team_sendall_start(void *context, void *data, int i)
{
  int i1;
  t_game *game;
  t_team *team;

  i1 = 0;
  (void)i;
  game = (t_game *)context;
  team = (t_team *)data;
  while (i1 < team->player->size(team->player))
    {
      send_msg(game->id_msg, ID_START, "", 0);
      ++i1;
    }
}

int team_find_by_id(void *context, void *data, void *value)
{
  int id;
  t_team *team;

  (void)context;
  id = *(int *)value;
  team = (t_team *)data;
  if (team->id == id)
    return (1);
  return (0);
}

void display_team_clear(t_game *game)
{
  SDL_Rect vign;

  vign.x = POSX_DISPLAY_TEAM;
  vign.y = POSY_DISPLAY_TEAM;
  vign.w = 175;
  vign.h = 530;
  SDL_FillRect(game->window->win, &vign,
	       SDL_MapRGB(game->window->win->format,
			  0, 0, 0));
}
