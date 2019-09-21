#ifndef TINKER_H
#define TINKER_H
#include "libft/libft.h"
#include <errno.h>
#include <dirent.h>

#define LMAX 4096

typedef struct                  t_list
{
    struct t_list               *next;
    struct t_list               *prev;

    char                        *name;
}                               ls;

int     init_ls_node(char *name);
int     init_list(char *path);
int     init_cwd();
int     init_tree(char *path);

ls      *seek_end(ls **list);

int     func(int ac, char ***av);

int     print_node(ls **node);
int     print_basic(ls **list);
int     print_rev(ls **list);
int     print_rec(ls **list);
int     print_long(ls **list);

int     clean(ls **list);
int     rem_node(ls **node);

#endif
