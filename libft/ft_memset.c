/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:27:15 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/02 17:42:38 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			l;
	unsigned char	*a;

	a = (unsigned char *)b;
	l = 0;
	while (l < len)
		a[l++] = (unsigned char)c;
	return (b);
}
