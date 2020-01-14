#include "tinker.h"

int		print_permissions(ls *node)
{
	if (!node)
		return (-1);
	return (1);
}

int		print_numfiles(ls *node)
{

	if (!node)
		return (-1);
	return (1);
}

int		print_user(ls *node)
{
	struct passwd	*pwuid;
	struct group	*gid;
	pwuid = (struct passwd *)malloc(L_MAX);
	gid = (struct group *)malloc(L_MAX);
	if (!(pwuid = getpwuid(node->stat_buff->st_uid)))
	{
		perror("print_user");
		return (-1);
	}
	if (!(gid = getgrgid(pwuid->pw_gid)))
	{
		perror("print_group");
		return (-1);
	}
	ft_putstr(pwuid->pw_name);
	ft_putchar(' ');
	ft_putstr(gid->gr_name);
	ft_putchar(' ');
	return (print_size(node));
}

int		print_size(ls *node)
{
	if (!node)
	{
		perror("print_size");
		return (-1);
	}
	ft_putnbr(node->stat_buff->st_size);
	ft_putchar(' ');
	return (print_date_modded(node));
}

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
	ft_putchar(' ');
	ft_putendl(node->name);
	return (1);
}