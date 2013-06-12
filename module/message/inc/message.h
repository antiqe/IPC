/*
** message.h for message in /home/guiho_r/projet/lemipc/inc
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar 27 15:42:42 2013 ronan guiho
** Last update Sun Mar 31 15:17:50 2013 alexis leprovost
*/

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#define	MSG_SIZE	256
#define MSG_DELIM	'|'

typedef enum e_idmsg
{
  ID_NEWCLIENT = 1,
  ID_POSCLIENT,
  ID_GETSIZE,
  ID_START,
  ID_SETSIZE,
  ID_DELCLIENT,
  ID_NEWLEADER,
  ID_MOVECLIENT,
  ID_ESCAPE,
  ID_ORDERDONE,
  ID_END
} t_idmsg;

typedef struct s_msg
{
  long	type;
  char	str[MSG_SIZE];
} t_msg;

int	send_msg(int id, long type, char* str, int flag);
int	recv_msg(int id, t_msg* msg, t_idmsg type, int flag);

#endif
