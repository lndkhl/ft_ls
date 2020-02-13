/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:55 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:31:58 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_ls	*init_ls_node(const char *name, const char *path)
{
	t_ls		*node;

	if (!(node = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	if (name == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->link_path = NULL;
	node->name = ft_strdup(name);
	node->abs_path = ft_strdup(path);
	if (lstat(node->abs_path, &node->stat_buff) == -1)
	{
		perror("error");
		return (NULL);
	}
	return (node);
}

t_ls	*init_list(const char *path, int *flags)
{
	DIR				*d;
	t_ls			*list;
	struct dirent	*dir_struct;
	char			*appended;

	list = NULL;
	appended = ((path[0] == '/') || (path[0] == '~') == 0) \
	? ft_strdup(path) : p_append(".", path);
	if (!(d = opendir(appended)))
	{
		free(appended);
		perror("error");
		return (NULL);
	}
	free(appended);
	while ((dir_struct = readdir(d)))
	{
		appended = p_append(path, dir_struct->d_name);
		if ((dir_struct->d_name[0] != '.') || (*flags & 2))
			list = add_node((init_ls_node(dir_struct->d_name, appended)),\
				list, flags);
		free(appended);
	}
	if (!list)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	closedir(d);
	free(dir_struct);
	return (list);
}

t_ls	*init_cwd(int *flags)
{
	t_ls	*cwd;

	return (cwd = init_list(".", flags));
}
