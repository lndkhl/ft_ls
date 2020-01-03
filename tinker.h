#ifndef TINKER_H
#define TINKER_H
#include "libft/libft.h"
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define L_MAX 1024000

typedef struct                  t_list
{
 	struct t_list		*next;
    	struct t_list		*prev;

	struct stat		stat_buff[L_MAX];

    	char			*name;
	char			*abs_path;
}                               ls;

//initializers (inits.c)
ls	*init_ls_node(const char *name, const char *path);
ls	*init_list(const char *path);
ls	*init_cwd();
int	init_files(char **files, ls **behemoth);

//modifiers (tinker.c)
int	add_node(ls *node, ls **list);
int	is_dir(ls *node);
ls	*seek_end(ls *list);
char	*path_append(const char *path, const char *name);

//printers (prints.c)
int	print_node(ls *node);
int	print_node_long(ls *list);
int	print(ls **list, int *flags);
int	print_rev(ls *node, int *flags);
int	print_rec(ls *list, int *flags);
int	print_basic(ls *node, int *flags);

//pre-wash (flags.c)
int	flag_check(char **av, int *flags);
int	parse(char **av, int *flags, char **directories, char **files);
int	is_valid(char *av_i, int *flags);
int	init_directories(char **directories, ls **behemoth);

//cleanup (cleans.c)
int	clean(ls **list);

//helpers (helpers.c)
int	is_d(char *name);
int	is_file(char *name);
int	push(char **container, char *item);
int	print_invalid(char *invalid);
int	print_illegal(char c);
#endif
