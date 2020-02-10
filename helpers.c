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

//checks that a given filename or path is in fact a directory
int		is_d(char *name)
{
	struct stat	stat_buff;
	
	if (lstat(name, &stat_buff) == -1)
		return (0);
	if ((stat_buff.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
//checks that a given filename is valid
int		is_file(char *name)
{
	struct stat stat_buff;

	if (lstat(name, &stat_buff) == -1)
		return (0);
	if ((stat_buff.st_mode & S_IFMT) != (S_IFDIR))
		return (1);
	return (0);
}

//appends a filename to an array
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

//prints that an invalid filename has been entered
int		print_invalid(t_cont *nonexistant)
{
	t_cont	*temp;

	if (!(nonexistant))
		return (0);
	temp = nonexistant;
	while (temp)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(nonexistant->name);
		ft_putendl(": No such file or directory");
		temp = temp->next;
	}
	return (1);
}

//prints that an illegal option has been chosen, terminates
int		print_illegal(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("'\n'usage ft_ls [l,r,a, R, t] [file ...]");
	return (0);
}
