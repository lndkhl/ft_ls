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
	print_permissions(node);
	return (1);
}

//prints the list via one of the print_node functions
int	print(ls **behemoth, int *flags)
{
	int	i;

	if (behemoth[0] == NULL)
		behemoth[0] = init_cwd();
	i = -1;
	while (behemoth[++i] != NULL)
	{
		if (*flags & 8)
			(*flags & 16) ? print_rec(sort(behemoth[i]), flags) : print_rec(behemoth[i], flags);
		else if (*flags & 4)
			(*flags & 16) ? print_rev(sort(behemoth[i]), flags) : print_rev(behemoth[i], flags);
		else 
			(*flags & 16) ? print_basic(sort(behemoth[i]), flags) : print_basic(behemoth[i], flags);
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
			while (temp && (temp)->name[0] == '.')
					temp = temp->next;
		if (!temp)
			return (1);
		if (temp && *flags & 1)
			print_node_long(temp);
		else if (temp)
			print_node(temp);
		temp = temp->next;
	}
	//clean (node);
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
		if (!temp)
			return (1);
		if (temp && *flags & 1)
			print_node_long(temp);	
		 else if (temp)
			print_node(temp);
		temp = temp->prev;
	}
	//clean (&node);
	return (1);
}

//prints the list recursively
int	print_rec(ls *list, int *flags)
{
	ls	*temp;
	ls	*crsr;

	if (!(list))
		return (-1);
	temp = list;
	if (temp)
	{
		crsr = temp;
		if (*flags & 4)
		{		
			if (!(print_rev(crsr, flags)))
				return (0);
		} 
		else 
			print_basic(crsr, flags);
		temp = NULL;
		while (crsr)
		{
			if (!(*flags & 2))
				while ((crsr) && (crsr)->name[0] == '.')
					crsr = crsr->next;
			if ((crsr) && is_dir(crsr))
			{
				temp = init_list(crsr->abs_path);
				print_rec(temp, flags);
			}
			if (crsr)
				crsr = crsr->next;
		}
		//if (junk)
		//	clean_one(junk);
	}
	return (0);
}
