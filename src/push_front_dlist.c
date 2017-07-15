/*
** push_front_dlist.c for  in /home/WASSEX/jungle/pushswap
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 11 14:59:30 2017 Wassim Alkayar
** Last update Wed Apr 26 16:27:41 2017 Wassim Alkayar
*/

#include "my.h"

t_dlist			push_front_dlist(t_dlist li, char *str)
{
  struct s_DlistCell	*element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    return (0);
  element->str = my_strdup(str);
  element->next = NULL;
  element->back = NULL;
  if (is_empty_dlist(li))
    {
      li = malloc(sizeof(*li));
      if (li == NULL)
	return (0);
      li->length = 0;
      li->begin = element;
      li->end = element;
    }
  else
    {
      li->begin->back = element;
      element->next = li->begin;
      li->begin = element;
    }
  li->length = li->length + 1;
  return (li);
}
