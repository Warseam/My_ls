/*
** create_dlistargc.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Fri Apr 21 21:06:14 2017 Wassim Alkayar
** Last update Sat Apr 29 15:30:32 2017 Wassim Alkayar
*/

#include "my.h"

t_dlist			create_dlistargc(t_dlist list, int argc, char **argv)
{
  int			i;

  i = 1;
  while (argc > i)
    {
      list = push_back_dlist(list, argv[i]);
      i = i + 1;
    }
  return (list);
}
