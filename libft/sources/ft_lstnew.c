/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:14:08 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 14:48:13 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*newlist;

	newlist = NULL;
	if (!(newlist = (void *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = ft_memcpy(ft_strnew(content_size), content,\
				content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
