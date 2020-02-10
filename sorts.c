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

t_ls	*update_sort(t_ls *sort, t_ls *head)
{
	t_ls	*temp;

	temp = NULL;
		if (!(temp = seek_end(sort)))
		{
			sort = head;
			head->next = NULL;
			head->prev = NULL;
		}
		else
		{
			temp->next = head;
			head->next = NULL;
			head->prev = temp;
		}
	return (sort);
}

void	sort_dirs(t_cont *directories)
{
	t_cont	*temp;
	t_cont	*crsr;
	t_cont	*swap;

	while ((temp = directories))
	{
		crsr = directories->next;
		while (crsr)
			if (ft_strcmp(temp->name, crsr->name) > 0)
			{
				swap = temp;
				crsr = crsr->next;
			}
		temp = temp->next;
	}
}
