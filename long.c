#include "tinker.h"

int		print_permissions(ls *node)
{
	if (!node)
	{
		perror("permissions");
		return (-1);
	}
	ft_putstr(ls_perms(node->stat_buff->st_mode));
	ft_putchar(' ');
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
	ft_putnbr(node->stat_buff->st_nlink);
	ft_putchar(' ');
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
char *ls_perms(int mode)
{
    char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
    char *bits;

	bits = ft_strnew(11);
    bits[0] = filetypeletter(mode);
	ft_putchar(bits[0]);
    strcpy(&bits[1], rwx[(mode >> 6)& 7]);
    strcpy(&bits[4], rwx[(mode >> 3)& 7]);
    strcpy(&bits[7], rwx[(mode & 7)]);
    if (mode & S_ISUID)
        bits[3] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        bits[6] = (mode & S_IXGRP) ? 's' : 'l';
    if (mode & S_ISVTX)
        bits[9] = (mode & S_IXOTH) ? 't' : 'T';
    bits[10] = '\0';
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
#ifdef S_ISFIFO
    else if (S_ISFIFO(mode))
        c = 'p';
#endif  /* S_ISFIFO */
#ifdef S_ISLNK
    else if (S_ISLNK(mode))
        c = 'l';
#endif  /* S_ISLNK */
#ifdef S_ISSOCK
    else if (S_ISSOCK(mode))
        c = 's';
#endif  /* S_ISSOCK */
#ifdef S_ISDOOR
    /* Solaris 2.6, etc. */
    else if (S_ISDOOR(mode))
        c = 'D';
#endif  /* S_ISDOOR */
    else
    {
        /* Unknown type -- possibly a regular file? */
        c = '?';
    }
    return(c);
}