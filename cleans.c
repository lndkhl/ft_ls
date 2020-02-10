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

void	clean(t_lust *list, int *flags)
{
	t_lust	*crsr;
	t_lust	*temp;

	if (!(crsr = list))
		return ;
	while (crsr)
	{
		if (crsr->next)
			temp = crsr->next;
		else
			temp = NULL;
		if (*flags & 8)
			return ;
		else
			crsr->list = clean_reg(crsr->list); 
		free(crsr->list);
		free(crsr);
		crsr = temp;
	}
}

t_ls	*clean_reg(t_ls *list)
{
	t_ls	*temp;
	t_ls	*crsr;

	temp = list;
	while (temp)
	{
		crsr = (temp->next) ? temp->next : NULL;
		free(temp->name);
		free(temp->dir_name);
		free(temp->abs_path);
		free(temp);
		temp = crsr;
	}
	return (temp);
}
/*
t_ls	*clean_rec(t_ls *list)
{
	t_ls	*temp;
	t_ls	*crsr;

	temp = list;
	while (temp)
	{
		crsr = (temp->next) ? temp->next : NULL;
		if (ft_strcmp(temp->name, ".") && ft_strcmp(temp->name, "..")\
			&& (temp->stat_buff->st_mode & S_IFMT) == S_IFDIR)
			temp = clean_rec(temp);
		if (temp)
		{
			free(temp->name);
			free(temp->dir_name);
			free(temp->abs_path);
			free(temp);
		}
		temp = crsr;
	}
	return (temp);
}
*/
void	clean_cont(t_cont *cont)
{
	t_cont 	*crsr;
	t_cont	*temp;

	if (!(crsr = cont))
		return ;
	while (crsr)
	{
		if (crsr->next)
			temp = crsr->next;
		else
			temp = NULL;
		free(crsr->name);
		free(crsr);
		crsr = temp;
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
