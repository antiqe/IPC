/*
** list.h for list in /home/guiho_r/projet/objdump/list/inc
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Mar 11 19:22:05 2013 ronan guiho
** Last update Sun Mar 31 15:49:32 2013 ronan guiho
*/

#ifndef __LIST_H__
#define __LIST_H__

typedef struct s_list_data
{
  void *data;
  struct s_list_data *prev;
  struct s_list_data *next;
} t_list_data;

typedef struct s_list
{
  t_list_data *data;
  int count;
  t_list_data *head;
  t_list_data *back;

  int (*size)(struct s_list *);
  int (*push_back)(struct s_list *, void *);
  int (*remove_if)(struct s_list *, int (*)(void *));
  int (*erase)(struct s_list *, void *);
  int (*iter)(struct s_list *, void (*)(void *, void *, int), void *);
  void (*clear)(struct s_list *);
  void *(*begin)(struct s_list *);
  void *(*end)(struct s_list *);
  void *(*find_if)(struct s_list *,
		   int (*)(void *, void *, void *), void *, void *);
  void (*sort)(struct s_list *, int (*)(void *, void *, void *), void *);
  void *(*at)(struct s_list *, int);
} t_list;

int size(t_list *this);
int push_back(t_list *this, void *data);
int remove_if(t_list *this, int (*)(void *));
int erase(t_list *this, void *);
void *find_if(t_list *this, int (*)(void *, void *, void *),
	      void *, void *);
int iter(t_list *this, void (*)(void *, void *, int), void *);
void clear(t_list *this);
void *at(t_list *this, int n);
void *begin(t_list *this);
void *end(t_list *this);
void sort(t_list *this, int (*)(void *, void *, void *), void *);

t_list *new_list();
void delete_data(t_list *this, t_list_data **data);
void delete_list(t_list *this);

#endif
