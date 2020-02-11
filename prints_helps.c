/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_helps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:10:18 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:41:44 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_ls	*print_rec(t_ls *list, int type, int *flags)
{
	t_ls	*crsr;

	if ((crsr = list))
	{
		ft_putstr(crsr->abs_path);
		ft_putstr(":\n");
		if (*flags & 1)
			print_total(crsr);
		print_basic(sort(crsr, type), flags);
		while (crsr)
		{
			if (is_dir(crsr) && ((*flags & 2) || crsr->name[0] != '.'))
			{
				ft_putchar('\n');
				print_rec(init_list(crsr->abs_path, flags), type, flags);
			}
			crsr = crsr->next;
		}
	}
	list = clean_reg(list);
	return (list);
}

int		print_titles(t_ls *node)
{
	if (!node)
		return (0);
	ft_putstr(node->abs_path);
	ft_putstr(":\n");
	print_total(node);
	return (1);
}

int		print_total(t_ls *node)
{
	ft_putstr("total ");
	ft_putnbr(node->total);
	ft_putchar('\n');
	return (1);
}