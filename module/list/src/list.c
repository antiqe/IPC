/*
** list.c for list in /home/guiho_r/projet/objdump/list/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Mar 11 22:57:46 2013 ronan guiho
** Last update Sat Mar 30 18:37:41 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

t_list *new_list()
{
  t_list *this;

  if ((this = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  this->data = NULL;
  this->count = 0;
  this->head = NULL;
  this->back = NULL;
  this->size = &size;
  this->push_back = &push_back;
  this->remove_if = &remove_if;
  this->erase = &erase;
  this->iter = &iter;
  this->clear = &clear;
  this->begin = &begin;
  this->end = &end;
  this->sort = &sort;
  this->find_if = &find_if;
  this->at = &at;
  return (this);
}

void *begin(t_list *this)
{
  return (this->head->data);
}

void *end(t_list *this)
{
  return (this->back->data);
}

void *at(t_list *this, int n)
{
  t_list_data *tmp;
  unsigned int i;

  i = 0;
  if (this)
    {
      tmp = this->head;
      while (tmp)
	{
	  if (i == (unsigned int)n)
	    return (tmp->data);
	  ++i;
	  tmp = tmp->next;
	}
    }
  return (NULL);
}

void delete_list(t_list *this)
{
  if (this)
    {
      this->clear(this);
      free(this);
    }
}
