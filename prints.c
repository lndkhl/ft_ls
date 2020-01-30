#include "tinker.h"

//prints the filename associated with a given node
int	print_node(ls *node)
{
	if (!(node))
		return (-1);
	ft_putendl((node)->name);
	return (1);
}

//long format of the print_node function (prints additional info)
int	print_node_long(ls *node)
{
	if (!(node))
		return (-1);
	print_permissions(node);
	return (1);
}

//prints the list via one of the print_node functions
int	print(ls **behemoth, int *flags)
{
	int	i;
	int	type;

	i = -1;
	while (behemoth[++i] != NULL)
	{
		type = (*flags & 16) ? 1 : 0;
		behemoth[i] = sort(behemoth[i], type);
		if (*flags & 1 && (!(*flags & 8)))
			print_titles(behemoth[i]);
		if (*flags & 8)
			print_rec(behemoth[i], type, flags);
		else if (*flags & 4)
			print_rev(behemoth[i], flags);
		else 
			print_basic(behemoth[i], flags);
	}
	return (0);
}

//prints each node according to the desired formatting
int	print_basic(ls *node, int *flags)
{
	ls	*temp;
	
	temp = NULL;
	if (!(temp = node))
		return (-1);
	while (temp)
	{
		if ((*flags & 2) || (temp)->name[0] != '.')
			(*flags & 1) ? print_node_long(temp) : print_node(temp);
		temp = temp->next;
	}
	return (1);
}

//prints the list in reverse order
int	print_rev(ls *node, int *flags)
{
	ls	*temp;

	temp = NULL;
	if (!(node) || !(temp = seek_end(node)))
		return (-1);
	while (temp)
	{
		if ((*flags & 2) || (temp)->name[0] != '.')
			(*flags & 1) ? print_node_long(temp) : print_node(temp);	
		temp = temp->prev;
	}
	return (1);
}

//prints recursively
ls	*print_rec(ls *list, int type, int *flags)
{
	ls	*temp;
	ls	*crsr;

	temp = list;
	if ((crsr = temp))
	{
				ft_putstr("total ");
				ft_putnbr(crsr->total);
				ft_putchar('\n');
		(*flags & 4) ? print_rev(sort(crsr, type), flags) : print_basic(sort(crsr, type), flags);
		while (crsr)
		{
			if (is_dir(crsr) && ((*flags & 2) || crsr->name[0] != '.'))
			{
				ft_putchar('\n');
				ft_putstr(crsr->abs_path);
				ft_putstr(":\n");
				print_rec(init_list(crsr->abs_path), type, flags);
			}
			crsr = crsr->next;
		}
	}
	clean_one(temp);
	return (temp);
}

int	print_titles(ls *node)
{	
	if (!node)
		return (0);
	if (node->dir_name)
	{
		ft_putstr(node->dir_name);
		ft_putstr(":\n");
	}
	ft_putnbr(node->total);
	ft_putchar('\n');
	return (1);
}
