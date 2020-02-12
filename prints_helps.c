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

void	print_rec(t_ls *list, int type, int *flags)
{
	t_ls	*crsr;

	if (!list)
		return ;
	crsr = list;
	print_title(crsr, flags);
	if (*flags & 1)
		print_total(crsr);
	print_basic(sort(crsr, type), flags);
	while (crsr)
	{
		if (is_d(crsr->abs_path))
		{
			ft_putchar('\n');
			print_rec(init_list(crsr->abs_path, flags), type, flags);
		}
		crsr = crsr->next;
	}
	clean_reg(list);
}

int		print_title(t_ls *node, int *flags)
{
	int		i;
	int		j;
	char	*title;

	i = ft_strlen(node->abs_path);
	j = ft_strlen(ft_strrchr(node->abs_path, '/'));
	title = ft_strsub(node->abs_path, 0, i - j);
	ft_putstr(title);
	free(title);
	ft_putstr(":\n");
	if (*flags & 1)
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
