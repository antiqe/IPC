/*
** gameboard.c for gameboard in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 11:16:45 2013 ronan guiho
** Last update Sat Mar 30 12:54:09 2013 ronan guiho
*/

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "window.h"
#include "board.h"

void	new_board_init(t_board *board, unsigned int width,
		       unsigned int height)
{
  board->width = width;
  board->height = height;
  board->getId = &board_get_id;
  board->getWidth = &board_get_width;
  board->getHeight = &board_get_height;
}

t_board *new_board(key_t key, unsigned int width, unsigned int height)
{
  t_board *board;

  if ((board = malloc(sizeof(t_board))) == NULL)
    return (NULL);
  if ((width < BOARD_WIDTH_MIN || width > BOARD_WIDTH_MAX) ||
      (height < BOARD_HEIGHT_MIN || height > BOARD_HEIGHT_MAX))
    {
      printf("board: Error:%d > WIDTH < %d", BOARD_WIDTH_MIN, BOARD_WIDTH_MAX);
      printf(" and %d > HEIGHT < %d\n", BOARD_HEIGHT_MIN, BOARD_HEIGHT_MAX);
      return (NULL);
    }
  if ((board->id = shmget(key, width * height, SHM_R | SHM_W)) != -1)
    {
      printf("board: Error: gameboard with key<%d>", key);
      printf(" and id<%d> as already exist\n", board->id);
      return (NULL);
    }
  if ((board->id = shmget(key, (width * height) * sizeof(int), \
			  IPC_CREAT | SHM_R | SHM_W)) == -1)
    {
      printf("board: Error: cannot create gameboard");
      return (NULL);
    }
  new_board_init(board, width, height);
  return (board);
}

unsigned int board_get_width(t_board *this)
{
  return (this->width);
}

unsigned int board_get_height(t_board *this)
{
  return (this->height);
}

void delete_board(t_board *this)
{
  if (this)
    shmctl(this->getId(this), IPC_RMID, NULL);
}
