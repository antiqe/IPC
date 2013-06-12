/*
** core.c for coree in /home/guiho_r/projet/lemipc/gameboard/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 13:15:49 2013 ronan guiho
** Last update Sun Mar 31 17:05:19 2013 ronan guiho
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <SDL/SDL_mixer.h>

#include "game.h"
#include "team.h"
#include "board.h"
#include "message.h"
#include "console.h"

int run_init(t_game *game, SDL_Rect *rect, SDL_Surface **surface)
{
  Mix_Music *musique;

  if ((run_wait_client(game)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  rect->x = BOARD_POSX;
  rect->y = BOARD_POSY;
  (*surface) = board_draw(game->board);
  SDL_BlitSurface(*surface, NULL, game->window->win, rect);
  display_allteam(game);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
    printf("%s\n", Mix_GetError());
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
  if ((musique = Mix_LoadMUS("music.ogg")) != NULL)
    Mix_PlayMusic(musique, -1);
  return (EXIT_SUCCESS);
}

int run_destroy(t_game *game, SDL_Surface *surface, SDL_Rect *rect)
{
  display_allteam(game);
  SDL_BlitSurface(surface, NULL, game->window->win, rect);
  game->list_team->iter(game->list_team, team_display, game);
  if (victory(game) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void run_execute(t_game *game, int tmp)
{
  if (game->list_team->size(game->list_team) != tmp)
    display_allteam(game);
  display_console(game);
}

int run(t_game *game)
{
  int tmp;
  SDL_Event event;
  SDL_Rect rect;
  SDL_Surface *surface;

  surface = NULL;
  if ((run_init(game, &rect, &surface)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  tmp = game->list_team->size(game->list_team);
  while (game->list_team->size(game->list_team) != 1)
    {
      while (SDL_PollEvent(&event))
	if (event.type == SDL_QUIT)
	  return (EXIT_FAILURE);
      SDL_BlitSurface(surface, NULL, game->window->win, &rect);
      game->list_team->iter(game->list_team, team_display, game);
      run_execute(game, tmp);
      tmp = game->list_team->size(game->list_team);
      run_wait_msg(game, NULL);
      SDL_Flip(game->window->win);
      usleep(1000000 / FRAME_PER_SEC);
    }
  if ((run_destroy(game, surface, &rect)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
