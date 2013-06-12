/*
** send.c for lemipc in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 16:58:07 2013 alexis leprovost
** Last update Thu Mar 28 17:50:13 2013 ronan guiho
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <strings.h>

#include "message.h"

int	send_msg(int id, long type, char* str, int flag)
{
  const unsigned int	len = !str ? 0 : strlen(str);
  t_msg		msg;

  msg.type = type;
  bzero(msg.str, MSG_SIZE);
  if (len > MSG_SIZE)
    return (EXIT_FAILURE);
  memcpy(msg.str, str, MSG_SIZE);
  msgsnd(id, &msg, sizeof(t_msg), flag);
  return (EXIT_SUCCESS);
}
