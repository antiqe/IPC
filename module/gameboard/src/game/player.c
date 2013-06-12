/*
** player.c for player in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 22:20:58 2013 ronan guiho
** Last update Sat Mar 30 13:11:02 2013 ronan guiho
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

t_player *new_player(int *pos)
{
  t_player *player;

  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->pos[X] = pos[X];
  player->pos[Y] = pos[Y];
  return (player);
}

int player_find_by_pos(void *context, void *data, void *value)
{
  int *pos;
  t_player *player;

  (void)context;
  pos = (int *)value;
  player = (t_player *)data;
  if (player->pos[X] == pos[X] && player->pos[Y] == pos[Y])
    return (1);
  return (0);
}

void player_display(void *context, void *data, int i)
{
  t_game *game;
  t_player *player;
  SDL_Rect sq;

  (void)i;
  game = (t_game *)context;
  player = (t_player *)data;
  sq.w = BOARD_WIDTH / game->board->getWidth(game->board);
  sq.h = BOARD_HEIGHT / game->board->getHeight(game->board);
  sq.x = BOARD_POSX + (player->pos[X] * sq.w) + 1;
  sq.y = BOARD_POSY + (player->pos[Y] * sq.h) + 1;
  sq.w -= 1;
  sq.h -= 1;
  SDL_FillRect(game->window->win, &sq, \
	       SDL_MapRGB(game->window->win->format,
			  player->color[0], player->color[1], player->color[2]));
}
