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
		perror("error");
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
	{
		perror("error");
		return (NULL);
	}
	free(appended);
	while ((dir_struct = readdir(d)))
	{
		appended = p_append(path, dir_struct->d_name);
		list = add_node((init_ls_node(dir_struct->d_name, path, appended)),\
			list, flags);
		free(appended);
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
