#ifndef TINKER_H
#define TINKER_H
#include "libft/libft.h"
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>

#define L_MAX 2048

typedef struct              d_list
{
		struct d_list		*next;
		struct d_list		*prev;
		struct stat			stat_buff[L_MAX];
		char				*name;
		char				*dir_name;
		char				*abs_path;
		char				link_buff[L_MAX];
		blkcnt_t			total;
}                           t_ls;

typedef struct				f_list
{
	t_ls					*list;
	struct f_list			*next;
	struct f_list			*prev;
}							t_lust;				


typedef struct				s_container
{
		struct s_container	*next;
		struct s_container	*prev;
		char				*name;
}							t_cont;

/*initializers (inits.c)*/
t_ls	*init_ls_node(const char *name, const char *dir_name, const char *path);
t_ls	*init_list(const char *path, int *flags);
t_ls	*init_cwd(int *flags);

/*modifiers (tinker.c)*/
t_ls	*add_node(t_ls *node, t_ls *list, int *flags);
char	*p_append(const char *path, const char *name);

/*printers (prints.c)*/
int		print_node(t_ls *node, int *flags);
int		print(t_lust *list, int *flags);
int		print_basic(t_ls *node, int *flags);

/*pre-wash (flags.c)*/
int		flag_check(char **av, int *flags);
t_lust	*parse(char **av, int *flags, t_lust *behemoth);

/*cleanup (cleans.c)*/
void	clean(t_lust *list, int *flags);
t_ls	*clean_reg(t_ls *list);
void	clean_cont(t_cont *cont);

/*helpers (helpers.c)*/
int		is_d(char *name);
int		is_file(char *name);
t_cont	*push(t_cont *container, char *item);

/*long-print (long.c)*/
int		print_permissions(t_ls *node);
int		print_user(t_ls *node);
int		print_size(t_ls *node);

/*sort (sorts.c)*/
int		count_nodes(t_ls *temp);
t_ls	*compare(t_ls *head, t_ls *temp, int type);
t_ls	*sort(t_ls *list, int type);

/*helper functions for flags (flags_helps.c)*/
t_lust	*add_dir(t_lust *node, t_lust *list);
int		is_valid(char *av_i, int *flags);
int		print_nonexistant(t_cont *nonexistant);

/*helper functions for inits (inits_helps.c)*/
t_lust	*init_files(t_cont *files, t_lust *behemoth, int *flags);
t_lust	*init_directories(t_cont *directories, t_lust *behemoth, int *flags);
t_lust	*init(int *flags, t_cont *files, t_cont *directories, t_lust *behemoth);

/*helper functions for prints (prints_helps.c)*/
t_ls	*print_rec(t_ls *list, int type, int *flags);
int		print_titles(t_ls *node);

/*additional helper functions for prints (more_prints.c)*/
int		print_invalid(t_cont *nonexistant);
int		print_illegal(char c);

/*helper functions for sorts (sorts_helps.c)*/
t_ls	*update_sort(t_ls *sort, t_ls *head);
void	sort_dirs(t_cont *directories);

/*helper functions for long-print (long-helps.c)*/
int		print_date_modded(t_ls *node);
char 	*ls_perms(int mode);
int 	filetypeletter(int mode);

/*additional helper functions (tinker_helpers.c)*/
int		is_dir(t_ls *node);
t_ls	*seek_end(t_ls *list);
#endif
