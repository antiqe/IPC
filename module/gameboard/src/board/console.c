/*
** console.c for console in /home/guiho_r/projet/lemipc/gameboard/src/board
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 18:41:58 2013 ronan guiho
** Last update Sat Mar 30 19:56:27 2013 ronan guiho
*/

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "game.h"
#include "console.h"
#include "window.h"
#include "board.h"

static char buffer[7][2] = {"C\0", "O\0", "N\0", "S\0", "O\0", "L\0", "E\0"};
static int  buffer_pos[7] = {6, 6, 6, 7, 6, 7, 7};

void console_clear(t_game *game)
{
  SDL_Rect clear;

  clear.x = POS_X_CONSOLE + 50;
  clear.y = POS_Y_CONSOLE + 5;
  clear.w = SIZE_X_CONSOLE - 50;
  clear.h = SIZE_Y_CONSOLE - 10;
  SDL_FillRect(game->window->win, &clear,
	       SDL_MapRGB(game->window->win->format, 0, 0, 0));
}

void console_write(t_game *game, char *write)
{
  int color[3];
  static int i;
  SDL_Rect pos;
  SDL_Surface *text;

  i = (i == 6) ? 0 : i;
  pos.x = POS_X_CONSOLE + 50;
  pos.y = (POS_Y_CONSOLE + 2) + (SPACING_CONSOLE * i);
  color[0] = 255;
  color[1] = 255;
  color[2] = 255;
  text = game->font_team->write(game->font_team, write, color);
  SDL_BlitSurface(text, NULL, game->window->win, &pos);
  SDL_FreeSurface(text);
  ++i;
  if (i == 6)
    console_clear(game);
}

void display_console_boarder(t_game *game, SDL_Rect *pos)
{
  int i;
  SDL_Rect board[4];

  board_draw_square(board, pos);
  i = -1;
  while (++i < 4)
    SDL_FillRect(game->window->win, &board[i],
		 SDL_MapRGB(game->window->win->format, 255, 255, 255));
  pos->w = 30;
  board_draw_square(board, pos);
  i = -1;
  while (++i < 4)
    SDL_FillRect(game->window->win, &board[i],
		 SDL_MapRGB(game->window->win->format, 255, 255, 255));
}

void display_console(t_game *game)
{
  int i;
  int color[3];
  SDL_Surface *text;
  SDL_Rect pos;

  pos.x = POS_X_CONSOLE;
  pos.y = POS_Y_CONSOLE;
  pos.w = SIZE_X_CONSOLE;
  pos.h = SIZE_Y_CONSOLE;
  display_console_boarder(game, &pos);
  i = -1;
  color[0] = 255;
  color[1] = 255;
  color[2] = 255;
  while (++i < 7)
    {
      pos.x = POS_X_CONSOLE + buffer_pos[i];
      text = game->font_team->write(game->font_team, buffer[i], color);
      SDL_BlitSurface(text, NULL, game->window->win, &pos);
      SDL_FreeSurface(text);
      pos.y += 17;
    }
}
