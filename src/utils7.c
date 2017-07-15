/*
** utils7.c for  in /home/WASSEX/jungle/ls-save/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Sat Apr 29 14:09:50 2017 Wassim Alkayar
** Last update Sat Apr 29 15:48:43 2017 Wassim Alkayar
*/

#include "my.h"

int	my_strncmp(char *str1, char *str2, int begin, int end)
{
  int	j;

  j = 0;
  while (j == 0 && begin <= end)
    {
      j = str1[begin] - str2[begin];
      begin = begin + 1;
    }
  return (j);
}

char	*month_number(char *nb, char a, char b, char c)
{
  if (a == 'J' && b == 'a' && c == 'n')
    nb = "1";
  if (a == 'F' && b == 'e' && c == 'b')
    nb = "2";
  if (a == 'M' && b == 'a' && c == 'r')
    nb = "3";
  if (a == 'A' && b == 'p' && c == 'r')
    nb = "4";
  if (a == 'M' && b == 'a' && c == 'y')
    nb = "5";
  if (a == 'J' && b == 'u' && c == 'n')
    nb = "6";
  if (a == 'J' && b == 'u' && c == 'l')
    nb = "7";
  if (a == 'A' && b == 'u' && c == 'g')
    nb = "8";
  if (a == 'S' && b == 'e' && c == 'p')
    nb = "9";
  if (a == 'O' && b == 'c' && c == 't')
    nb = "10";
  if (a == 'N' && b == 'o' && c == 'v')
    nb = "11";
  if (a == 'D' && b == 'e' && c == 'c')
    nb = "12";
  return (nb);
}
