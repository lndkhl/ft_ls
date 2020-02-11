#include "tinker.h"

//prints last modification date
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
