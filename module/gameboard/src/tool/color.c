/*
** color.c for color in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src/tool
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Mar 29 14:20:51 2013 ronan guiho
** Last update Fri Mar 29 16:35:13 2013 ronan guiho
*/

#include <stdlib.h>

#include "game.h"

void get_random_color(int *color)
{
  static int	nb;

  nb = (nb == 0) ? rand() : nb;
  nb = ((nb >> 2) + nb) + 0x42;
  color[0] = ABS(nb) % 256;
  color[1] = (ABS(nb) >> 8) % 256;
  color[2] = (ABS(nb) >> 16) % 256;
}
