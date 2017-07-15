/*
** no_options.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 18 00:12:23 2017 Wassim Alkayar
** Last update Sun Jul 16 01:35:59 2017 Wassim Alkayar
*/

#include "my.h"

void			case_arg_mult(struct dirent *fichierlu, DIR *dir, t_dlist list)
{
  int			i;
  struct s_DlistCell	*tmp;

  i = 1;
  if (is_empty_dlist(list) == true)
    exit(84);
  tmp = list->begin;
  while (i <= list->length)
    {
      if (list->length != 1)
	my_printf("%s:\n", tmp->str);
      if ((dir = opendir(tmp->str)) != NULL)
	print_dlist_files(prepare_sorted_list(fichierlu, dir, tmp->str));
      else
	{
	  my_printf("ls : cannot access '%s': ", tmp->str);
	  perror("");
	}
      if (i < list->length)
	my_putchar('\n');
      tmp = tmp->next;
      i = i + 1;
    }
}
