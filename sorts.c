/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:25:03 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:25:05 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int		count_nodes(t_ls *temp)
{
	t_ls	*crsr;
	int	j;

	j = 0;
	crsr = temp;
	while (crsr)
	{
		j++;
		crsr = crsr->next;
	}
	return (j);
}


t_ls	*compare(t_ls *head, t_ls *temp, int type)
{
	if (type == 1)
	{
		if (head->stat_buff->st_mtime < temp->stat_buff->st_mtime)
				return (temp);
		else if (head->stat_buff->st_mtime == temp->stat_buff->st_mtime &&\
			head->stat_buff->st_mtimespec.tv_nsec <\
				temp->stat_buff->st_mtimespec.tv_nsec)
				return (temp);
		return (head);
	}
	else if (type == 0)
	{
		if (ft_strcmp(temp->name, head->name) < 1)
			return temp;
		return (head);
	}
	else
		return (NULL);
}

/*sorts list according to type specified by type parameter*/
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
