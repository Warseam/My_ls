/*
** push_back_dlist.c for  in /home/WASSEX/jungle/pushswapessai/pushswap
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 11 18:16:33 2017 Wassim Alkayar
** Last update Wed Apr 26 16:27:31 2017 Wassim Alkayar
*/

#include "my.h"

t_dlist			push_back_dlist(t_dlist li, char *str)
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
      li->end->next = element;
      element->back = li->end;
      li->end = element;
    }
  li->length = li->length + 1;
  return (li);
}
