/*
** my_alphacmp.c for my_ls in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon Apr 24 14:34:47 2017 Wassim Alkayar
** Last update Sat Apr 29 15:36:15 2017 Wassim Alkayar
*/

#include <stdlib.h>
#include "my.h"

int	my_alphacmp(char *str1, char *str2)
{
  int	ret;
  char	*str1low;
  char	*str2low;

  if (str1 == NULL && str2 == NULL)
    return (84);
  str1low = my_strlowcase(my_strdup(str1));
  str2low = my_strlowcase(my_strdup(str2));
  ret = my_strcmp(str1low, str2low);
  free(str1low);
  free(str2low);
  return (ret);
}
