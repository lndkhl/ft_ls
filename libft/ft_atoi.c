/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:51:34 by lnkambul          #+#    #+#             */
/*   Updated: 2019/06/19 14:55:22 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *s)
{
	int			n;
	long long	r;
	char		*p;

	n = 1;
	r = 0;
	p = (char *)s;
	p = ft_whitespace_skipper(p);
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			n = n * -1;
		p++;
	}
	while (ft_isdigit(*p))
	{
		r = (r * 10) + ((*p) - 48);
		p++;
	}
	return (r * n);
}
