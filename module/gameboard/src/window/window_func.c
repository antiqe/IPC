/*
** window_func.c for window_func in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 11:46:12 2013 ronan guiho
** Last update Sat Mar 30 13:18:04 2013 ronan guiho
*/

#include <stdlib.h>
#include <SDL/SDL.h>

#include "window.h"

unsigned int window_get_width(t_window *this)
{
  if (this)
    return (this->width);
  return (0);
}

unsigned int window_get_height(t_window *this)
{
  if (this)
    return (this->height);
  return (0);
}

SDL_Surface *window_get_window(t_window *this)
{
  if (this)
    return (this->win);
  return (NULL);
}

void window_clear(t_window *this, int *color)
{
  Uint32 clear_color;
  SDL_Rect screen_rect;

  if (this)
    {
      screen_rect.x = 0;
      screen_rect.y = 0;
      screen_rect.w = this->getWidth(this);
      screen_rect.h = this->getHeight(this);
      clear_color = SDL_MapRGB(this->getWindow(this)->format, \
			       color[0], color[1], color[2]);
      SDL_FillRect(this->getWindow(this), &screen_rect, clear_color);
    }
}

