/*
** font.c for font in /home/guiho_r/projet/lemipc/gameboard/src/window
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 11:02:45 2013 ronan guiho
** Last update Fri Mar 29 14:53:20 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "font.h"

t_font *new_font(char *path, unsigned int size)
{
  t_font *font;

  TTF_Init();
  if ((font = malloc(sizeof(t_font))) == NULL)
    return (NULL);
  if ((font->font = TTF_OpenFont(path, size)) == NULL)
    {
      printf("board: Error: cannot open font.\n");
      return (NULL);
    }
  font->size = size;
  font->write = &font_write;
  return (font);
}

SDL_Surface *font_write(t_font *this, char *text, int *color)
{
  SDL_Surface *stext;
  SDL_Color scolor;

  scolor.r = color[0];
  scolor.g = color[1];
  scolor.b = color[2];
  if ((stext = TTF_RenderText_Solid(this->font, text, scolor)) == NULL)
    return (NULL);
  return (stext);
}

void delete_font(t_font *font)
{
  if (font)
    free(font);
}
