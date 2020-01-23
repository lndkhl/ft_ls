#include "tinker.h"

//checks that a given filename or path is in fact a directory
int		is_d(char *name)
{
	struct stat	stat_buff;
	
	if (lstat(name, &stat_buff) == -1)
	{	
		perror("is_d");
		return (-1);
	}
	if ((stat_buff.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
//checks that a given filename is valid
int		is_file(char *name)
{
	struct stat stat_buff;

	if (lstat(name, &stat_buff) == -1)
	{	
		perror("is_file");
		return (-1);
	}
	if ((stat_buff.st_mode & S_IFMT) != (S_IFDIR))
		return (1);
	return (0);
}

//appends a filename to an array
int		push(char **container, char *item)
{
	int	i;

	i = 0;
	if (!item)
	{
		perror("push");
		return (-1);
	}
	while (container[i] != NULL && i < L_MAX)
		i++;
	container[i] = ft_strjoin(ft_strdup("./"), item);
	return (1);
}

//prints that an invalid filename has been entered
int		print_invalid(char *invalid)
{
	ft_putstr("ft_ls: ");
	ft_putstr(invalid);
	ft_putendl(": No such file or directory");
	return (-1);
}

//prints that an illegal option has been chosen, terminates
int		print_illegal(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage ft_ls [l,r,a, R, t] [file ...]");
	return (-1);
}