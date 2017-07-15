/*
** my_put_nbr.c for my_put_nbr in /home/Wasx/CPool_Day03
** 
** Made by Wassim ALKAYAR
** Login   <Wasx@epitech.net>
** 
** Started on  Wed Mar  1 17:58:17 2017 Wassim ALKAYAR
** Last update Sat Apr 29 15:36:44 2017 Wassim Alkayar
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	diviseur;

  diviseur = 1000000000;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb > 0)
    {
      while ((nb / diviseur) == 0)
	{
	  diviseur = diviseur / 10;
	}
      while (diviseur != 0)
	{
	  my_putchar(48 + (nb / diviseur) % 10);
	  diviseur = diviseur / 10;
	}
    }
  else
    {
      my_putchar(48);
    }
  return (0);
}
