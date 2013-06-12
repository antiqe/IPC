/*
** main.c for main in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 09:53:51 2013 ronan guiho
** Last update Sun Mar 31 15:30:33 2013 alexis leprovost
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

#include "team.h"
#include "game.h"

void usage()
{
  printf("Usage: ./gameboard [pathname] [width] [height]\n");
}

int init_game(t_game *game, unsigned int width,
	      unsigned int height, key_t key)
{
  if ((game->board = new_board(key, width, height)) == NULL)
    return (EXIT_FAILURE);
  if ((game->window = new_window(WINDOW_WIDTH, WINDOW_HEIGHT,
				WINDOW_TITLE)) == NULL)
    {
      printf("./gameboard: Error: Cannot create window.\n");
      return (EXIT_FAILURE);
    }
  if ((game->list_team = new_list()) == NULL)
    return (EXIT_FAILURE);
  if ((game->id_msg = msgget(key, SHM_R | SHM_W)) != -1)
    {
      printf("./gameboard: Error: Stream <%d> has already exist.\n",
	     game->id_msg);
      return (EXIT_FAILURE);
    }
  game->id_msg = msgget(key, IPC_CREAT | SHM_R | SHM_W);
  return (EXIT_SUCCESS);
}

int init_semaphore(t_game *game, key_t key)
{
  srand(time(NULL));
  if ((game->id_sem = semget(key, 1, SHM_R | SHM_W)) != -1)
    {
      printf("./gameboard: Error: Semaphore <%d> has already exist.\n",
	     game->id_sem);
      return (EXIT_FAILURE);
    }
  game->id_sem = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
  semctl(game->id_sem, 0, SETVAL, 1);
  if ((game->font_team = new_font(PATH_FONT, SIZE_FONT_TEAM)) == NULL)
    return (EXIT_FAILURE);
  game->status = WAITING;
  return (EXIT_SUCCESS);
}

void delete_game(t_game *game)
{
  semctl(game->id_sem, IPC_RMID, 0);
  msgctl(game->id_msg, IPC_RMID, NULL);
  delete_board(game->board);
}

int main(int ac, char **av)
{
  key_t key;
  t_game game;

  if (ac != 4)
    {
      usage();
      return (EXIT_FAILURE);
    }
  if ((key = ftok(av[1], 0)) == -1)
    return (EXIT_FAILURE);
  if (init_game(&game, atoi(av[2]), atoi(av[3]), key) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (init_semaphore(&game, key) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (run(&game) == EXIT_FAILURE)
    {
      delete_game(&game);
      return (EXIT_FAILURE);
    }
  delete_game(&game);
  return (EXIT_SUCCESS);
}
