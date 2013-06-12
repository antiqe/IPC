/*
** board_func.c for board in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/board
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 30 12:52:31 2013 ronan guiho
** Last update Sat Mar 30 12:58:45 2013 ronan guiho
*/

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "window.h"
#include "board.h"

void board_draw_square(SDL_Rect *line, SDL_Rect *pos)
{
  line[0].x = pos->x;
  line[0].y = pos->y;
  line[0].w = 1;
  line[0].h = pos->h;
  line[1].x = pos->x;
  line[1].y = pos->y;
  line[1].w = pos->w;
  line[1].h = 1;
  line[2].x = pos->x;
  line[2].y = pos->y + pos->h;
  line[2].w = pos->w;
  line[2].h = 1;
  line[3].x = pos->x + pos->w;
  line[3].y = pos->y;
  line[3].w = 1;
  line[3].h = pos->h;

}

void	    board_draw_init(SDL_Rect *screen_rect, t_board *this)
{
  screen_rect->y = 0;
  screen_rect->w = BOARD_WIDTH / this->getWidth(this);
  screen_rect->h = BOARD_HEIGHT / this->getHeight(this);

}

SDL_Surface *board_draw(t_board *this)
{
  int i;
  SDL_Surface *board;
  SDL_Rect screen_rect;
  SDL_Rect line[4];

  if ((board = SDL_CreateRGBSurface(SDL_SWSURFACE, BOARD_WIDTH + 1, \
				    BOARD_HEIGHT + 1, 32, \
				    0, 0, 0, 0)) == NULL)
      return (NULL);
  board_draw_init(&screen_rect, this);
  while (screen_rect.y < BOARD_HEIGHT)
    {
      screen_rect.x = 0;
      while (screen_rect.x < BOARD_WIDTH)
	{
	  board_draw_square(line, &screen_rect);
	  i = -1;
	  while (++i < 4)
	    SDL_FillRect(board, &line[i], 0x333333);
	  screen_rect.x += screen_rect.w;
	}
      screen_rect.y += screen_rect.h;
    }
  return (board);
}

int board_get_id(t_board *this)
{
  return (this->id);
}
