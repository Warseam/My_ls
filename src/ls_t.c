/*
** ls_t.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Fri Apr 28 23:15:58 2017 Wassim Alkayar
** Last update Sat Apr 29 15:35:46 2017 Wassim Alkayar
*/

#include "my.h"

void			ls_t(t_dlist li)
{
  struct stat		fileStat;
  struct s_DlistCell	*tmp;
  char			*timebuf;

  tmp = li->begin;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (stat(tmp->str, &fileStat) == -1)
	return ;
      timebuf = ctime(&fileStat.st_mtime);
      tmp->strtime = my_strdup(timebuf);
      if (tmp->next == NULL)
	{
	  li = order_time(li);
	  li = sort_by_month(li);
	  li = epur_name(li);
	  print_reverse_dlist(li);
	  exit(1);
	}
      tmp = tmp->next;
    }
}

void			lspt_for_t(struct s_DlistCell *tmp, struct dirent *f, DIR *dir)
{
  t_dlist		list2;
  struct s_DlistCell	*tmp2;
  char			*strbegin;

  list2 = NULL;
  list2 = prepare_sorted_list(f, dir, tmp->str);
  list2 = push_front_dlist(list2, tmp->str);
  tmp2 = list2->begin->next;
  strbegin = my_strdup(list2->begin->str);
  while (tmp2 != NULL)
    {
      tmp2->str = my_strdup(path_str(strbegin, tmp2->str));
      tmp2 = tmp2->next;
    }
  ls_t(list2);
}

void			ls_t_prepare(struct dirent *fichierlu, DIR *dir, t_dlist list)
{
  int			i;
  struct s_DlistCell	*tmp;

  i = 1;
  tmp = list->begin;
  while (i <= list->length)
    {
      if (list->length != 1)
	my_printf("%s:\n", tmp->str);
      if ((dir = opendir(tmp->str)) != NULL)
	lspt_for_t(tmp, fichierlu, dir);
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
  exit(1);
}
