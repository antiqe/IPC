/*
** main.c for main in /home/guiho_r/projet/lemipc/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Mar 26 21:26:06 2013 ronan guiho
** Last update Sat Mar 30 19:03:59 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "lemipc.h"
#include "message.h"

static char*	get_error(int error)
{
  const int	tablen = 9;
  char* const	tab[] = { "Unknown error",
			  "Cannot create team key message",
			  "Cannot create global key message",
			  "Cannot join global channel",
			  "Load size map failed",
			  "Gameboard not started",
			  "Gameboard is full",
			  "Cannot add a new bot",
			  "Cannot join team channel" };
  return (error >= tablen || !error ? "Unknown error" : tab[error]);
}

int main(int argc, char *argv[])
{
  const char  delim[2] = { MSG_DELIM, '\0' };
  t_bot	bot;
  int	error;
  t_msg buff;

  if (argc != 3)
    return (printf("Usage: %s [pathname] [teamname]\n", argv[0]));
  if (strlen(argv[2]) > TEAMNAME_SIZE_MAX || !argv[2][0])
    return (printf("%s: Error: %s and %d\n", argv[0], LENGTH_ERROR,
		   TEAMNAME_SIZE_MAX));
  if (strstr(argv[2], delim))
    return (printf("%s: Error: %s '%c'\n", argv[0], STRING_ERROR, MSG_DELIM));
  srand(time(NULL));
  if ((error = init(&bot, argv[1], argv[2])))
    return (printf("%s: Error: %s\n", argv[0], get_error(error)));
  if (recv_msg(bot.msg_id[GLOBAL], &buff, ID_START, 0) == -1)
    return (printf("%s: Error: Cannot join gameboard\n", argv[0]));
  as_leader(&bot);
  return (EXIT_SUCCESS);
}
