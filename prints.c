#include "tinker.h"

//prints the filename associated with a given node
int	print_node(ls *node)
{
	if (!(node))
	{
		perror("print node");
		return (-1);
	}
	//ft_putendl("checkpoint 5");
	ft_putendl((node)->name);
	return (1);
}

//long format of the print_node function (prints additional info)
int	print_node_long(ls *node)
{
	if (!(node))
	{
		perror("print node long");
		return (-1);
	}
	ft_putendl((node)->name);
	ft_putendl("long print function functional");
	return (1);
}

//prints the list via one of the print_node functions
int	print(ls **behemoth, int *flags)
{
	int	i;

	if (behemoth[0] == NULL)
	{
		perror("main print");
		return (-1);
	}
	i = -1;
	while (behemoth[++i] != NULL)
	{
		if (*flags & 8)
			print_rec(behemoth[i], flags);
		if (*flags & 4)
		{		
			if (!(print_rev(behemoth[i], flags)))
				return (0);
		} 
		else if (!(print_basic(behemoth[i], flags)))
			return (0);
	}
	return (1);
}

//prints each node according to the desired formatting
int	print_basic(ls *node, int *flags)
{
	ls	*temp;

	temp = NULL;
	if (!(temp = node))
	{
		perror("print basic");
		return (-1);
	}
	while (temp)
	{
		if (!(*flags & 2))
			while (temp->next && (temp)->name[0] == '.')
					temp = temp->next;
		if (temp && *flags & 1)
			print_node_long(temp);
		else if (temp)
			print_node(temp);
		temp = temp->next;
	}
	clean (&node);
	return (1);
}

//prints the list in reverse order
int	print_rev(ls *node, int *flags)
{
	ls	*temp;

	temp = NULL;
	if (!(node) || !(temp = seek_end(node)))
	{
		perror("print rev");
		return (-1);
	}
	while (temp)
	{
		if (!(*flags & 2))
			while (temp->prev && (temp)->name[0] == '.')
				temp = temp->prev;
		if (temp && *flags & 1)
			print_node_long(temp);	
		 else if (temp)
			print_node(temp);
		temp = temp->prev;
	}
	clean (&node);
	return (1);
}

//prints the list recursively
int	print_rec(ls *list, int *flags)
{
	ls	*temp;
	ls	*crsr;

	if (!(list))
	{
		perror("print rec");
		return (-1);
	}
	temp = list;
	crsr = temp->next;
	if (*flags & 4)
	{		
		if (!(print_rev(temp, flags)))
			return (0);
	} 
	else if (!(print_basic(temp, flags)))
		return (0);
	while (crsr)
	{
		if (!(*flags & 2))
			while (crsr->next && (crsr)->name[0] == '.')
			{
				ft_putendl("life");
				crsr = crsr->next;
			}
		if (is_dir(crsr))
		{
			temp = init_list(crsr->abs_path);
			print_rec(temp, flags);

		}
		crsr = crsr->next;
	}
	//clean(behemoth);
	return (1);
}
