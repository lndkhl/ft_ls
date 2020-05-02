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

#include "../includes/ft_ls.h"

void	print_title(t_ls *node, int *flags)
{
	int		i;
	int		j;
	char	*temp;
	char	*title;

	if (!(temp = ft_strrchr(node->abs_path, '/')))
		title = ft_strdup(node->abs_path);
	else
	{
		i = ft_strlen(node->abs_path);
		j = ft_strlen(temp);
		title = ft_strsub(node->abs_path, 0, i - j);
	}
	if (!(ft_strlen(title)))
	{
		free(title);
		title = ft_strdup("/");
	}
	ft_putstr(title);
	free(title);
	ft_putstr(":\n");
	if (*flags & 1)
		print_total(node);
}

void	print_total(t_ls *node)
{
	ft_putstr("total ");
	ft_putnbr(node->total);
	ft_putchar('\n');
}
