#include "tinker.h"

int	print_node(ls **node)
{
	if (!(*node))
	{
		perror("print node");
		return (-1);
	}
	ft_putendl((*node)->name);
	return (1);
}

int	print_node_long(ls **node)
{
	if (!(*node))
	{
		perror("print node long");
		return (-1);
	}
	ft_putendl("function pointer working");
	return (1);
}

int	print(ls **list)
{
	ls	*temp;
	int	(*print_ptr[2])(ls **node);

	print_ptr[0] = &print_node;
	print_ptr[1] = &print_node_long;
	if (!(*list))
	{
		perror("print basic");
		return (-1);
	}
	temp = *list;
	while (temp)
	{
		if (!(print_ptr[0](&temp)))
			return (0);
		temp = temp->next;
	}
	//clean (list);
	return (1);
}

int	print_rev(ls **list)
{
	ls	*temp;

	temp = NULL;
	if (!(*list) || !(temp = seek_end(list)))
	{
		perror("print rev");
		return (-1);
	}
	while (temp)
	{
		if (!(print_node(&temp)))
			return (0);
		temp = temp->prev;
	}
	//clean (list);
	return (1);
}

int	print_rec(ls **list)
{
	ls	*temp;
	ls	*crsr;

	if (!(*list))
	{
		perror("print rec");
		return (-1);
	}
	temp = *list;
	crsr = (*list)->next;
	print(&temp);
	while (crsr)
	{
		if (is_dir(&crsr))
		{
			temp = init_list(crsr->abs_path);
			print_rec(&temp);
		}
		crsr = crsr->next;
	}
	clean(list);
	return (1);
}
