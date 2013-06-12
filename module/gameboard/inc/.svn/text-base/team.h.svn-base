/*
** team.h for team in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 10:50:24 2013 ronan guiho
** Last update Sat Mar 30 18:50:46 2013 ronan guiho
*/

#ifndef __TEAM_H__
#define __TEAM_H__

#include "list.h"

#define SIZE_FONT_TEAM 20
#define SPACING_DISPLAY_TEAM 30
#define POSX_DISPLAY_TEAM 830
#define POSY_DISPLAY_TEAM 50

typedef struct s_team
{
  int id;
  char *name;
  t_list *player;
  int color[3];
} t_team;

t_team *new_team(char *name, int id);
void team_display(void *context, void *data, int i);
void team_sendall_start(void *context, void *data, int i);
void team_sendall_end(void *context, void *data, int i);
int team_find_by_id(void *context, void *data, void *value);

#endif
