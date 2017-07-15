/*
** utils5.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Fri Apr 28 23:55:36 2017 Wassim Alkayar
** Last update Sat Apr 29 15:47:08 2017 Wassim Alkayar
*/

#include "my.h"

char	*modif_time_str(char *str)
{
  char	*tmp;
  int	i;
  int	j;

  j = 0;
  tmp = malloc(sizeof(char) * 25);
  i = 20;
  while (str[i] != '\0')
    {
      tmp[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  i = 4;
  while (i < 19)
    {
      tmp[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  tmp[j] = '\0';
  return (tmp);
}

char			*month_gestion(char *str, int i, int j, char *nb)
{
  char			*replace;

  replace = malloc(sizeof(char) * my_strlen(str));
  while (i <= 4)
    {
      replace[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  nb = my_strdup(month_number(nb, str[i], str[i + 1], str[i + 2]));
  replace[j] = nb[0];
  if (nb[1] != '\0')
    {
      replace[j + 1] = nb[1];
      j = j + 1;
    }
  i = i + 3;
  while (str[i] != '\0')
    {
      j = j + 1;
      replace[j] = str[i];
      i = i + 1;
    }
  replace[j] = '\0';
  return (replace);
}

t_dlist			order_time(t_dlist list)
{
  struct s_DlistCell	*tmp;
  int			i;
  int			j;
  char			*nb;

  nb = NULL;
  i = 0;
  j = 0;
  list->begin = list->begin->next;
  tmp = list->begin;
  while (tmp != NULL)
    {
      tmp->strtime = modif_time_str(tmp->strtime);
      tmp->strtime = month_gestion(tmp->strtime, i, j, nb);
      tmp = tmp->next;
    }
  return (list);
}

t_dlist			sort_by_month(t_dlist timelist)
{
  struct s_DlistCell	*tmp;
  char			*replace;
  char			*replacetime;
  int			a;

  a = 0;
  tmp = timelist->begin->next;
  while (tmp != NULL)
    {
      a = my_strncmp(tmp->strtime, tmp->back->strtime, 0, 16);
      if (a < 0)
	{
	  replace = my_strdup(tmp->str);
	  replacetime = my_strdup(tmp->strtime);
	  tmp->str = my_strdup(tmp->back->str);
	  tmp->strtime = my_strdup(tmp->back->strtime);
	  tmp->back->str = my_strdup(replace);
	  tmp->back->strtime = my_strdup(replacetime);
	  tmp = timelist->begin->next;
	}
      tmp = tmp->next;
    }
  return (timelist);
}
