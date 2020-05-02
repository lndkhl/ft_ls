/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:52:20 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 12:50:06 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	*w;
	unsigned char	a;

	i = 0;
	w = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (w[i] == a)
			return (&w[i]);
		i++;
	}
	return (NULL);
}
