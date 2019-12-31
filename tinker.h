#ifndef TINKER_H
#define TINKER_H
#include "libft/libft.h"
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define L_MAX 4096

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

//modifiers (tinker.c)
int	add_node(ls *node, ls **list);
int	is_dir(ls **node);
ls	*seek_end(ls **list);
char	*path_append(const char *path, const char *name);

//printers (prints.c)
int	print_node(ls **node);
int	print_node_long(ls **list);
int	print(ls **list);
int	print_rev(ls **list);
int	print_rec(ls **list);

//pre-wash (flags.c)
int	flag_check(char **av, int ac, int *flags);
int	parse(char **av, int ac);
ls	*sort(ls **list);
int	is_valid(char *av_i, int *flags);

//cleanup (cleans.c)
int	clean(ls **list);

#endif
