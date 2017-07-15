/*
** test2.c for  in /home/WASSEX/Semestre1/PSU_2016_my_ls
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Tue Apr 25 16:48:39 2017 Wassim Alkayar
** Last update Sun Jul 16 01:36:52 2017 Wassim Alkayar
*/

#include "my.h"

void		aff_ls_R(char *tmp, char *parentfile)
{
  my_putstr("\n\n");
  my_putstr(path_str(parentfile, tmp));
  my_putstr(":\n");
}

void			ls_R(char *path)
{
  DIR			*dir;
  struct dirent		*fichierlu;
  char			*parentfile;
  char			*tmp;

  fichierlu = NULL;
  if ((dir = opendir(path)) == NULL)
    errorsystem();
  ls_R_util(fichierlu, dir, path);
  parentfile = my_strdup(path);
  if ((dir = opendir(path)) == NULL)
    errorsystem();
  while ((fichierlu = readdir(dir)) != NULL)
    {
      if (opendir(path_str(parentfile, fichierlu->d_name)) != NULL &&
	  my_strcmp(fichierlu->d_name, ".") != 0 &&
	  my_strcmp(fichierlu->d_name, "..") != 0 &&
	  fichierlu->d_name[0] != '.')
	{
	  tmp = my_strdup(fichierlu->d_name);
	  aff_ls_R(tmp, parentfile);
	  ls_R(path_str(parentfile, tmp));
	}
    }
}

void			ls_R_prepare(t_dlist list)
{
  struct s_DlistCell	*tmp;

  tmp = list->begin;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putstr(":\n");
      ls_R(tmp->str);
      if (tmp->next != NULL)
	my_putchar('\n');
      tmp = tmp->next;
    }
  my_putchar('\n');
}
