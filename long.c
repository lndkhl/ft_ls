#include "tinker.h"

int		print_permissions(ls *node)
{
	if (!node)
	{
		perror("permissions");
		return (-1);
	}
	ft_putstr(ls_perms(node->stat_buff->st_mode));
	ft_putstr("  ");
	return (print_user(node));
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
char *ls_perms(int mode)
{
    char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
    char *bits;

	bits = ft_strnew(10);
    bits[0] = filetypeletter(mode);
	//ft_putchar(bits[0]);
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

int filetypeletter(int mode)
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