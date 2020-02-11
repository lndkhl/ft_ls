/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_prints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:12:06 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/10 07:12:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

//prints that an invalid filename has been entered
int		print_invalid(t_cont *nonexistant)
{
	t_cont	*temp;

	if (!(nonexistant))
		return (0);
	temp = nonexistant;
	while (temp)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(nonexistant->name);
		ft_putendl(": No such file or directory");
		temp = temp->next;
	}
	return (1);
}

//prints that an illegal option has been chosen, terminates
int		print_illegal(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("'\n'usage ft_ls [l,r,a, R, t] [file ...]");
	return (0);
}
