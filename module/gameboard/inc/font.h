/*
** font.h for font in /home/guiho_r/projet/lemipc/gameboard/src/window
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 11:00:28 2013 ronan guiho
** Last update Thu Mar 28 11:28:38 2013 ronan guiho
*/

#ifndef __FONT_H__
#define __FONT_H__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define PATH_FONT "font.ttf"

typedef struct s_font
{
  TTF_Font *font;
  unsigned int size;
  SDL_Surface *(*write)(struct s_font *font, char *text, int *color);
} t_font;

t_font *new_font(char *path, unsigned int size);
SDL_Surface *font_write(t_font *this, char *text, int *color);
void delete_font(t_font *font);

#endif
