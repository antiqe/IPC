/*
** window.c<2> for window in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 10:20:31 2013 ronan guiho
** Last update Thu Mar 28 11:00:01 2013 ronan guiho
*/

#include <stdlib.h>
#include <SDL/SDL.h>

#include "window.h"

t_window *new_window(unsigned int width, unsigned int height, char *title)
{
  t_window *window;

  SDL_Init(SDL_INIT_VIDEO);
  if ((window = malloc(sizeof(t_window))) == NULL)
    return (NULL);
  window->getWidth = &window_get_width;
  window->getHeight = &window_get_height;
  window->getWindow = &window_get_window;
  window->clear = &window_clear;
  window->width = width;
  window->height = height;
  if ((window->win = SDL_SetVideoMode(width, height, \
				      32, SDL_HWSURFACE)) == NULL)
    return (NULL);
  SDL_WM_SetCaption(title, NULL);
  return (window);
}

void	delete_window(t_window *this)
{
  if (this)
    free(this);
}
