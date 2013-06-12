/*
** player.h for player in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 10:52:22 2013 ronan guiho
** Last update Fri Mar 29 18:13:15 2013 ronan guiho
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef enum e_pos
{
  X = 0,
  Y
} t_pos;

typedef struct s_player
{
  int pos[2];
  int color[3];
} t_player;

t_player *new_player(int *pos);
void player_display(void *context, void *data, int i);
int player_find_by_pos(void *context, void *data, void *value);

#endif
