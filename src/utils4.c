/*
** utils4.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Wed Apr 26 22:07:42 2017 Wassim Alkayar
** Last update Sat Apr 29 15:44:57 2017 Wassim Alkayar
*/

#include "my.h"

char			*path_str(char *stra, char *strb)
{
  int			i;
  int			j;
  int			m;
  char			*tmpstr;

  i = 0;
  m = my_strlen(stra) + my_strlen(strb) + 2;
  tmpstr = malloc(sizeof(char) * m);
  while (stra[i] != '\0')
    {
      tmpstr[i] = stra[i];
      i = i + 1;
    }
  tmpstr[i] = '/';
  j = i + 1;
  i = 0;
  while (strb[i] != '\0')
    {
      tmpstr[j] = strb[i];
      i = i + 1;
      j = j + 1;
    }
  tmpstr[j] = '\0';
  return (tmpstr);
}

char	*file_name(char *str)
{
  int	i;
  int	j;
  char	*replace;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	j = i;
      i = i + 1;
    }
  j = j + 1;
  replace = malloc(sizeof(char) * my_strlen(str));
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

int			ls_R_util_bis(struct dirent *fichierlu, DIR *dir, char *path)
{
  int			i;

  fichierlu = NULL;
  i = 1;
  if ((dir = opendir(path)) == NULL)
    errorsystem();
  while ((fichierlu = readdir(dir)) != NULL)
    {
      if (fichierlu->d_name[0] != '.')
	i = i + 1;
    }
  return (i);
}

void		ls_R_util(struct dirent *fichierlu, DIR *dir, char *path)
{
  int		i;

  i = ls_R_util_bis(fichierlu, dir, path);
  if ((dir = opendir(path)) == NULL)
    errorsystem();
  while ((fichierlu = readdir(dir)) != NULL)
    {
      if (fichierlu->d_name[0] != '.')
	{
	  my_putstr(fichierlu->d_name);
	  if (i > 2)
	    {
	      my_putstr(" ");
	      i = i - 1;
	    }
	}
    }
}

t_dlist		ls_R_l_util(struct dirent *fichierlu, DIR *dir, char *path)
{
  t_dlist	list;

  list = NULL;
  if ((dir = opendir(path)) == NULL)
    errorsystem();
  list = push_back_dlist(list, path);
  ls_l_prepare(fichierlu, dir, list);
  return (0);
}
