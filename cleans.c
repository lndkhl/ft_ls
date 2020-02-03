#include "tinker.h"

void	clean(ls **list)
{
	ls	*crsr;
	int	i;

	i = -1;
	while ((crsr = list[++i]))
		clean_one(crsr);
	return ;
}

void	clean_one(ls *head)
{
	ls	*temp;

	if (!(temp = head))
		return ;
	while (temp)
	{
		ft_strdel(&(temp->name));
		ft_strdel(&(temp->abs_path));
		ft_strdel(&(temp->dir_name));
		temp = temp->next;
	}
	return ;
}

void	clean_string(char **string)
{
	char *crsr;
	int		i;

	i = 0;
	if (!(string[i]))
		return ;
	while ((crsr = string[i++]))
		ft_strdel(&crsr);
	return ;
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
