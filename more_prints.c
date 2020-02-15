/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_prints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:12:06 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:56:53 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int		print_invalid(t_cont *nonexistant)
{
	ft_putstr("ft_ls: ");
	ft_putstr(nonexistant->name);
	ft_putendl(": No such file or directory");
	return (1);
}

int		print_illegal(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("'\n'usage ft_ls [l,r,a, R, t] [file ...]");
	return (0);
}

int		filetypeletter(int mode)
{
	char	c;

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
	return (c);
}
