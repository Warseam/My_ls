/*
** utils3.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Wed Apr 26 12:00:34 2017 Wassim Alkayar
** Last update Sat Apr 29 15:41:22 2017 Wassim Alkayar
*/

#include "my.h"

int	mode(struct stat fileStat)
{
  my_putstr( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
  my_putstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
  my_putstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
  my_putstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");

  if (S_ISDIR(fileStat.st_mode))
    return (1);
  else
    return (2);
}

void			utils_ls_l(struct stat fileStat)
{
  struct passwd		*pwd;
  struct group		*grp;

  my_putchar(' ');
  my_put_nbr(fileStat.st_nlink);
  my_putchar(' ');
  if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
    {
      my_putstr(pwd->pw_name);
      my_putstr(" ");
    }
  if ((grp = getgrgid(fileStat.st_gid)) != NULL)
    {
      my_putstr(grp->gr_name);
      my_putstr(" ");
    }
}

int	get_length_number(int nb)
{
  int	i;

  i = 1;
  while (nb != 0)
    {
      nb = nb / 10;
      i = i + 1;
    }
  return (i);
}

int			format_ls_l(t_dlist li)
{
  struct stat		fileStat;
  struct s_DlistCell	*tmp;
  int			maxsize;
  int			a;
  int			i;

  maxsize = 0;
  tmp = li->begin;
  while (tmp != NULL)
    {
      if (stat(tmp->str, &fileStat) == -1)
	return (0);
      a = fileStat.st_size;
      i = get_length_number(a);
      if (i > maxsize)
	maxsize = i;
      tmp = tmp->next;
    }
  return (maxsize);
}
