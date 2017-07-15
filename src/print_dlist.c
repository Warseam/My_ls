/*
** print_dlist.c for  in /home/WASSEX/jungle/pushswap
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 11 16:08:47 2017 Wassim Alkayar
** Last update Sat Apr 29 15:37:26 2017 Wassim Alkayar
*/

#include "my.h"

void			print_dlist(t_dlist li)
{
  struct s_DlistCell	*tmp;

  if (is_empty_dlist(li))
    return ;
  tmp = li->begin;
  while (tmp != NULL)
    {
      my_printf("[%s] ", tmp->str);
      tmp = tmp->next;
    }
  my_printf("\n");
}
