/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:18:16 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 15:54:57 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa(int i)
{
	char				*r;
	unsigned int		c;
	long				a;

	c = 0;
	a = (long)i;
	a *= (a < 0) ? -1 : 1;
	while (a > 0)
	{
		a /= 10;
		c++;
	}
	if (!(r = (i <= 0) ? ft_strnew(++c) : ft_strnew(c)))
		return (NULL);
	r[0] = (i < 0) ? '-' : r[0];
	r = (i == 0) ? ft_strdup("0") : r;
	a = (long)i;
	a *= (a < 0) ? -1 : 1;
	while (a > 0)
	{
		r[--c] = (a % 10) + '0';
		a /= 10;
	}
	return (r);
}
