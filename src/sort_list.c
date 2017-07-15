/*
** my_sort_list.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Apr 22 12:09:04 2017 Wassim Alkayar
** Last update Sun Jul 16 01:38:13 2017 Wassim Alkayar
*/

#include "my.h"

t_dlist			sort_list(t_dlist list)
{
  struct s_DlistCell	*tmp;
  char			*replace;
  int			a;

  a = 0;
  tmp = list->begin->next;
  while (tmp != NULL)
    {
      a = my_alphacmp(tmp->str, tmp->back->str);
      if (a < 0)
	{
	  replace = my_strdup(tmp->str);
	  tmp->str = my_strdup(tmp->back->str);
	  tmp->back->str = my_strdup(replace);
	  tmp = list->begin->next;
	}
      tmp = tmp->next;
    }
  return (list);
}

t_dlist		prepare_sorted_list(struct dirent *fichierlu,
				    DIR *dir,
				    char *toopen)
{
  t_dlist	listsort;

  listsort = NULL;
  dir = opendir(toopen);
  if (dir == NULL)
    errorsystem();
  while ((fichierlu = readdir(dir)) != NULL)
    {
      if (fichierlu->d_name[0] != '.')
	listsort = push_back_dlist(listsort, fichierlu->d_name);
    }
  if (closedir(dir) == -1)
    errorsystem();
  listsort = sort_list(listsort);
  listsort = sort_list(listsort);
  return (listsort);
}
