#include "tinker.h"

ls	*clean(ls **list)
{
	ls	*crsr;
	ls	*temp;
	int	i;

	i = 0;
	if (!(list[i]))
	{
		perror("clean");
		return (NULL);
	}
	while ((crsr = list[i++]))
	{
		while(crsr)
		{
			if (crsr->next)
				temp = crsr->next;
			else
				temp = NULL;
			if (crsr->name)
				ft_strdel(&(crsr->name));
			if (crsr->abs_path)
				ft_strdel(&(crsr->abs_path));
			free(crsr);
			crsr = temp;
		}
	}
	return ((crsr = NULL));
}

ls	*clean_one(ls *head)
{
	ls	*crsr;
	ls	*temp;

	if (!head)
	{
		perror("clean one");
		return (NULL);
	}
	crsr = head;
	while (crsr)
	{
		if (crsr->next)
			temp = crsr->next;
		else
			temp = NULL;
		if (crsr->name)
			ft_strdel(&(crsr->name));
		if (crsr->abs_path)
			ft_strdel(&(crsr->abs_path));
		free(crsr);
		crsr = temp;
	}
	return ((crsr = NULL));
}

char	*clean_string(char **string)
{
	char *crsr;
	int		i;

	i = 0;
	if (!(string[i]))
	{
		perror("clean strings");
		return (NULL);
	}
	while ((crsr = string[i++]))
	{
		ft_strdel(&crsr);
		free(crsr);
	}
	return ((crsr = NULL));
}
