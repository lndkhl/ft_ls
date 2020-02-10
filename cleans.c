/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:48 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:23:50 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

void	clean(t_lust *list)
{
	t_lust	*crsr;

	crsr = list;
	while (crsr)
	{
		clean_one(crsr->list);
		crsr = crsr->next;
	}
}

void	clean_one(t_ls *head)
{
	t_ls	*temp;

	if (!(temp = head))
		return ;
	while (temp)
	{
		ft_strdel(&(temp->name));
		ft_strdel(&(temp->abs_path));
		ft_strdel(&(temp->dir_name));
		temp = temp->next;
	}
}

void	clean_string(t_cont *cont)
{
	t_cont 	*crsr;

	if (!(cont))
		return ;
	while ((crsr = cont))
	{
		ft_strdel(&(crsr->name));
		crsr = crsr->next;
	}
}

int		filetypeletter(int mode)
{
	char    c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return(c);
}
