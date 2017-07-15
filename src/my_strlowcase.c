/*
** my_strlowcase.c for my_ls in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon Apr 24 14:37:23 2017 Wassim Alkayar
** Last update Sat Apr 29 15:37:14 2017 Wassim Alkayar
*/

#include <stdlib.h>

char	*my_strlowcase(char *str)
{
  int	i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] += 32;
      ++i;
    }
  return (str);
}
