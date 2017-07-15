/*
** ls_l.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 18 00:27:21 2017 Wassim Alkayar
** Last update Sun Jul 16 01:37:48 2017 Wassim Alkayar
*/

#include "my.h"

void			ut_tw(struct stat fileStat, int a,
			      struct s_DlistCell *tmp, int maxsize)
{
  char			*timebuf;
  int			i;

  i = get_length_number(fileStat.st_size);
  while (i < maxsize)
    {
      my_putchar(' ');
      i = i + 1;
    }
  my_put_nbr(fileStat.st_size);
  my_putstr(" ");
  timebuf = ctime(&fileStat.st_mtime);
  timebuf = timebuf_changer(timebuf);
  my_putstr(timebuf);
  my_putstr(" ");
  if (a == 1)
    my_putstr(file_name(tmp->str));
  else
    my_putstr(file_name(tmp->str));
  my_putchar('\n');
}

void			ls_l(t_dlist li)
{
  struct stat		fileStat;
  struct s_DlistCell	*tmp;
  int			a;
  int			total;
  int			maxsize;

  maxsize = format_ls_l(li);
  tmp = li->begin;
  tmp = tmp->next;
  total = count_blocks(li->begin->str);
  my_putstr("total ");
  my_put_nbr(total);
  my_putchar('\n');
  while (tmp != NULL)
    {
      if (stat(tmp->str, &fileStat) == -1)
	return ;
      a = mode(fileStat);
      utils_ls_l(fileStat);
      ut_tw(fileStat, a, tmp, maxsize);
      if (tmp->next == NULL)
	return ;
      tmp = tmp->next;
    }
}

void			lspt(struct s_DlistCell *tmp, struct dirent *f, DIR *dir)
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
  ls_l(list2);
}

void			ls_l_prepare(struct dirent *fichierlu, DIR *dir, t_dlist list)
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
	lspt(tmp, fichierlu, dir);
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
