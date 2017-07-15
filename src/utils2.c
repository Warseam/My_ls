/*
** utils2.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Apr 22 16:28:43 2017 Wassim Alkayar
** Last update Sun Jul 16 01:38:37 2017 Wassim Alkayar
*/

#include "my.h"

t_dlist			copy_flags(t_dlist list, t_dlist listflags)
{
  struct s_DlistCell	*tmp;
  int			i;

  i = 0;
  tmp = list->begin;
  while (tmp != NULL)
    {
      if (tmp->str[0] == '-' && tmp->str[i + 1] != '\0')
	{
	  while (tmp->str[i] != '\0')
	    {
	      if (tmp->str[i] == 'l' || tmp->str[i] == 'R')
		listflags = push_back_dlist(listflags, tmp->str);
	      else if (tmp->str[i] == 'r' ||
		       tmp->str[i] == 'd' ||
		       tmp->str[i] == 't')
		listflags = push_back_dlist(listflags, tmp->str);
	      i = i + 1;
	    }
	  i = 0;
	}
      tmp = tmp->next;
    }
  return (listflags);
}

char			*list_to_string(t_dlist list)
{
  char			*flags;
  struct s_DlistCell	*tmp;
  int			i;
  int			j;

  j = 0;
  i = 1;
  flags = malloc(sizeof(char) * 10);
  tmp = list->begin;
  while (tmp != NULL)
    {
      while (tmp->str[i] != '\0')
	{
	  if (tmp->str[i] == 'l' || tmp->str[i] == 'R' || tmp->str[i] == 'r')
	    flags[j] = tmp->str[i];
	  if (tmp->str[i] == 'd' || tmp->str[i] == 't')
	    flags[j] = tmp->str[i];
	  i = i + 1;
	  j = j + 1;
	}
      i = 1;
      tmp = tmp->next;
    }
  flags[j] = '\0';
  return (flags);
}

t_dlist			delete_list_flags(t_dlist list)
{
  struct s_DlistCell	*tmp;

  tmp = list->begin;
  while (tmp != NULL)
    {
      if (list->length == 1 && tmp->str[0] == '-' && tmp->str[1] != '\0')
	list = NULL;
      else if (list->length != 1 && tmp->str[0] == '-' && tmp->str[1] != '\0')
	{
	  if (tmp->back == NULL)
	    {
	      list->begin = tmp->next;
	      tmp->next->back = NULL;
	    }
	  else
	    tmp->back->next = tmp->next;
	  if (tmp->next != NULL)
	    tmp->next->back = tmp->back;
	  tmp = list->begin;
	  list->length = list->length - 1;
	}
      tmp = tmp->next;
    }
  return (list);
}

int			count_blocks(char *str)
{
  DIR			*dir;
  struct dirent		*fichierlu;
  struct stat		fileStat;
  int			total;
  char			*goodpath;

  total = 0;
  dir = opendir(str);
  while ((fichierlu = readdir(dir)) != NULL)
    {
      goodpath = path_str(str, fichierlu->d_name);
      stat(goodpath, &fileStat);
      total = total + fileStat.st_blocks;
    }
  total = total / 2;
  return (total);
}

char	*timebuf_changer(char *buffer)
{
  int	i;
  int	j;
  char	*str;

  j = 0;
  i = 4;
  str = malloc(sizeof(char) * 15);
  while (i < 16)
    {
      str[j] = buffer[i];
      i = i + 1;
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}
