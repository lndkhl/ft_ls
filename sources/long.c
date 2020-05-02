/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:09 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:34:24 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_permissions(t_ls *node)
{
	char	*perms;

	if (!node)
	{
		perror("permissions");
		return (-1);
	}
	perms = ls_perms(node->stat_buff.st_mode);
	if (perms[0] == 'l')
	{
		node->link_path = ft_strnew(L_MAX);
		readlink(node->abs_path, node->link_path, L_MAX);
	}
	ft_putstr(perms);
	free(perms);
	ft_putstr("  ");
	return (print_user(node));
}

int		print_user(t_ls *node)
{
	struct passwd	*pwuid;
	struct group	*gid;

	if (!(pwuid = getpwuid(node->stat_buff.st_uid)))
	{
		perror("print_user error");
		return (-1);
	}
	if (!(gid = getgrgid(node->stat_buff.st_gid)))
	{
		perror("print_group error");
		return (-1);
	}
	if ((node->stat_buff.st_nlink) / 10 == 0)
		ft_putstr("  ");
	else if ((node->stat_buff.st_nlink) / 100 == 0)
		ft_putchar(' ');
	ft_putnbr(node->stat_buff.st_nlink);
	ft_putstr("  ");
	ft_putstr(pwuid->pw_name);
	ft_putstr("  ");
	ft_putstr(gid->gr_name);
	ft_putstr("  ");
	return (print_size(node));
}

int		print_size(t_ls *node)
{
	int	buffer;
	int	size;
	int	padding;

	padding = 0;
	buffer = 10;
	if (!node)
	{
		perror("print_size");
		return (-1);
	}
	size = node->stat_buff.st_size;
	while (size > 0)
	{
		padding++;
		size /= 10;
	}
	padding = buffer - padding;
	while (padding--)
		ft_putchar(' ');
	ft_putnbr(node->stat_buff.st_size);
	ft_putchar(' ');
	return (print_date_modded(node));
}
