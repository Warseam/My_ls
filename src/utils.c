/*
** utils.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Apr 22 16:24:50 2017 Wassim Alkayar
** Last update Sat Apr 29 15:39:29 2017 Wassim Alkayar
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j == 0 && str1[i] != '\0' && str2[i] != '\0')
    {
      j = str1[i] - str2[i];
      i = i + 1;
    }
  return (j);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*tocopy;

  i = 0;
  tocopy = malloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      tocopy[i] = src[i];
      i = i + 1;
    }
  tocopy[i] = '\0';
  return (tocopy);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
