/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:55 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/14 09:09:04 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_ls	*init_ls_node(const char *name, const char *path, unsigned int type)
{
	t_ls		*node;

	if (!(node = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	if (name == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->link_path = NULL;
	node->type = type;
	node->name = ft_strdup(name);
	node->abs_path = ft_strdup(path);
	if (lstat(node->abs_path, &node->stat_buff) == -1)
	{
		perror("error");
		return (NULL);
	}
	return (node);
}

t_ls	*init_list(const char *p, int *fl)
{
	DIR				*d;
	t_ls			*li;
	struct dirent	*dir_struct;
	char			*ap;

	li = NULL;
	ap = (p[0] == '/' || p[0] == '~' == 0) ? ft_strdup(p) : p_append(".", p);
	if (!(d = opendir(ap)))
	{
		free(ap);
		perror(p);
		return (NULL);
	}
	free(ap);
	while ((dir_struct = readdir(d)))
	{
		ap = p_append(p, dir_struct->d_name);
		if ((dir_struct->d_name[0] != '.') || (*fl & 2))
			li = add_node((init_ls_node(dir_struct->d_name, ap, 1)), li, fl);
		free(ap);
	}
	if (!li)
		empty_dir(p);
	closedir(d);
	return (li);
}

void	empty_dir(const char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}

t_ls	*init_cwd(int *flags)
{
	t_ls	*cwd;

	return (cwd = init_list(".", flags));
}
