/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:54:35 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:02:28 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_ls	*sort(t_ls *list, int type)
{
	t_ls	*temp;
	t_ls	*sort;
	t_ls	*head;
	int		j;

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
	list = sort;
	return (list);
}

t_cont	*compare_dirs(t_cont *head, t_cont *temp)
{
	if (ft_strcmp(temp->name, head->name) < 1)
		return (temp);
	return (head);
}

t_cont	*seek_last(t_cont *list)
{
	t_cont	*temp;

	if (!(list))
		return (list);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
