/*
** lemipc.h for lemipc in /home/leprov_a//project/tek2/lemIPC/dev/lemIPC
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar 27 14:24:43 2013 alexis leprovost
** Last update Sat Mar 30 19:38:19 2013 alexis leprovost
*/

#ifndef _LEMIPC_H_
#define _LEMIPC_H_

#include <sys/types.h>

#define TEAM_KEY_MSG_ERROR	1
#define	GLOBAL_KEY_MSG_ERROR	2
#define GLOBAL_ID_MSG_ERROR	3
#define MAP_ERROR		4
#define DATA_ERROR		5
#define FULL_MAP_ERROR		6
#define	BOT_ERROR		7
#define TEAM_ID_MSG_ERROR	8

#define TEAMNAME_SIZE_MAX	64

#define LENGTH_ERROR	"Teamname length must be contained between 1"
#define STRING_ERROR	"Teamname string cannot contain the character"

#define	ABS(v)	((v) < 0 ? ((v) * (-1)) : (v))

#define RANGE_LEADER	10

typedef enum e_bool
  {
    FALSE = 0,
    TRUE
  } t_bool;

typedef enum e_key
  {
    GLOBAL = 0,
    TEAM
  } t_key;

typedef enum e_pos
  {
    X = 0,
    Y
  } t_pos;

typedef enum e_side
  {
    NORTH = 0,
    SOUTH,
    WEST,
    EAST
  } t_side;

typedef struct s_map
{
  int	width;
  int	height;
  int	size;
} t_map;

typedef struct s_bot
{
  key_t		key[2];
  int		msg_id[2];
  int		shm_id;
  int		sem_id;
  int		id;
  int		pos[2];
  t_map		map;
  void		*data;
  int		(*run)(struct s_bot*);
} t_bot;

int	init(t_bot* bot, char* pathname, char* teamname);

int	as_leader(t_bot* bot);
int	as_follower(t_bot* bot);

int	is_dead(t_bot* bot);
int	is_victory(t_bot* bot);
void	get_teammate(t_bot* bot, int* pos);
int	find_free_case(t_bot* bot, int *pos);

void	sem_lock(int id);
void	sem_unlock(int id);

void	die(t_bot* bot);
void	move(t_bot* bot, int x, int y);

void	get_target(t_bot* bot, int* pos);
void	find_case_to_move(t_bot* bot, int* pos);

#endif /* _LEMIPC_H_ */
