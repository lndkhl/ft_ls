/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:48 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:24:14 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_lust	*clean(t_lust *list)
{
	t_lust	*crsr;
	t_lust	*temp;

	if (!list)
		return (list);
	crsr = list;
	while (crsr)
	{
		temp = (crsr->next) ? crsr->next : NULL;
		free(crsr);
		crsr = temp;
	}
	return (list);
}

t_ls	*clean_reg(t_ls *list)
{
	t_ls	*temp;
	t_ls	*crsr;

	if (!list)
		return (list);
	temp = list;
	while (temp)
	{
		crsr = (temp->next) ? temp->next : NULL;
		temp = clean_one(temp);
		temp = crsr;
	}
	return (list);
}

t_ls	*clean_one(t_ls *node)
{
	if (!node)
		return (node);
	free(node->name);
	free(node->abs_path);
	free(node->link_path);
	free(node);
	node = NULL;
	return (node);
}

t_cont	*clean_cont(t_cont *cont)
{
	t_cont	*crsr;
	t_cont	*temp;

	if (!cont)
		return (cont);
	crsr = cont;
	while (crsr)
	{
		temp = (crsr->next) ? crsr->next : NULL;
		free(crsr->name);
		free(crsr);
		crsr = temp;
	}
	return (cont);
}
