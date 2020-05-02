/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:25:03 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:03:36 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		count_nodes(t_ls *temp)
{
	t_ls	*crsr;
	int		j;

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
		if (head->stat_buff.st_mtime < temp->stat_buff.st_mtime)
			return (temp);
		else if (head->stat_buff.st_mtime == temp->stat_buff.st_mtime &&\
			head->stat_buff.st_mtim.tv_nsec <\
				temp->stat_buff.st_mtim.tv_nsec)
			return (temp);
		return (head);
	}
	else if (type == 0)
	{
		if (ft_strcmp(temp->name, head->name) < 1)
			return (temp);
		return (head);
	}
	else
		return (NULL);
}
