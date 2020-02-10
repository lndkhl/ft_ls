/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:55 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/10 08:17:16 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//initializes a node
t_ls	*init_ls_node(const char *name, const char *dir_name, const char *path)
{
	t_ls		*node;

	if (!(node = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);;
	if (name == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->name = ft_strdup(name);
	node->abs_path = ft_strdup(path);
	if (dir_name)
		node->dir_name = ft_strdup(dir_name);
	else
		node->dir_name = NULL;
	ft_memset(node->link_buff, '\0', L_MAX);
	if (lstat(node->abs_path, node->stat_buff) == -1)
	{
		perror("lstat at init");
		return(NULL);
	}
	return (node);
}

//initializes a list of the files in a given directory
t_ls	*init_list(const char *path, int *flags)
{
	DIR     		*d;
	t_ls			*list;
	struct dirent	*dir_struct;
	char			*appended;
	
	list = NULL;
	appended = ((path[0] == '/') || (path[0] == '~') == 0) \
	? ft_strdup(path) : p_append(".", path);
	if (!(d = opendir(appended)))
		return (NULL);
	ft_strdel(&appended);
	while ((dir_struct = readdir(d)))
	{
		appended = p_append(path, dir_struct->d_name);
		list = add_node((init_ls_node(dir_struct->d_name, path, appended)),\
			list, flags);
		ft_strdel(&appended);
	}
	closedir(d);
	return (list);
}

//initializes the directory from which the function is called
t_ls	*init_cwd(int *flags)
{
	t_ls	*cwd;

	return (cwd = init_list(".", flags));
}

//initializes the nodes corresponding to requested filename
t_lust	*init_files(t_cont *files, t_lust *behemoth, int *flags)
{
	char	*dir_name;
	t_cont	*crsr;
	t_ls	*list;

	dir_name = NULL;
	if (!(files))
		return (NULL);
	crsr = files;
	behemoth = (t_lust *)malloc(sizeof(t_lust));
	list = init_ls_node(crsr->name, dir_name, crsr->name);;
	while (crsr->next)
	{
		crsr = crsr->next;
		list = add_node(init_ls_node(crsr->name, dir_name, crsr->name)\
			, list, flags);
	}
	behemoth->list = list;
	behemoth->prev = NULL;
	behemoth->next = NULL;
	return (behemoth);
}
//creates linked lists of the provided directories' contents
t_lust *init_directories(t_cont *directories, t_lust *behemoth, int *flags)
{
	t_cont	*crsr;
	t_ls	*list;
	t_lust	*temp;

	if (!(directories))
		return (behemoth);
	crsr = directories;
	while (crsr)
	{
		temp = (t_lust *)malloc(sizeof(t_lust));
		temp->next = NULL;
		temp->prev = NULL;
		list = init_list(crsr->name, flags);
		temp->list = list;
		behemoth = add_dir(temp, behemoth);
		temp = NULL;
		crsr = crsr->next;
	}
	return (behemoth);
}
