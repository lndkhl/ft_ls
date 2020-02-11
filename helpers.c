/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:00 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:24:03 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

/*checks that a given filename or path is in fact a directory*/
int		is_d(char *name)
{
	struct stat	stat_buff;
	
	if (lstat(name, &stat_buff) == -1)
		return (0);
	if ((stat_buff.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
/*checks that a given filename is valid*/
int		is_file(char *name)
{
	struct stat stat_buff;

	if (lstat(name, &stat_buff) == -1)
		return (0);
	if ((stat_buff.st_mode & S_IFMT) != (S_IFDIR))
		return (1);
	return (0);
}

/*appends a list element to a container*/
t_cont	*push(t_cont *container, char *item)
{
	t_cont	*temp;
	t_cont	*crsr;

	if (!item)
		return (NULL);
	temp = (t_cont *)malloc(sizeof(t_cont));
	temp->name = ft_strdup(item);
	temp->next = NULL;
	if (!(container))
	{
		temp->prev = NULL;
		container = temp;
		return (container);
	}
	crsr = container;
	while (crsr->next)
		crsr = crsr->next;
	crsr->next = temp;
	temp->prev = crsr;
	return (container);
}
