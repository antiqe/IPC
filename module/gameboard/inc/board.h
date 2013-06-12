/*
** gameboard.h for gameboard in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 11:21:46 2013 ronan guiho
** Last update Fri Mar 29 16:34:00 2013 ronan guiho
*/

#ifndef __BOARD_H__
#define __BOARD_H__

#include <SDL/SDL.h>

#define BOARD_WIDTH_MIN 10
#define BOARD_WIDTH_MAX 100

#define BOARD_HEIGHT_MIN 10
#define BOARD_HEIGHT_MAX 100

#define BOARD_WIDTH 800
#define BOARD_HEIGHT 600

#define BOARD_POSX 10
#define BOARD_POSY 10

typedef struct s_board
{
  int id;
  unsigned int width;
  unsigned int height;
  int (*getId)(struct s_board *);
  unsigned int (*getWidth)(struct s_board *);
  unsigned int (*getHeight)(struct s_board *);
} t_board;

SDL_Surface *board_draw(t_board *this);
void board_draw_square(SDL_Rect *line, SDL_Rect *pos);
t_board *new_board(key_t key, unsigned int width, unsigned int height);
int board_get_id(t_board *this);
unsigned int board_get_width(t_board *this);
unsigned int board_get_height(t_board *this);
void delete_board(t_board *this);

#endif
