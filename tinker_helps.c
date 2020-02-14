/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinker_helps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:48:00 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/14 08:21:00 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int			is_dir(t_ls *node)
{
	if (!(node))
	{
		perror("is_dir");
		return (-1);
	}
	if (ft_strcmp((node)->name, ".") == 0 || ft_strcmp((node)->name, "..") == 0)
		return (0);
	if (((node)->stat_buff.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

t_ls		*seek_end(t_ls *list)
{
	t_ls	*temp;

	if (!(list))
		return (list);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int			count_dirs(t_cont *directories)
{
	t_cont	*crsr;
	int		j;

	j = 0;
	crsr = directories;
	while (crsr)
	{
		j++;
		crsr = crsr->next;
	}
	return (j);
}
