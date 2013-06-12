/*
** list2.c for list2 in /home/guiho_r/depot/tmp/depot/new/nmobjdump-2015s-2016-2017si-guiho_r/lib/list/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 17 22:47:44 2013 ronan guiho
** Last update Sun Mar 31 16:28:57 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int iter(t_list *this, void (*func)(void *, void *, int), void *context)
{
  unsigned int i;
  t_list_data *tmp;

  i = 0;
  if (this && func)
    {
      tmp = this->head;
      while (tmp)
	{
	  func(context, tmp->data, i);
	  tmp = tmp->next;
	  if (tmp == this->head)
	    return (EXIT_SUCCESS);
	  ++i;
	}
    }
  return (EXIT_SUCCESS);
}

void clear(t_list *this)
{
  t_list_data *tmp;
  t_list_data *tmp_delete;

  if (this)
    {
      tmp = this->head;
      while (tmp)
	{
	  tmp_delete = tmp;
	  tmp = tmp->next;
	  delete_data(this, &tmp_delete);
	}
    }
}

void sort(t_list *this, int (*pred)(void *, void *, void *), void *context)
{
  int flag;
  t_list_data *tmp;
  void *data;

  if (this && pred)
    {
      flag = 0;
      data = NULL;
      tmp = this->head;
      while (tmp)
	{
	  if (tmp->next)
	    if (tmp->data && tmp->next->data)
	      if (pred(context, tmp->data, tmp->next->data) > 0)
		{
		  data = tmp->data;
		  tmp->data = tmp->next->data;
		  tmp->next->data = data;
		  flag = 1;
		}
	  tmp = tmp->next;
	}
      if (flag == 1)
	sort(this, pred, context);
    }
}

void *find_if(t_list *this, int (*pred)(void *, void *, void *),
	      void *value, void *context)
{
  t_list_data *tmp;

  if (this)
    {
      tmp = this->head;
      while (tmp)
	{
	  if (pred(context, tmp->data, value) == 1)
	    return (tmp->data);
	  tmp = tmp->next;
	}
    }
  return (NULL);
}
