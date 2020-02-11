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
int	print_node(t_ls *node, int *flags)
{
	if (!(node))
		return (-1);
	(*flags & 1) ? print_permissions(node) : ft_putendl((node)->name);
	return (1);
}

//prints the list via one of the print_node functions
int	print(t_lust *behemoth, int *flags)
{
	t_lust	*crsr;
	int		type;

	crsr = behemoth;
	while (crsr)
	{
		if (crsr->prev)
			ft_putchar('\n');
		type = (*flags & 16) ? 1 : 0;
		crsr->list = sort(crsr->list, type);
		if (*flags & 1 && (!(*flags & 8)))
			print_titles(crsr->list);
		if (*flags & 8)
			print_rec(crsr->list, type, flags);
		else 
			print_basic(crsr->list, flags);
		crsr = crsr->next;
	}
	return (0);
}

//prints each node according to the desired formatting
int	print_basic(t_ls *node, int *flags)
{
	t_ls	*temp;

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
