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
