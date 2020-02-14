/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:10:51 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:54:10 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

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

t_cont		*sort_dirs(t_cont *directories)
{
	t_cont	*temp;
	t_cont	*sort;
	t_cont	*head;
	int		j;

	sort = NULL;
	j = count_dirs(directories);
	while ((directories) && j--)
	{
		head = directories;
		temp = directories->next;
		while (temp)
		{
			head = compare_dirs(head, temp);
			temp = temp->next;
		}
		if (head == directories)
			directories = directories->next;
		else if (head->prev)
			head->prev->next = head->next;
		if (head->next)
			head->next->prev = head->prev;
		sort = update_dirs(sort, head);
	}
	directories = sort;
	return (directories);
}
