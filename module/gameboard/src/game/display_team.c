/*
** display_team.c for display_team in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/game
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Mar 29 13:48:05 2013 ronan guiho
** Last update Sun Mar 31 14:47:02 2013 ronan guiho
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "game.h"
#include "team.h"
#include "board.h"
#include "message.h"

void display_team_vign(t_game *game, t_team *team, int y)
{
  SDL_Rect vign;

  vign.x = POSX_DISPLAY_TEAM;
  vign.y = y + 8;
  vign.w = 30;
  vign.h = 20;
  SDL_FillRect(game->window->win, &vign,
	       SDL_MapRGB(game->window->win->format,
			  team->color[0], team->color[1], team->color[2]));
  SDL_Flip(game->window->win);
}

SDL_Surface *display_name_team(t_game *game, char *name, int *color)
{
  unsigned int i;
  char buffer[64];

  i = 0;
  while (name[i] && i < 10)
    {
      buffer[i] = name[i];
      ++i;
    }
  if (i == 10)
    while (i < 13)
      buffer[i++] = '.';
  buffer[i] = '\0';
  return (game->font_team->write(game->font_team, buffer, color));
}

void display_team(void *context, void *data, int i)
{
  int color[3];
  t_game *game;
  t_team *team;
  SDL_Rect rect;
  SDL_Surface *text;

  rect.x = POSX_DISPLAY_TEAM + 40;
  rect.y = POSY_DISPLAY_TEAM + (SPACING_DISPLAY_TEAM * i);
  game = (t_game *)context;
  team = (t_team *)data;
  color[0] = 255;
  color[1] = 255;
  color[2] = 255;
  display_team_vign(game, team, rect.y);
  text = display_name_team(game, team->name, color);
  SDL_BlitSurface(text, NULL, game->window->win, &rect);
  SDL_FreeSurface(text);
}

void display_allteam_board(t_game *game, SDL_Rect *pos)
{
  int i;
  SDL_Rect border[4];

  board_draw_square(border, pos);
  i = -1;
  while (++i < 4)
    SDL_FillRect(game->window->win, &border[i],
		 SDL_MapRGB(game->window->win->format, 255, 255, 255));
  pos->h = 35;
  board_draw_square(border, pos);
  i = -1;
  while (++i < 4)
    SDL_FillRect(game->window->win, &border[i],
		 SDL_MapRGB(game->window->win->format, 255, 255, 255));
}

int display_allteam(t_game *game)
{
  int color[3];
  SDL_Rect pos;
  SDL_Surface *text;

  pos.h = 600;
  pos.w = 195;
  pos.x = 820;
  pos.y = 10;
  color[0] = 255;
  color[1] = 255;
  color[2] = 255;
  display_allteam_board(game, &pos);
  text = game->font_team->write(game->font_team, "TEAM", color);
  pos.x = 890;
  SDL_BlitSurface(text, NULL, game->window->win, &pos);
  SDL_FreeSurface(text);
  display_team_clear(game);
  game->list_team->iter(game->list_team, display_team, game);
  return (EXIT_SUCCESS);
}
