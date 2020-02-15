/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:11:25 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:27:40 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_lust	*add_dir(t_lust *node, t_lust *list)
{
	t_lust	*crsr;

	if (!(node))
		return (list);
	crsr = list;
	while (crsr->next)
		crsr = crsr->next;
	crsr->next = node;
	node->prev = crsr;
	return (list);
}

int		is_valid(char *av_i, int *flags)
{
	int	i;

	i = 0;
	while (av_i[++i] != '\0')
	{
		if (av_i[i] == 'l')
			*flags = *flags | 1;
		else if (av_i[i] == 'a')
			*flags = *flags | 2;
		else if (av_i[i] == 'r')
			*flags = *flags | 4;
		else if (av_i[i] == 'R')
			*flags = *flags | 8;
		else if (av_i[i] == 't')
			*flags = *flags | 16;
		else
			return (print_illegal(av_i[i]));
	}
	return (1);
}

int		print_nonexistant(t_cont *nonexistant)
{
	t_cont	*temp;

	if (nonexistant == NULL)
		return (0);
	temp = nonexistant;
	while (temp != NULL)
	{
		print_invalid(temp);
		temp = temp->next;
	}
	clean_cont(nonexistant);
	return (1);
}
