#include "tinker.h"

int	clean(ls **list)
{
	ls	*crsr;
	ls	*temp;

	if (!(*list))
	{
		perror("clean");
		return (-1);
	}
	crsr = *list;
	while (crsr->next)
	{
		temp = crsr->next;
		if (crsr->name)
			ft_strdel(&(crsr->name));
		if (crsr->abs_path)
			ft_strdel(&(crsr->abs_path));
		free(crsr);
		crsr = temp;
	}
	if (crsr->name)
		ft_strdel(&(crsr->name));
	free(crsr);
	return (1);
}


