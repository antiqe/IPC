/*
** lis1.c for list1 in /home/guiho_r/depot/tmp/depot/new/nmobjdump-2015s-2016-2017si-guiho_r/lib/list/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 17 22:44:46 2013 ronan guiho
** Last update Sun Mar 31 16:27:28 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int size(t_list *this)
{
  if (!this)
    return (0);
  return (this->count);
}

int push_back(t_list *this, void *data)
{
  t_list_data *ptr;

  if (this)
    {
      if ((ptr = malloc(sizeof(t_list_data))) == NULL)
	return (EXIT_FAILURE);
      ptr->data = data;
      ptr->next = NULL;
      ptr->prev = NULL;
      if (this->head == NULL)
	{
	  this->head = ptr;
	  this->back = ptr;
	}
      else
	{
	  ptr->prev = this->back;
	  this->back->next = ptr;
	  this->back = ptr;
	}
      ++(this->count);
    }
  return (EXIT_SUCCESS);
}

int erase(t_list *this, void *data)
{
  t_list_data *tmp;

  if (this)
    {
      tmp = this->head;
      while (tmp)
	{
	  if (tmp->data == data)
	    {
	      delete_data(this, &tmp);
	      return (EXIT_SUCCESS);
	    }
	  tmp = tmp->next;
	}
    }
  return (EXIT_FAILURE);
}

int remove_if(t_list *this, int (*pred)(void *))
{
  t_list_data *tmp;
  t_list_data *tmp_delete;

  if (pred && this)
    {
      tmp = this->head;
      while (tmp)
	{
	  tmp_delete = NULL;
	  if (pred(tmp->data) == 1)
	    tmp_delete = tmp;
	  tmp = tmp->next;
	  if (tmp_delete)
	    delete_data(this, &tmp_delete);
	}
    }
  return (EXIT_FAILURE);
}

void delete_data(t_list *this, t_list_data **data)
{
  if (this && (*data))
    {
      if ((*data)->next == NULL && (*data)->prev != NULL)
	{
	  this->back = (*data)->prev;
	  (*data)->prev->next = NULL;
	}
      else if ((*data)->next != NULL && (*data)->prev == NULL)
	{
	  this->head = (*data)->next;
	  (*data)->next->prev = NULL;
	}
      else if ((*data)->next == NULL && (*data)->prev == NULL)
	{
	  this->head = NULL;
	  this->back = NULL;
	}
      else
	{
	  (*data)->prev->next = (*data)->next;
	  (*data)->next->prev = (*data)->prev;
	}
      --(this->count);
    }
}
