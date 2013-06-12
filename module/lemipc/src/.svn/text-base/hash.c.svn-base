/*
** hash.c for lemIPC in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 14:00:44 2013 alexis leprovost
** Last update Wed Mar 27 17:45:17 2013 alexis leprovost
*/

#include <math.h>

#include "hash.h"

int	hash(const char* str)
{
  int	hash;
  int	i;

  i = -1;
  hash = MAGIC_KEY;
  while (str && str[++i])
    hash = ((hash << 1) + hash) + (int)str[i];
  return (hash);
}
