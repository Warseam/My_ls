/*
** utils6.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Apr 29 12:12:09 2017 Wassim Alkayar
** Last update Sat Apr 29 15:47:47 2017 Wassim Alkayar
*/

#include "my.h"

char		*file_name_tracer(char *str)
{
  int		j;
  int		i;
  char		*replace;

  i = 0;
  j = 0;
  if (str == NULL)
    return (0);
  replace = malloc(sizeof(char) * my_strlen(str));
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	j = i + 1;
      i = i + 1;
    }
  i = 0;
  while (str[j] != '\0')
    {
      replace[i] = str[j];
      i = i + 1;
      j = j + 1;
    }
  replace[i] = '\0';
  return (replace);
}

t_dlist			epur_name(t_dlist li)
{
  struct s_DlistCell	*tmp;

  tmp = li->begin;
  while (tmp != NULL)
    {
      tmp->str = my_strdup(file_name_tracer(tmp->str));
      tmp = tmp->next;
    }
  return (li);
}

void			print_reverse_dlist(t_dlist li)
{
  struct s_DlistCell	*tmp;

  tmp = li->end;
  while (tmp->back != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->back;
    }
}
