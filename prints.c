/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:23 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/03 17:24:24 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//prints the filename associated with a given node
int	print_node(ls *node, int *flags)
{
	if (!(node))
		return (-1);
	(*flags & 1) ? print_permissions(node) : ft_putendl((node)->name);
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
		if (i)
			ft_putchar('\n');
		type = (*flags & 16) ? 1 : 0;
		behemoth[i] = sort(behemoth[i], type);
		if (*flags & 1 && (!(*flags & 8)))
			print_titles(behemoth[i]);
		if (*flags & 8)
			print_rec(behemoth[i], type, flags);
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
	if (*flags & 4)
	{
		temp = seek_end(node);
		while (temp)
		{
			if ((*flags & 2) || (temp)->name[0] != '.')
				print_node(temp, flags);
			temp = temp->prev;
		}
	}
	else
	{
		while (temp)
		{
			if ((*flags & 2) || (temp)->name[0] != '.')
				print_node(temp, flags);
			temp = temp->next;
		}
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
		print_basic(sort(crsr, type), flags);
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
	ft_putstr("total ");
	ft_putnbr(node->total);
	ft_putchar('\n');
	return (1);
}
