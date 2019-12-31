#include "tinker.h"

//prints the filename associated with a given node
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

//long format of the print_node function (prints additional info)
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

//prints the list via one of the print_node functions
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

//prints the list in reverse order
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

//prints the list recursively
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
