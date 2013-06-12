/*
** core_init.c for core_init in /home/guiho_r/depot/lemipc-2015s-2016-2017si-guiho_r/module/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Mar 28 21:04:32 2013 ronan guiho
** Last update Sun Mar 31 15:20:52 2013 ronan guiho
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include "team.h"
#include "game.h"
#include "console.h"
#include "message.h"
#include "font.h"

int run_wait_msg(t_game *game, t_font *font)
{
  t_msg msg;

  if ((msgrcv(game->id_msg, &msg, sizeof(msg), 0, IPC_NOWAIT)) != -1)
    {
      if (msg.type == ID_GETSIZE)
	run_message_sizeboard(game);
      else if (msg.type == ID_NEWCLIENT)
	{
	  if (run_message_newclient(game, font, msg.str) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else if (msg.type == ID_POSCLIENT)
	run_message_move(game, msg.str);
      else if (msg.type == ID_DELCLIENT)
	run_message_delclient(game, msg.str);
    }
  return (EXIT_SUCCESS);
}

void run_wait_display(t_game *game, t_font *font, int pos)
{
  int color[2][3];
  SDL_Rect rect;
  SDL_Surface *text;
  char buffer[256];

  rect.x = POS_X_WAITING;
  rect.y = POS_Y_WAITING;
  color[0][0] = 0;
  color[0][1] = 0;
  color[0][2] = 0;
  color[1][0] = COLOR_R_WAITING;
  color[1][1] = COLOR_G_WAITING;
  color[1][2] = COLOR_B_WAITING;
  bzero(buffer, 256);
  game->window->clear(game->window, color[0]);
  sprintf(buffer, "%s (%d/%d)", MSG_WAITING, pos, COUNT_WAITING);
  text = font->write(font, buffer, color[1]);
  SDL_BlitSurface(text, NULL, game->window->getWindow(game->window), &rect);
}

int run_wait_client_event(t_game *game, int *pos, int *flag)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (EXIT_FAILURE);
      if (event.type == SDL_MOUSEBUTTONDOWN)
	{
	  SDL_GetMouseState(&pos[0], &pos[1]);
	  if (game->list_team->size(game->list_team) >= COUNT_WAITING)
	    if ((pos[0] >= POS_X_BUTTON && \
		 pos[0] <= (POS_X_BUTTON + SIZE_X_BUTTON)) && \
		(pos[1] >= POS_Y_BUTTON && \
		 pos[1] <= (POS_Y_BUTTON + SIZE_Y_BUTTON)))
	      (*flag) = 1;
	}
    }
  return (EXIT_SUCCESS);
}

void run_wait_client_end(t_game *game)
{
  int color[3];

  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  game->window->clear(game->window, color);
  game->status = INGAME;
  game->list_team->iter(game->list_team, team_sendall_start, game);
}

int run_wait_client(t_game *game)
{
  int flag;
  int pos[2];
  t_font *font;
  t_font *font1;

  flag = 0;
  if ((font = new_font(PATH_FONT, 50)) == NULL)
    return (EXIT_FAILURE);
  if ((font1 = new_font(PATH_FONT, 30)) == NULL)
    return (EXIT_FAILURE);
  run_wait_display(game, font, game->list_team->size(game->list_team));
  while (!flag)
    {
      if ((run_wait_msg(game, font)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (game->list_team->size(game->list_team) >= COUNT_WAITING)
	run_display_play(game, font1);
      if ((run_wait_client_event(game, pos, &flag)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      SDL_Flip(game->window->win);
      usleep(1000000 / FRAME_PER_SEC);
    }
  run_wait_client_end(game);
  return (EXIT_SUCCESS);
}
