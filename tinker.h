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

ls	*init_ls_node(const char *name, const char *path);
ls	*init_list(const char *path);
ls	*init_cwd();

int	add_node(ls *node, ls **list);
int	is_dir(ls **node);
ls	*seek_end(ls **list);
char	*path_append(const char *path, const char *name);

int	print_node(ls **node);
int	print_node_long(ls **list);
int	print(ls **list);
int	print_rev(ls **listi);
int	print_rec(ls **list);

int	print_long(ls **liist);
int	print_long_rec(ls **list);

ls	*sort(ls **list);

int	clean(ls **list);

#endif
