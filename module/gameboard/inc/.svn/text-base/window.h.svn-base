/*
** window.h for window in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 10:24:57 2013 ronan guiho
** Last update Thu Mar 28 14:18:29 2013 ronan guiho
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL/SDL.h>

#define WINDOW_TITLE "- LemiPC ~ Gameboard -"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define FRAME_PER_SEC 60

typedef struct s_window
{
  SDL_Surface *win;
  unsigned int width;
  unsigned int height;
  SDL_Surface *(*getWindow)(struct s_window *);
  unsigned int (*getWidth)(struct s_window *);
  unsigned int (*getHeight)(struct s_window *);
  void (*clear)(struct s_window *, int *);
} t_window;


t_window *new_window(unsigned int width, unsigned int height, char *title);
SDL_Surface *window_get_window(t_window *this);
unsigned int window_get_width(t_window *this);
unsigned int window_get_height(t_window *this);
void window_clear(t_window *this, int *color);
void delete_window(t_window *this);

#endif
