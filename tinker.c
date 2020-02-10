/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:36 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:24:38 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//appends node (param1) to linked list (param2)
t_ls    	*add_node(t_ls *node, t_ls *list, int *flags)
{
	t_ls	*crsr;

	if(!(node))
	{
		perror("add_node");
		return(NULL);
	}
	if (!(list))
	{
		list = node;
		if (node->name[0] != '.' || (*flags & 2))
			list->total = node->stat_buff->st_blocks;
		return (list);
	}
	if (node->name[0] != '.' || (*flags & 2))
		list->total += node->stat_buff->st_blocks;
	crsr = seek_end(list);
	crsr->next = node;
	node->prev = crsr;
	return (list);
}

//determines if a given node is a directory
int	is_dir(t_ls *node)
{
	if (!(node))
	{
		perror("is_dir");
		return (-1);
	}
	if (ft_strcmp((node)->name, ".") == 0 || ft_strcmp((node)->name, "..") == 0)
		return (0);
	if (((node)->stat_buff->st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

//returns the last node in a given linked list
t_ls		*seek_end(t_ls *list)
{
	t_ls	*temp;

	if(!(list))
		return (NULL);
	temp = (list);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

//updates the absolute path variable of a node
char		*p_append(const char *path, const char *name)
{
	char	*temp;
	char	*slash;
	char	*appended;

	if (!(path) || !(name))
		return (NULL);
	slash = ft_strdup("/");
	temp = ft_strjoin(path, slash);
	appended = ft_strjoin(temp, name);
	free(temp);
	free(slash);
	return (appended);
}

//sorts list by last modification date and time
t_ls      *sort(t_ls *list, int type)
{
	t_ls  *temp;
	t_ls  *sort;
	t_ls  *head;
	int j;

	sort = NULL;
	j = count_nodes(list);
	while ((list) && j--)
	{
		head = list;
		temp = list->next;
		while (temp)
		{
			head = compare(head, temp, type);
			temp = temp->next;
		}
		if (head == list)
			list = list->next;
		else if (head->prev)
			head->prev->next = head->next;
		if (head->next)
			head->next->prev = head->prev;
		sort = update_sort(sort, head);
	}
	return (sort);
}
