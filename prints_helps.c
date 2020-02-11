/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:10:18 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/10 07:10:23 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//prints recursively
t_ls	*print_rec(t_ls *list, int type, int *flags)
{
	t_ls	*temp;
	t_ls	*crsr;

	temp = NULL;
	if ((crsr = list))
	{
		temp = crsr;
		if (*flags & 1)
		{
			ft_putstr("total ");
			ft_putnbr(crsr->total);
			ft_putchar('\n');
		}
		print_basic(sort(crsr, type), flags);
		while (crsr)
		{
			if (is_dir(crsr) && ((*flags & 2) || crsr->name[0] != '.'))
			{
				ft_putchar('\n');
				ft_putstr(crsr->abs_path);
				ft_putstr(":\n");
				print_rec(init_list(crsr->abs_path, flags), type, flags);
			}
			crsr = crsr->next;
		}
		clean_reg(temp);
	}
	return (temp);
}

int	print_titles(t_ls *node)
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
