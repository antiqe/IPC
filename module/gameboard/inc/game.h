/*
** game.h for game in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/inc
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 21:14:01 2013 ronan guiho
** Last update Sun Mar 31 14:47:58 2013 ronan guiho
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "list.h"
#include "font.h"
#include "board.h"
#include "window.h"

#define COUNT_WAITING 2

#define MSG_WAITING "Waiting for teams..."

#define COLOR_R_WAITING 255
#define COLOR_G_WAITING 0
#define COLOR_B_WAITING 0

#define POS_X_WAITING 180
#define POS_Y_WAITING 230

#define POS_X_BUTTON 410
#define POS_Y_BUTTON 600

#define SIZE_X_BUTTON 200
#define SIZE_Y_BUTTON 50

#define POS_X_VICTORY 180
#define POS_Y_VICTORY 230

#define ABS(x) ((x < 0) ? (-x) : (x))

enum e_status
{
  WAITING = 0,
  INGAME
};

typedef struct s_game
{
  enum e_status status;
  int id_msg;
  int id_msge;
  int id_sem;
  t_window *window;
  t_board *board;
  t_list *list_team;
  t_font *font_team;
} t_game;

int run(t_game *game);
int victory(t_game *game);
void display_team_clear(t_game *game);
void display_p(void *context, void *data, int i);
int run_display_play(t_game *game, t_font *font);
int run_wait_client(t_game *game);
void get_random_color(int *color);
void run_message_sizeboard(t_game *game);
int run_wait_msg(t_game *game, t_font *font);
void run_message_move(t_game *game, char *buffer);
void run_message_delclient(t_game *game, char *buffer);
int run_message_newclient(t_game *game, t_font *font, char *buffer);
void run_wait_display(t_game *game, t_font *font, int pos);
int display_allteam(t_game *game);

#endif
