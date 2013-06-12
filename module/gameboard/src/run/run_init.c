/*
** core_init.c for core_init in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 21:04:32 2013 ronan guiho
** Last update Sat Mar 30 18:43:12 2013 ronan guiho
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
#include "message.h"
#include "console.h"
#include "font.h"

void run_display_play_init(int *color, SDL_Rect *rect)
{
  color[0] = 255;
  color[1] = 0;
  color[2] = 0;
  rect->x = POS_X_BUTTON;
  rect->y = POS_Y_BUTTON;
  rect->w = SIZE_X_BUTTON;
  rect->h = SIZE_Y_BUTTON;
}

int run_display_play(t_game *game, t_font *font)
{
  int i;
  int color[3];
  SDL_Rect rect;
  SDL_Surface *text;
  SDL_Rect border[4];

  run_display_play_init(color, &rect);
  board_draw_square(border, &rect);
  i = -1;
  while (++i < 4)
    SDL_FillRect(game->window->win, &border[i],
		 SDL_MapRGB(game->window->win->format, 255, 0, 0));
  text = font->write(font, "PLAY", color);
  rect.x = POS_X_BUTTON + (SIZE_X_BUTTON / 3);
  SDL_BlitSurface(text, NULL, game->window->getWindow(game->window), &rect);
  SDL_FreeSurface(text);
  return (EXIT_SUCCESS);
}
