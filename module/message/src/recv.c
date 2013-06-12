/*
** recv.c for lemipc in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 17:16:20 2013 alexis leprovost
** Last update Thu Mar 28 16:45:25 2013 ronan guiho
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <strings.h>

#include "message.h"

int	recv_msg(int id, t_msg* msg, t_idmsg type, int flag)
{
  return (msgrcv(id, msg, sizeof(*msg), type, flag));
}
