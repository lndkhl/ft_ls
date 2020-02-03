/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:09 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:24:12 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//prints file permissions
int		print_permissions(ls *node)
{
	char	*perms;

	if (!node)
	{
		perror("permissions");
		return (-1);
	}
	perms = ls_perms(node->stat_buff->st_mode);
	if (perms[0] == 'l')
		readlink(node->abs_path, node->link_buff, L_MIN);
	ft_putstr(perms);
	free(perms);
	ft_putstr("  ");
	return (print_user(node));
}

//prints user
int		print_user(ls *node)
{
	struct passwd	*pwuid;
	struct group	*gid;
	if (!(pwuid = getpwuid(node->stat_buff->st_uid)))
	{
		perror("print_user");
		return (-1);
	}
	if (!(gid = getgrgid(node->stat_buff->st_gid)))
	{
		perror("print_group");
		return (-1);
	}
	if ((node->stat_buff->st_nlink)/ 10 == 0)
		ft_putchar(' ');
	ft_putnbr(node->stat_buff->st_nlink);
	ft_putstr("  ");
	ft_putstr(pwuid->pw_name);
	ft_putstr("  ");
	ft_putstr(gid->gr_name);
	ft_putstr("  ");
	return (print_size(node));
}

//prints file size
int		print_size(ls *node)
{
	int	buffer;
	int	size;
	int	padding;

	padding = 0;
	buffer = 9;
	if (!node)
	{
		perror("print_size");
		return (-1);
	}
	size = node->stat_buff->st_size;
	while (size > 0)
	{
		padding++;
		size /= 10;
	}
	padding = buffer - padding;
	while (padding--)
		ft_putchar(' ');
	ft_putnbr(node->stat_buff->st_size);
	ft_putchar(' ');
	return (print_date_modded(node));
}

//prints last modification date
int		print_date_modded(ls *node)
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

//determines file permissions
char *ls_perms(int mode)
{
    char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
    char *bits;

	bits = ft_strnew(10);
    bits[0] = filetypeletter(mode);
    ft_strcpy(&bits[1], rwx[(mode >> 6)& 7]);
    ft_strcpy(&bits[4], rwx[(mode >> 3)& 7]);
    ft_strcpy(&bits[7], rwx[(mode & 7)]);
    if (mode & S_ISUID)
        bits[3] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        bits[6] = (mode & S_IXGRP) ? 's' : 'l';
    if (mode & S_ISVTX)
        bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	return(bits);
}
