/*
** victory.c for victory in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/run
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 30 17:13:50 2013 ronan guiho
** Last update Sun Mar 31 20:29:06 2013 ronan guiho
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
#include "console.h"

SDL_Surface *victory_team(t_game *game, t_font *font)
{
  int color[3];
  char buffer[256];
  SDL_Surface *team;
  char *name;

  color[0] = 255;
  color[1] = 0;
  color[2] = 0;
  bzero(buffer, 256);
  name = ((t_team *)game->list_team->at(game->list_team, 0))->name;
  sprintf(buffer, "%.10s%s has won !", name, (strlen(name) > 10) ? "..." : "");
  team = font->write(font, buffer, color);
  return (team);
}

int victory(t_game *game)
{
  t_font *font;
  SDL_Event event;
  SDL_Surface *team;
  SDL_Rect pos;

  pos.x = POS_X_VICTORY;
  pos.y = POS_Y_VICTORY;
  if ((font = new_font(PATH_FONT, 70)) == NULL)
    return (EXIT_FAILURE);
  team = victory_team(game, font);
  while (42)
    {
      while (SDL_PollEvent(&event))
	{
	  if (event.type == SDL_QUIT)
	    return (EXIT_FAILURE);
	  if (event.type == SDL_KEYDOWN)
	    if (event.key.keysym.sym == SDLK_ESCAPE)
	      return (EXIT_FAILURE);
	}
      SDL_BlitSurface(team, NULL, game->window->win, &pos);
      SDL_Flip(game->window->win);
      usleep(1000000 / FRAME_PER_SEC);
    }
  return (EXIT_SUCCESS);
}
