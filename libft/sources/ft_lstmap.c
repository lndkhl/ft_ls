/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:10:09 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 12:48:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*next;
	t_list		*head;

	if (!(next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	head = next;
	lst = lst->next;
	while (lst)
	{
		if (!(next->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		next = next->next;
		lst = lst->next;
	}
	return (head);
}
