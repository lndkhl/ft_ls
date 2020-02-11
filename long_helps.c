/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_helps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:34:40 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 09:19:41 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int		print_date_modded(t_ls *node)
{
	char	*shorter;

	shorter = ft_strsub(ctime(&(node->stat_buff->st_mtime)), 4, 12);
	if (!node)
	{
		perror("print date");
		return (-1);
	}
	ft_putstr(shorter);
	free(shorter);
	ft_putchar(' ');
	ft_putendl(node->name);
	if (node->link_buff[0] != '\0')
	{
		ft_putstr(" -> ");
		ft_putendl(node->link_buff);
	}
	return (1);
}

char	*ls_perms(int mode)
{
	char	*rwx[8];
	char	*bits;

	rwx[0] = "---";
	rwx[1] = "--x";
	rwx[2] = "-w-";
	rwx[3] = "-wx";
	rwx[4] = "r--";
	rwx[5] = "r-x";
	rwx[6] = "rw-";
	rwx[7] = "rwx";
	bits = ft_strnew(10);
	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	return (bits);
}
