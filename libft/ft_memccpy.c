/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:13:33 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/10 17:32:13 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	e;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	e = (unsigned char)c;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while ((i < n) && (src || dst))
	{
		d[i] = s[i];
		if (s[i] == e)
			return (&d[++i]);
		i++;
	}
	return (NULL);
}
