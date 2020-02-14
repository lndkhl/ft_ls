/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:23 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/14 08:55:17 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

int		print_node(t_ls *node, int *flags)
{
	if (!(node))
		return (-1);
	(*flags & 1) ? print_permissions(node) : ft_putendl((node)->name);
	return (1);
}

void	print(t_ls *list, int *flags)
{
	t_ls	*temp;
	t_ls	*crsr;

	if (!list)
		return ;
	if (list->type)
		print_title(list, flags);
	temp = (*flags & 16) ? sort(list, 1) : sort(list, 0);
	crsr = temp;
	print_basic(temp, flags);
	if (*flags & 8)
	{
		temp = (*flags & 4) ? seek_end(temp) : temp;
		while (temp)
		{
			if ((is_dir(temp)) && (temp->name[0] != '.' || (*flags & 2)))
			{
				ft_putchar('\n');
				print(init_list(temp->abs_path, flags), flags);
			}
			temp = (*flags & 4) ? temp->prev : temp->next;
		}
	}
	list = clean_reg(crsr);
}

void	print_basic(t_ls *node, int *flags)
{
	t_ls	*temp;

	temp = NULL;
	if (!(temp = node))
		return ;
	if (*flags & 4)
	{
		temp = seek_end(node);
		while (temp)
		{
			print_node(temp, flags);
			temp = temp->prev;
		}
	}
	else
	{
		while (temp)
		{
			print_node(temp, flags);
			temp = temp->next;
		}
	}
}
