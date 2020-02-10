/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:11:25 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/10 08:17:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_lust	*add_dir(t_lust *node, t_lust *list)
{
	t_lust	*crsr;

	if (!(node))
		return (list);
	if (!(list))
	{
		list = (t_lust *)malloc(sizeof(t_lust));
		list = node;
		return (list);
	}
	crsr = list;
	while (crsr->next)
		crsr = crsr->next;
	crsr->next = node;
	node->prev = crsr;
	return (list);
}
