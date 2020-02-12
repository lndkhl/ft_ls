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

#include "tinker.h"

void	clean(t_lust *list)
{
	t_lust	*crsr;
	t_lust	*temp;

	if (!(crsr = list))
		return ;
	while (crsr)
	{
		if (crsr->next)
			temp = crsr->next;
		else
			temp = NULL;
		crsr->list = clean_reg(crsr->list);
		free(crsr->list);
		free(crsr);
		crsr = temp;
	}
}

t_ls	*clean_reg(t_ls *list)
{
	t_ls	*temp;
	t_ls	*crsr;

	temp = list;
	while (temp)
	{
		crsr = (temp->next) ? temp->next : NULL;
		free(temp->name);
		free(temp->abs_path);
		free(temp->link_path);
		free(temp);
		temp = crsr;
	}
	return (temp);
}

void	clean_cont(t_cont *cont)
{
	t_cont	*crsr;
	t_cont	*temp;

	if (!(crsr = cont))
		return ;
	while (crsr)
	{
		if (crsr->next)
			temp = crsr->next;
		else
			temp = NULL;
		free(crsr->name);
		free(crsr);
		crsr = temp;
	}
}
