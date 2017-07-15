/*
** my.h for  in /home/WASSEX/Semestre1/PSU_2016_my_ls/include
** 
** Made by Wassim Alkayar
** Login   <WASSEX@epitech.net>
** 
** Started on  Mon Apr 17 14:25:32 2017 Wassim Alkayar
** Last update Sun Jul 16 01:34:59 2017 Wassim Alkayar
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>

typedef enum
{
    false,
    true
}	bool;

struct			s_DlistCell
{
  char			*str;
  char			*strtime;
  struct s_DlistCell	*next;
  struct s_DlistCell	*back;
};

typedef struct		s_dlist
{
  int			length;
  struct s_DlistCell	*begin;
  struct s_DlistCell	*end;
}			*t_dlist;

char	*my_strlowcase(char*);
int	my_alphacmp(char*, char*);

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_printf(char *str, ...);
int	my_put_nbr(int nb);

void	ls(struct dirent *fichierlu, DIR *dir, t_dlist list);
void	case_arg_mult(struct dirent *fichierlu, DIR *dir, t_dlist list);

t_dlist prepare_sorted_list(struct dirent *fichierlu, DIR *dir, char *toopen);
t_dlist	my_sort_list(t_dlist list);

void	ls_l(t_dlist list);
void	ls_l_prepare(struct dirent *fichierlu, DIR *dir, t_dlist list);

void	ls_R(char *path);
void	ls_R_prepare(t_dlist list);

void	aff_ls_R_l(char *tmp, char *parentfile);
void	ls_R_l(char *path);
void	ls_R_l_prepare(t_dlist list);
t_dlist	ls_R_l_util(struct dirent *fichierlu, DIR *dir, char *path);

void	ls_t(t_dlist li);
void	lspt_for_t(struct s_DlistCell *tmp, struct dirent *f, DIR *dir);
void	ls_t_prepare(struct dirent *fichierlu, DIR *dir, t_dlist list);
t_dlist	sort_by_year(t_dlist timelist);

int	check_flag_func(char *, char);
void	print_directories(t_dlist, char *);

t_dlist	create_dlistargc(t_dlist list, int argc, char **argv);
void	errorsystem();
int	mode(struct stat fileStat);
int	checkflag(int argc, char **argv);
int	check_opotions(struct dirent *fichierlu, DIR *dir, t_dlist list);

t_dlist	push_back_dlist(t_dlist li, char *str);
t_dlist	push_front_dlist(t_dlist li, char *str);
void	print_dlist(t_dlist li);
void	print_dlist_files(t_dlist li);
t_dlist	new_Dlist(void);
bool	is_empty_dlist(t_dlist li);

char	*my_strdup(char *src);
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);

t_dlist	copy_flags(t_dlist list, t_dlist listflags);
char	*list_to_string(t_dlist list);
t_dlist	delete_list_flags(t_dlist list);
int	count_blocks(char *str);
char	*timebuf_changer(char *buffer);
void	utils_ls_l(struct stat fileStat);
int	format_ls_l(t_dlist li);
int	get_length_number(int nb);
char	*path_str(char *, char *);
char	*file_name(char *str);
void	ls_R_util(struct dirent *fichierlu, DIR *dir, char *path);
int	ls_R_util_bis(struct dirent *fichierlu, DIR *dir, char *path);

t_dlist	order_time(t_dlist list);
char	*modif_time_str(char *str);
int	my_strncmp(char *str1, char *str2, int begin, int end);
t_dlist	sort_by_month(t_dlist timelist);
t_dlist	sort_by_year(t_dlist timelist);
char	*file_name_tracer(char *str);
t_dlist	epur_name(t_dlist li);
void	print_reverse_dlist(t_dlist li);
char	*month_gestion(char *str, int i, int j, char *nb);
char	*month_number(char *nb, char a, char b, char c);

#endif /* MY_H_ */
