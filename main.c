/*
** test.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon Apr 17 14:41:00 2017 Wassim Alkayar
** Last update Sat Apr 29 15:30:03 2017 Wassim Alkayar
*/

#include "my.h"

void			function_call(t_dlist list, int l, int R, int t)
{
  struct dirent		*fichierlu;
  DIR			*dir;

  fichierlu = NULL;
  dir = NULL;
  if (t == 1)
    ls_t_prepare(fichierlu, dir, list);
  if (l == 1 && R == 0)
    ls_l_prepare(fichierlu, dir, list);
  if (l == 0 && R == 1)
    ls_R_prepare(list);
  if (l == 1 && R == 1)
    ls_R_l_prepare(list);
}

void	flags_activation(t_dlist list, char *flags, int ct)
{
  int	l;
  int	R;
  int	t;

  l = 0;
  R = 0;
  t = 0;
  list = delete_list_flags(list);
  if (is_empty_dlist(list))
    list = push_back_dlist(list, ".");
  while (flags[ct] != '\0')
    {
      if (flags[ct] == 'l')
	l = 1;
      if (flags[ct] == 'R')
	R = 1;
      if (flags[ct] == 't')
	t = 1;
      ct = ct + 1;
    }
  function_call(list, l, R, t);
}

void			mult_argc_two(t_dlist list, char *flags)
{
  struct s_DlistCell	*tmp;
  int			ct;
  t_dlist		list2;

  list2 = NULL;
  ct = 0;
  if (is_empty_dlist(list) == false)
    {
      tmp = list->begin;
      if (list->length == 1 && tmp->str[0] == '-' && tmp->str[1] != '\0')
	list2 = push_back_dlist(list2, ".");
      else if (tmp->str[0] == '-' && tmp->str[1] != '\0')
	{
	  list->begin = tmp->next;
	  tmp->next->back = NULL;
	}
    }
  else if (is_empty_dlist(list) == true)
    {
      list2 = push_back_dlist(list2, ".");
      flags_activation(list2, flags, ct);
      return ;
    }
  flags_activation(list, flags, ct);
}

void			mult_argc(int argc, char **argv, t_dlist list, int i)
{
  DIR			*dir;
  struct dirent		*fichierlu;
  t_dlist		listflags;
  char			*flags;

  listflags = NULL;
  dir = NULL;
  fichierlu = NULL;
  while (argc > i)
    {
      list = push_back_dlist(list, argv[i]);
      i = i + 1;
    }
  listflags = copy_flags(list, listflags);
  list = delete_list_flags(list);
  if (is_empty_dlist(listflags) == false)
    {
      flags = my_strdup(list_to_string(listflags));
      mult_argc_two(list, flags);
    }
  else
    case_arg_mult(fichierlu, dir, list);
}

int			main(int argc, char **argv)
{
  DIR			*dir;
  struct dirent		*fichierlu;
  t_dlist		list;
  int			i;

  i = 1;
  list = NULL;
  dir = NULL;
  fichierlu = NULL;
  if (argc == 1)
    {
      print_dlist_files(prepare_sorted_list(fichierlu, dir, "."));
      return (0);
    }
  mult_argc(argc, argv, list, i);
  return (0);
}
