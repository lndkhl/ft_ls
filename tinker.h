/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:50:10 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:59:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINKER_H
# define TINKER_H
# include "libft/libft.h"
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>

# define L_MAX 128

typedef struct			s_thing
{
	struct s_thing		*next;
	struct s_thing		*prev;
	struct stat			stat_buff;
	char				*name;
	char				*abs_path;
	char				*link_path;
	blkcnt_t			total;
	unsigned int		type;
}						t_ls;

typedef struct			s_body
{
	t_ls				*list;
	struct s_body		*next;
	struct s_body		*prev;
}						t_lust;

typedef struct			s_container
{
	struct s_container	*next;
	struct s_container	*prev;
	char				*name;
}						t_cont;

t_ls					*init_ls_node(const char *n, const char *p, unsigned\
							int t);
t_ls					*init_list(const char *path, int *flags);
t_ls					*init_cwd(int *flags);
t_ls					*add_node(t_ls *node, t_ls *list, int *flags);
char					*p_append(const char *path, const char *name);
int						print_node(t_ls *node, int *flags);
void					print(t_ls *list, int *flags);
void					print_basic(t_ls *node, int *flags);
int						flag_check(char **av, int *flags);
void					parse(char **av, int *f, t_lust *b, t_cont *n);

t_lust					*clean(t_lust *list);
t_ls					*clean_reg(t_ls *list);
t_cont					*clean_cont(t_cont *cont);
int						is_d(char *name);
int						is_file(char *name);
t_cont					*push(t_cont *container, char *item);
int						print_permissions(t_ls *node);
int						print_user(t_ls *node);
int						print_size(t_ls *node);
int						count_nodes(t_ls *temp);
t_ls					*compare(t_ls *head, t_ls *temp, int type);

t_ls					*sort(t_ls *list, int type);
t_lust					*add_dir(t_lust *node, t_lust *list);
int						is_valid(char *av_i, int *flags);
int						print_nonexistant(t_cont *nonexistant);
t_lust					*init_files(t_cont *f, t_lust *b, int *flags);
t_lust					*init_directories(t_cont *d, t_lust *b, int *f);
void					init(int *f, t_cont *fi, t_cont *d, t_lust *b);
void					print_title(t_ls *node, int *flags);
void					print_total(t_ls *node);
int						print_invalid(t_cont *nonexistant);

int						print_illegal(char c);
t_ls					*update_sort(t_ls *sort, t_ls *head);
void					sort_dirs(t_cont *directories);
int						print_date_modded(t_ls *node);
char					*ls_perms(int mode);
int						filetypeletter(int mode);
int						is_dir(t_ls *node);
t_ls					*seek_end(t_ls *list);
t_ls					*clean_one(t_ls *node);
#endif
