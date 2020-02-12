/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:36 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:47:40 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_ls		*add_node(t_ls *node, t_ls *list, int *flags)
{
	t_ls	*crsr;

	if (!(node))
		return (list);
	if (!(list))
	{
		list = node;
		if ((*flags & 1) && (node->name[0] != '.' || (*flags & 2)))
			list->total = node->stat_buff.st_blocks;
		return (list);
	}
	if ((*flags & 1) && (node->name[0] != '.' || (*flags & 2)))
		list->total += node->stat_buff.st_blocks;
	crsr = seek_end(list);
	crsr->next = node;
	node->prev = crsr;
	return (list);
}

char		*p_append(const char *path, const char *name)
{
	char	*temp;
	char	*appended;
	int		i;

	i = 0;
	if (!(path) || !(name))
		return (NULL);
	while (path[i] != '\0')
		i++;
	if (path[--i] != '/')
		temp = ft_strjoin(path, "/");
	else
		temp = ft_strdup(path);
	appended = ft_strjoin(temp, name);
	free(temp);
	return (appended);
}
